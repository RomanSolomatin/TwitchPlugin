// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TWITCHPLUGIN_TwitchComponent_generated_h
#error "TwitchComponent.generated.h already included, missing '#pragma once' in TwitchComponent.h"
#endif
#define TWITCHPLUGIN_TwitchComponent_generated_h

#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_17_DELEGATE \
static inline void FTwitchServerDisconnected_DelegateWrapper(const FMulticastScriptDelegate& TwitchServerDisconnected) \
{ \
	TwitchServerDisconnected.ProcessMulticastDelegate<UObject>(NULL); \
}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_16_DELEGATE \
static inline void FTwitchServerConnected_DelegateWrapper(const FMulticastScriptDelegate& TwitchServerConnected) \
{ \
	TwitchServerConnected.ProcessMulticastDelegate<UObject>(NULL); \
}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_15_DELEGATE \
struct _Script_TwitchPlugin_eventTwitchUserJoin_Parms \
{ \
	FString Channel; \
	FString Name; \
}; \
static inline void FTwitchUserJoin_DelegateWrapper(const FMulticastScriptDelegate& TwitchUserJoin, const FString& Channel, const FString& Name) \
{ \
	_Script_TwitchPlugin_eventTwitchUserJoin_Parms Parms; \
	Parms.Channel=Channel; \
	Parms.Name=Name; \
	TwitchUserJoin.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_14_DELEGATE \
struct _Script_TwitchPlugin_eventTwitchUserLeft_Parms \
{ \
	FString Channel; \
	FString Name; \
}; \
static inline void FTwitchUserLeft_DelegateWrapper(const FMulticastScriptDelegate& TwitchUserLeft, const FString& Channel, const FString& Name) \
{ \
	_Script_TwitchPlugin_eventTwitchUserLeft_Parms Parms; \
	Parms.Channel=Channel; \
	Parms.Name=Name; \
	TwitchUserLeft.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_13_DELEGATE \
struct _Script_TwitchPlugin_eventTwitchReceivedMessage_Parms \
{ \
	FString Channel; \
	FString User; \
	FString Message; \
}; \
static inline void FTwitchReceivedMessage_DelegateWrapper(const FMulticastScriptDelegate& TwitchReceivedMessage, const FString& Channel, const FString& User, const FString& Message) \
{ \
	_Script_TwitchPlugin_eventTwitchReceivedMessage_Parms Parms; \
	Parms.Channel=Channel; \
	Parms.User=User; \
	Parms.Message=Message; \
	TwitchReceivedMessage.ProcessMulticastDelegate<UObject>(&Parms); \
}




#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTwitchMessageChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchMessageChannel(Z_Param_Message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTwitchDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchDisconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTwitchConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchConnect(); \
		P_NATIVE_END; \
	}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTwitchMessageChannel) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchMessageChannel(Z_Param_Message); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTwitchDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchDisconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTwitchConnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TwitchConnect(); \
		P_NATIVE_END; \
	}


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUTwitchComponent(); \
	friend TWITCHPLUGIN_API class UClass* Z_Construct_UClass_UTwitchComponent(); \
	public: \
	DECLARE_CLASS(UTwitchComponent, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TwitchPlugin"), NO_API) \
	DECLARE_SERIALIZER(UTwitchComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_INCLASS \
	private: \
	static void StaticRegisterNativesUTwitchComponent(); \
	friend TWITCHPLUGIN_API class UClass* Z_Construct_UClass_UTwitchComponent(); \
	public: \
	DECLARE_CLASS(UTwitchComponent, USceneComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TwitchPlugin"), NO_API) \
	DECLARE_SERIALIZER(UTwitchComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTwitchComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTwitchComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTwitchComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTwitchComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTwitchComponent(UTwitchComponent&&); \
	NO_API UTwitchComponent(const UTwitchComponent&); \
public:


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTwitchComponent(UTwitchComponent&&); \
	NO_API UTwitchComponent(const UTwitchComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTwitchComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTwitchComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTwitchComponent)


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_PRIVATE_PROPERTY_OFFSET
#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_19_PROLOG
#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_RPC_WRAPPERS \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_INCLASS \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_INCLASS_NO_PURE_DECLS \
	PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h_22_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class TwitchComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PlayerVsTwitch_Plugins_TwitchPlugin_Source_TwitchPlugin_Public_TwitchComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS