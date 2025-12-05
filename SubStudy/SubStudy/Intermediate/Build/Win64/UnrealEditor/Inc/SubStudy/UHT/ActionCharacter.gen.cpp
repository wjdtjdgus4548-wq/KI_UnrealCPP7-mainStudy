// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/Player/ActionCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_AActionCharacter();
SUBSTUDY_API UClass* Z_Construct_UClass_AActionCharacter_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_UResourceComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class AActionCharacter Function SetWalkMode
struct Z_Construct_UFunction_AActionCharacter_SetWalkMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xea\xb1\xb7\xea\xb8\xb0\xeb\xaa\xa8\xeb\x93\x9c \xec\x84\xa4\xec\xa0\x95(\xeb\x8b\xa4\xec\x9d\xb4\xeb\x82\x98\xeb\xaf\xb9 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xeb\x96\x94\xec\x8b\x9c \xec\xa0\x80\xea\xb1\xb0 \xec\x9c\xa0\xed\x8e\x91\xec\x85\x98\xec\x9d\xb8\xea\xb0\x80 \xeb\xad\x94\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xeb\x91\xa0\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb1\xb7\xea\xb8\xb0\xeb\xaa\xa8\xeb\x93\x9c \xec\x84\xa4\xec\xa0\x95(\xeb\x8b\xa4\xec\x9d\xb4\xeb\x82\x98\xeb\xaf\xb9 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8 \xeb\x96\x94\xec\x8b\x9c \xec\xa0\x80\xea\xb1\xb0 \xec\x9c\xa0\xed\x8e\x91\xec\x85\x98\xec\x9d\xb8\xea\xb0\x80 \xeb\xad\x94\xea\xb0\x80 \xeb\xb6\x99\xec\x96\xb4\xeb\x91\xa0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActionCharacter_SetWalkMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActionCharacter, nullptr, "SetWalkMode", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AActionCharacter_SetWalkMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_AActionCharacter_SetWalkMode_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AActionCharacter_SetWalkMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActionCharacter_SetWalkMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AActionCharacter::execSetWalkMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWalkMode();
	P_NATIVE_END;
}
// End Class AActionCharacter Function SetWalkMode

// Begin Class AActionCharacter
void AActionCharacter::StaticRegisterNativesAActionCharacter()
{
	UClass* Class = AActionCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetWalkMode", &AActionCharacter::execSetWalkMode },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AActionCharacter);
UClass* Z_Construct_UClass_AActionCharacter_NoRegister()
{
	return AActionCharacter::StaticClass();
}
struct Z_Construct_UClass_AActionCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/ActionCharacter.h" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "Player|Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCamera_MetaData[] = {
		{ "Category", "Player|Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Resource_MetaData[] = {
		{ "Category", "Player|Resource" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Move_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Sprint_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Roll_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintSpeed_MetaData[] = {
		{ "Category", "Palyer|Movemnt" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "Player|Movement" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RollMontage_MetaData[] = {
		{ "Category", "Animation|Montage" },
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSprint_MetaData[] = {
		{ "Category", "Player|State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xeb\x9c\x80?\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x9c\x80?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SprintStaminaCost_MetaData[] = {
		{ "Category", "Player|Resource" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xb4\x88\xeb\x8b\xb9 \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xec\x8a\xa4\xed\x85\x8c\xeb\xaf\xb8\xeb\x82\x98\xec\x82\xac\xec\x9a\xa9\xeb\x9f\x89\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xb4\x88\xeb\x8b\xb9 \xeb\x8b\xac\xeb\xa6\xac\xea\xb8\xb0 \xec\x8a\xa4\xed\x85\x8c\xeb\xaf\xb8\xeb\x82\x98\xec\x82\xac\xec\x9a\xa9\xeb\x9f\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RollStaminaCost_MetaData[] = {
		{ "Category", "Player|Resource" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xed\x9a\x8c\xeb\x8b\xb9 \xea\xb5\xac\xeb\xa5\xb4\xea\xb8\xb0 \xec\x8a\xa4\xed\x85\x8c\xeb\xaf\xb8\xeb\x82\x98\xec\x82\xac\xec\x9a\xa9\xeb\x9f\x89\n" },
#endif
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x9a\x8c\xeb\x8b\xb9 \xea\xb5\xac\xeb\xa5\xb4\xea\xb8\xb0 \xec\x8a\xa4\xed\x85\x8c\xeb\xaf\xb8\xeb\x82\x98\xec\x82\xac\xec\x9a\xa9\xeb\x9f\x89" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Player/ActionCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCamera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Resource;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Move;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Sprint;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Roll;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RollMontage;
	static void NewProp_bIsSprint_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSprint;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SprintStaminaCost;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RollStaminaCost;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_AnimInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AActionCharacter_SetWalkMode, "SetWalkMode" }, // 959042379
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActionCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_PlayerCamera = { "PlayerCamera", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, PlayerCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCamera_MetaData), NewProp_PlayerCamera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_Resource = { "Resource", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, Resource), Z_Construct_UClass_UResourceComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Resource_MetaData), NewProp_Resource_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Move = { "IA_Move", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, IA_Move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Move_MetaData), NewProp_IA_Move_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Sprint = { "IA_Sprint", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, IA_Sprint), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Sprint_MetaData), NewProp_IA_Sprint_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Roll = { "IA_Roll", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, IA_Roll), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Roll_MetaData), NewProp_IA_Roll_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_SprintSpeed = { "SprintSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, SprintSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintSpeed_MetaData), NewProp_SprintSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, WalkSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WalkSpeed_MetaData), NewProp_WalkSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_RollMontage = { "RollMontage", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, RollMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RollMontage_MetaData), NewProp_RollMontage_MetaData) };
void Z_Construct_UClass_AActionCharacter_Statics::NewProp_bIsSprint_SetBit(void* Obj)
{
	((AActionCharacter*)Obj)->bIsSprint = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_bIsSprint = { "bIsSprint", nullptr, (EPropertyFlags)0x0020080000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AActionCharacter), &Z_Construct_UClass_AActionCharacter_Statics::NewProp_bIsSprint_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSprint_MetaData), NewProp_bIsSprint_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_SprintStaminaCost = { "SprintStaminaCost", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, SprintStaminaCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SprintStaminaCost_MetaData), NewProp_SprintStaminaCost_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_RollStaminaCost = { "RollStaminaCost", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, RollStaminaCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RollStaminaCost_MetaData), NewProp_RollStaminaCost_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_AActionCharacter_Statics::NewProp_AnimInstance = { "AnimInstance", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionCharacter, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnimInstance_MetaData), NewProp_AnimInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActionCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_PlayerCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_Resource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Move,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Sprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_IA_Roll,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_SprintSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_WalkSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_RollMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_bIsSprint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_SprintStaminaCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_RollStaminaCost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionCharacter_Statics::NewProp_AnimInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActionCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AActionCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActionCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActionCharacter_Statics::ClassParams = {
	&AActionCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AActionCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AActionCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActionCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AActionCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AActionCharacter()
{
	if (!Z_Registration_Info_UClass_AActionCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActionCharacter.OuterSingleton, Z_Construct_UClass_AActionCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActionCharacter.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<AActionCharacter>()
{
	return AActionCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AActionCharacter);
AActionCharacter::~AActionCharacter() {}
// End Class AActionCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActionCharacter, AActionCharacter::StaticClass, TEXT("AActionCharacter"), &Z_Registration_Info_UClass_AActionCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActionCharacter), 2019891617U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_2740787401(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
