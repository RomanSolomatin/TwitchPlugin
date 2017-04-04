// Fill out your copyright notice in the Description page of Project Settings.

#include "TwitchPlugin.h"
#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Engine/World.h"
#include <string>

#include "TwitchComponent.h"


#define SOCKET_NAME "TwitchSocket"
#define IRC_ADDRESS "irc.twitch.tv"
#define IRC_PORT 6667

UTwitchComponent::UTwitchComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


// Sets default values for this component's properties
UTwitchComponent::UTwitchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTwitchComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Twitch Component: BeginPlay"));
	// ...
	
}

void UTwitchComponent::BeginDestroy()
{
	Super::BeginDestroy();
}


// Called every frame
void UTwitchComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTwitchComponent::recieveMessage()
{
	UE_LOG(LogTemp, Log, TEXT("Twitch IRC: Receive Message"));
	TArray<uint8> ReceivedData;
	uint32 Size;
	bool Received = false;
	ESocketConnectionState SocketState = listenerSocket->GetConnectionState();
	if (SocketState == ESocketConnectionState::SCS_NotConnected) {
		receiveMessages = false;
		ServerDisconnected.Broadcast();
	}
	// Wait to receive a message
	while (listenerSocket->HasPendingData(Size))
	{
		Received = true;
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));

		int32 Read = 0;
		listenerSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
	}

	// Check if message received
	if (Received)
	{
		// Read the message and parse it
		const std::string cstr(reinterpret_cast<const char*>(ReceivedData.GetData()), ReceivedData.Num());
		FString fs(cstr.c_str());
		UE_LOG(LogTemp, Log, TEXT("Twitch IRC Received Data: %s"), *fs);
		//UE_LOG(LogTemp, Log, tmp);
		parseMessage(fs);
	}
}

void UTwitchComponent::parseMessage(FString message)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch IRC: Parsing Message"));
	TArray<FString> lines;
	message.ParseIntoArrayLines(lines);
	for (FString fs : lines)
	{
		TArray<FString> parts;
		fs.ParseIntoArray(parts, TEXT(":"));
		TArray<FString> meta;
		parts[0].ParseIntoArrayWS(meta);
		if (parts.Num() >= 2)
		{
			if (meta[0] == TEXT("PING"))
			{
				sendMessage(TEXT("PONG :tmi.twitch.tv"));
			}
			else if (meta.Num() == 3 && meta[1] == TEXT("PRIVMSG"))
			{
				FString msg = parts[1];
				if (parts.Num() > 2)
				{
					for (int i = 2; i < parts.Num(); i++)
					{
						msg += TEXT(":") + parts[i];
					}
				}
				FString user;
				FString tmp;
				meta[0].Split(TEXT("!"), &user, &tmp);

				// Callback when message received
				ReceivedMessage.Broadcast(TEXT("#") + Username, user, msg);
				continue;
			}
			else if (meta.Num() >= 3 && meta[1] == TEXT("PART")) {
				TArray<FString> tmp;
				message.ParseIntoArray(tmp, TEXT("@"));
				TArray<FString> tmpp;
				tmp[0].ParseIntoArray(tmpp, TEXT("!"));
				FString name = tmpp[1];
				FString chan = meta[2];
				UserLeft.Broadcast(chan, name);
			}
			else if (meta.Num() >= 3 && meta[1] == TEXT("JOIN")) {
				TArray<FString> tmp;
				message.ParseIntoArray(tmp, TEXT("@"));
				TArray<FString> tmpp;
				tmp[0].ParseIntoArray(tmpp, TEXT("!"));
				FString name = tmpp[1];
				FString chan = meta[2];
				UserJoined.Broadcast(chan, name);
			}
		}
	}
}

void UTwitchComponent::requestMembership()
{
	//Request Information to See NAMES, JOIN, PART, or MODE ~ https://github.com/justintv/Twitch-API/blob/master/IRC.md#membership
	sendMessage(TEXT("CAP REQ :twitch.tv/membership"));
}

void UTwitchComponent::requestCommands()
{
	//Enables custom raw commands ~ https://github.com/justintv/Twitch-API/blob/master/IRC.md#membership
	sendMessage(TEXT("CAP REQ :twitch.tv/commands"));
}

bool UTwitchComponent::sendMessage(FString message)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch IRC: Sending Message: %s"), *message);
	FString serialized = message + TEXT("\r\n");
	TCHAR *serializedChar = serialized.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;

	return listenerSocket->Send((uint8*)TCHAR_TO_UTF8(serializedChar), size, sent);
}

void UTwitchComponent::sendChannelMessage(FString message)
{
	sendMessage(TEXT("PRIVMSG #") + Username + TEXT(" :") + message);
}

void UTwitchComponent::TwitchConnect()
{
	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Start"));
	/*
	// Resolve Twitch hostname
	auto resolveInfo = ISocketSubsystem::Get()->GetHostByName(IRC_ADDRESS);
	while (!resolveInfo->IsComplete());

	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Resolve Complete"));
	
	// Check host result
	if (resolveInfo->GetErrorCode() != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Twitch IRC: Couldn't resolve hostname."));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Got Host Result"));
	// Get host IP
	const FInternetAddr* addr = &resolveInfo->GetResolvedAddress();
	uint32 OutIP = 0;
	addr->GetIp(OutIP);
	int32 port = IRC_PORT;

	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Get our Hosts IP"));

	// Configure and create socket
	TSharedRef<FInternetAddr> iaddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	iaddr->SetIp(OutIP);
	iaddr->SetPort(IRC_PORT);
	listenerSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT(SOCKET_NAME), false);

	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Configured & Started our Socket"));

	// Try socket connection
	bool connected = listenerSocket->Connect(*iaddr);
	if (connected) {
		UE_LOG(LogTemp, Warning, TEXT("Twitch Component: Connected!"));
		ServerConnected.Broadcast();
		receiveMessages = true;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, Me, &UTwitchComponent::recieveMessage, 0.01, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Twitch Component: Failed to connect."));
		ServerDisconnected.Broadcast();
		if (listenerSocket)
			listenerSocket->Close();
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Connect Tried our Socket and Connected."));

	// Send Twitch OAuth Token
	sendMessage(TEXT("PASS ") + oAuth);

	// Set Nick of User
	sendMessage(TEXT("NICK ") + Username);

	sendMessage(TEXT("JOIN #") + Username);

	//Request Membership Permissions
	requestMembership();
	//Request Command Permissions
	requestCommands();
	*/
}

void UTwitchComponent::TwitchDisconnect()
{
	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Disconnect"));
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
	receiveMessages = false;
	listenerSocket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(listenerSocket);
	ServerDisconnected.Broadcast();

}

void UTwitchComponent::TwitchMessageChannel(const FString & Message)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch Component: Message Channel"));
	sendChannelMessage(FString(Message));
}
