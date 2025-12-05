// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/UI/MainHudWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainHudWidget() {}

// Begin Cross Module References
SUBSTUDY_API UClass* Z_Construct_UClass_UMainHudWidget();
SUBSTUDY_API UClass* Z_Construct_UClass_UMainHudWidget_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_UResourceBarWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class UMainHudWidget
void UMainHudWidget::StaticRegisterNativesUMainHudWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMainHudWidget);
UClass* Z_Construct_UClass_UMainHudWidget_NoRegister()
{
	return UMainHudWidget::StaticClass();
}
struct Z_Construct_UClass_UMainHudWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/MainHudWidget.h" },
		{ "ModuleRelativePath", "Public/UI/MainHudWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Resource" },
		{ "ModuleRelativePath", "Public/UI/MainHudWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaminaBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Resource" },
		{ "ModuleRelativePath", "Public/UI/MainHudWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_HealthBar;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_StaminaBar;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMainHudWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UMainHudWidget_Statics::NewProp_HealthBar = { "HealthBar", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMainHudWidget, HealthBar), Z_Construct_UClass_UResourceBarWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthBar_MetaData), NewProp_HealthBar_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UMainHudWidget_Statics::NewProp_StaminaBar = { "StaminaBar", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMainHudWidget, StaminaBar), Z_Construct_UClass_UResourceBarWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaminaBar_MetaData), NewProp_StaminaBar_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMainHudWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMainHudWidget_Statics::NewProp_HealthBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMainHudWidget_Statics::NewProp_StaminaBar,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMainHudWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMainHudWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMainHudWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMainHudWidget_Statics::ClassParams = {
	&UMainHudWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMainHudWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMainHudWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMainHudWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UMainHudWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMainHudWidget()
{
	if (!Z_Registration_Info_UClass_UMainHudWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMainHudWidget.OuterSingleton, Z_Construct_UClass_UMainHudWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMainHudWidget.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<UMainHudWidget>()
{
	return UMainHudWidget::StaticClass();
}
UMainHudWidget::UMainHudWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMainHudWidget);
UMainHudWidget::~UMainHudWidget() {}
// End Class UMainHudWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_MainHudWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMainHudWidget, UMainHudWidget::StaticClass, TEXT("UMainHudWidget"), &Z_Registration_Info_UClass_UMainHudWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMainHudWidget), 354919441U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_MainHudWidget_h_3981116373(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_MainHudWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_MainHudWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
