// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"

#include "Runtime/Networking/Public/Networking.h"
#include "Runtime/Sockets/Public/Sockets.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"

#include "TwitchComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTwitchReceivedMessage, FString, Channel, FString, User, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwitchUserLeft, FString, Channel, FString, Name);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTwitchUserJoin, FString, Channel, FString, Name);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTwitchServerConnected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTwitchServerDisconnected);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWITCHPLUGIN_API UTwitchComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "Received Message from Twitch", Keywords = "Twitch Received Message"), Category = "Twitch|Events")
		FTwitchReceivedMessage ReceivedMessage;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "User Left Twitch Channel", Keywords = "Twitch User Left Channel"), Category = "Twitch|Events")
		FTwitchUserLeft UserLeft;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "User Joined Twitch Channel", Keywords = "Twitch User Joined Channel"), Category = "Twitch|Events")
		FTwitchUserJoin UserJoined;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "Connected to Twitch IRC Server", Keywords = "Twitch Server Connected"), Category = "Twitch|Events")
		FTwitchServerConnected ServerConnected;

	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "Disconnected from Twitch IRC Server", Keywords = "Twitch Server Disconnected"), Category = "Twitch|Events")
		FTwitchServerDisconnected ServerDisconnected;


public:	
	// Sets default values for this component's properties
	UTwitchComponent();

	UPROPERTY(EditAnywhere)
		FString Username;
	UPROPERTY(EditAnywhere)
		FString oAuth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	FSocket* listenerSocket;
	FTimerHandle timerHandle;
	bool receiveMessages = true;
	UTwitchComponent* Me = this;

	void recieveMessage();
	void parseMessage(FString message);
	void requestMembership();
	void requestCommands();
	bool sendMessage(FString message);
	void sendChannelMessage(FString message);

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect to Twitch", Keywords = "Twitch Disconnect"), Category = "Twitch|Functions")
		void TwitchConnect();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Disconnect From Twitch", Keywords = "Twitch Disconnect"), Category = "Twitch|Functions")
		void TwitchDisconnect();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Send Message to the Channel on Twitch", Keywords = "Twitch Send Message"), Category = "Twitch|Functions")
		void TwitchMessageChannel(const FString& Message);
	
};
