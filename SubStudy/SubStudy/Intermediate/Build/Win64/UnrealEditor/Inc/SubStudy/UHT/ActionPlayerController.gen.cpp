// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/Player/ActionPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActionPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_AActionPlayerController();
SUBSTUDY_API UClass* Z_Construct_UClass_AActionPlayerController_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class AActionPlayerController
void AActionPlayerController::StaticRegisterNativesAActionPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AActionPlayerController);
UClass* Z_Construct_UClass_AActionPlayerController_NoRegister()
{
	return AActionPlayerController::StaticClass();
}
struct Z_Construct_UClass_AActionPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Player/ActionPlayerController.h" },
		{ "ModuleRelativePath", "Public/Player/ActionPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/ActionPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Look_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Player/ActionPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewPitchMin_MetaData[] = {
		{ "Category", "Camera|Pitch" },
		{ "ModuleRelativePath", "Public/Player/ActionPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewPitchMax_MetaData[] = {
		{ "Category", "Camera|Pitch" },
		{ "ModuleRelativePath", "Public/Player/ActionPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Look;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ViewPitchMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ViewPitchMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActionPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionPlayerController_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionPlayerController, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultMappingContext_MetaData), NewProp_DefaultMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActionPlayerController_Statics::NewProp_IA_Look = { "IA_Look", nullptr, (EPropertyFlags)0x0124080000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionPlayerController, IA_Look), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Look_MetaData), NewProp_IA_Look_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionPlayerController_Statics::NewProp_ViewPitchMin = { "ViewPitchMin", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionPlayerController, ViewPitchMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewPitchMin_MetaData), NewProp_ViewPitchMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActionPlayerController_Statics::NewProp_ViewPitchMax = { "ViewPitchMax", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActionPlayerController, ViewPitchMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewPitchMax_MetaData), NewProp_ViewPitchMax_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActionPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionPlayerController_Statics::NewProp_DefaultMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionPlayerController_Statics::NewProp_IA_Look,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionPlayerController_Statics::NewProp_ViewPitchMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActionPlayerController_Statics::NewProp_ViewPitchMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActionPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AActionPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActionPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActionPlayerController_Statics::ClassParams = {
	&AActionPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AActionPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AActionPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActionPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AActionPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AActionPlayerController()
{
	if (!Z_Registration_Info_UClass_AActionPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActionPlayerController.OuterSingleton, Z_Construct_UClass_AActionPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActionPlayerController.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<AActionPlayerController>()
{
	return AActionPlayerController::StaticClass();
}
AActionPlayerController::AActionPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AActionPlayerController);
AActionPlayerController::~AActionPlayerController() {}
// End Class AActionPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActionPlayerController, AActionPlayerController::StaticClass, TEXT("AActionPlayerController"), &Z_Registration_Info_UClass_AActionPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActionPlayerController), 4142852923U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionPlayerController_h_1450553732(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
