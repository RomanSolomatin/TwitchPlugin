// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UObjectBaseUtility.h"
#include "UObject/Object.h"

#include "TwitchBlueprintFunctionLibrary.generated.h"
/*
*
*/

USTRUCT(BlueprintType)
struct FHTTPData {

	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Utilities|HTTP|Struct")
		FString name;
		UPROPERTY(EditAnywhere, BlueprintReadWRite, Category = "Utilities|HTTP|Struct")
		FString data;

};

/*
 * 
 */
UCLASS()
class TWITCHPLUGIN_API UTwitchBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()



private:


public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Twitch Followers", Keywords = "Twitch Get Followers"), Category = "Twitch|Functions")
		static void GetTwitchFollowers(const FString& Username, int32& Followers);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Twitch Subscribers", Keywords = "Twitch Get Subscribers"), Category = "Twitch|Functions")
		static void GetTwitchSubscribers(const FString& Username, int32& Subscribers);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Twitch Views", Keywords = "Twitch Get Views"), Category = "Twitch|Functions")
		static void GetTwitchViews(const FString& Username, int32& Views);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Twitch Viewers", Keywords = "Twitch Get Viewers"), Category = "Twitch|Functions")
		static void GetTwitchViewers(const FString& Username, int32& Viewers);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Twitch Chatters", Keywords = "Twitch Get Chatters"), Category = "Twitch|Functions")
		static void GetTwitchChatters(const FString& Username, int32& Viewers);
};
