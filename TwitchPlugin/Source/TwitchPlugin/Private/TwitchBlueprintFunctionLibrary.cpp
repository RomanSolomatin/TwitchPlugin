// Fill out your copyright notice in the Description page of Project Settings.

#include "TwitchPlugin.h"


#include "TwitchBlueprintFunctionLibrary.h"

UTwitchBlueprintFunctionLibrary::UTwitchBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void UTwitchBlueprintFunctionLibrary::GetTwitchFollowers(const FString & Username, int32 & Followers)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch BPFL: Get Followers"));
}

void UTwitchBlueprintFunctionLibrary::GetTwitchSubscribers(const FString & Username, int32 & Subscribers)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch BPFL: Get Subscribers"));
}

void UTwitchBlueprintFunctionLibrary::GetTwitchViews(const FString & Username, int32 & Views)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch BPFL: Get Views"));
}

void UTwitchBlueprintFunctionLibrary::GetTwitchViewers(const FString & Username, int32 & Viewers)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch BPFL: Get Viewers"));
}

void UTwitchBlueprintFunctionLibrary::GetTwitchChatters(const FString & Username, int32 & Viewers)
{
	UE_LOG(LogTemp, Log, TEXT("Twitch BPFL: Get Chatters"));
}


