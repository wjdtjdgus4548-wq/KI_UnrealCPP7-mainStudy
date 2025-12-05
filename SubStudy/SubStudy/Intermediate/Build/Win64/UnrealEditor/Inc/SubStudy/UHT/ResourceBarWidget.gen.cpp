// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/UI/ResourceBarWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeResourceBarWidget() {}

// Begin Cross Module References
SUBSTUDY_API UClass* Z_Construct_UClass_UResourceBarWidget();
SUBSTUDY_API UClass* Z_Construct_UClass_UResourceBarWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class UResourceBarWidget Function RefreshWidget
struct Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics
{
	struct ResourceBarWidget_eventRefreshWidget_Parms
	{
		float InCurrent;
		float InMax;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/ResourceBarWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InCurrent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::NewProp_InCurrent = { "InCurrent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ResourceBarWidget_eventRefreshWidget_Parms, InCurrent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::NewProp_InMax = { "InMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ResourceBarWidget_eventRefreshWidget_Parms, InMax), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::NewProp_InCurrent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::NewProp_InMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UResourceBarWidget, nullptr, "RefreshWidget", nullptr, nullptr, Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::ResourceBarWidget_eventRefreshWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::ResourceBarWidget_eventRefreshWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UResourceBarWidget_RefreshWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UResourceBarWidget_RefreshWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UResourceBarWidget::execRefreshWidget)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InCurrent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InMax);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshWidget(Z_Param_InCurrent,Z_Param_InMax);
	P_NATIVE_END;
}
// End Class UResourceBarWidget Function RefreshWidget

// Begin Class UResourceBarWidget
void UResourceBarWidget::StaticRegisterNativesUResourceBarWidget()
{
	UClass* Class = UResourceBarWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "RefreshWidget", &UResourceBarWidget::execRefreshWidget },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UResourceBarWidget);
UClass* Z_Construct_UClass_UResourceBarWidget_NoRegister()
{
	return UResourceBarWidget::StaticClass();
}
struct Z_Construct_UClass_UResourceBarWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "UI/ResourceBarWidget.h" },
		{ "ModuleRelativePath", "Public/UI/ResourceBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Resource" },
		{ "ModuleRelativePath", "Public/UI/ResourceBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Current_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Resource" },
		{ "ModuleRelativePath", "Public/UI/ResourceBarWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Max_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Resource" },
		{ "ModuleRelativePath", "Public/UI/ResourceBarWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Bar;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Current;
	static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Max;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UResourceBarWidget_RefreshWidget, "RefreshWidget" }, // 3699157951
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UResourceBarWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Bar = { "Bar", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UResourceBarWidget, Bar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bar_MetaData), NewProp_Bar_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Current = { "Current", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UResourceBarWidget, Current), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Current_MetaData), NewProp_Current_MetaData) };
const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Max = { "Max", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UResourceBarWidget, Max), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Max_MetaData), NewProp_Max_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UResourceBarWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Bar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Current,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UResourceBarWidget_Statics::NewProp_Max,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UResourceBarWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UResourceBarWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UResourceBarWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UResourceBarWidget_Statics::ClassParams = {
	&UResourceBarWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UResourceBarWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UResourceBarWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UResourceBarWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UResourceBarWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UResourceBarWidget()
{
	if (!Z_Registration_Info_UClass_UResourceBarWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UResourceBarWidget.OuterSingleton, Z_Construct_UClass_UResourceBarWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UResourceBarWidget.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<UResourceBarWidget>()
{
	return UResourceBarWidget::StaticClass();
}
UResourceBarWidget::UResourceBarWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UResourceBarWidget);
UResourceBarWidget::~UResourceBarWidget() {}
// End Class UResourceBarWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_ResourceBarWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UResourceBarWidget, UResourceBarWidget::StaticClass, TEXT("UResourceBarWidget"), &Z_Registration_Info_UClass_UResourceBarWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UResourceBarWidget), 2311334835U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_ResourceBarWidget_h_4055672621(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_ResourceBarWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_UI_ResourceBarWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
