// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/ResourceComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SUBSTUDY_ResourceComponent_generated_h
#error "ResourceComponent.generated.h already included, missing '#pragma once' in ResourceComponent.h"
#endif
#define SUBSTUDY_ResourceComponent_generated_h

#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_31_DELEGATE \
SUBSTUDY_API void FOnStaminaEmpty_DelegateWrapper(const FMulticastScriptDelegate& OnStaminaEmpty);


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_34_DELEGATE \
SUBSTUDY_API void FOnDie_DelegateWrapper(const FMulticastScriptDelegate& OnDie);


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_36_DELEGATE \
SUBSTUDY_API void FOnStaminaChanged_DelegateWrapper(const FMulticastScriptDelegate& OnStaminaChanged, float Current, float Max);


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAddHealth); \
	DECLARE_FUNCTION(execHasEnoughStamina); \
	DECLARE_FUNCTION(execAddStamina);


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUResourceComponent(); \
	friend struct Z_Construct_UClass_UResourceComponent_Statics; \
public: \
	DECLARE_CLASS(UResourceComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SubStudy"), NO_API) \
	DECLARE_SERIALIZER(UResourceComponent)


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UResourceComponent(UResourceComponent&&); \
	UResourceComponent(const UResourceComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UResourceComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UResourceComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UResourceComponent) \
	NO_API virtual ~UResourceComponent();


#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_39_PROLOG
#define FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_INCLASS_NO_PURE_DECLS \
	FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUBSTUDY_API UClass* StaticClass<class UResourceComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ResourceComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
