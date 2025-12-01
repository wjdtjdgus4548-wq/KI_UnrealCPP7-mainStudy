// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/Test/FloatingActor_Curve.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloatingActor_Curve() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_AFloatingActor();
SUBSTUDY_API UClass* Z_Construct_UClass_AFloatingActor_Curve();
SUBSTUDY_API UClass* Z_Construct_UClass_AFloatingActor_Curve_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class AFloatingActor_Curve
void AFloatingActor_Curve::StaticRegisterNativesAFloatingActor_Curve()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFloatingActor_Curve);
UClass* Z_Construct_UClass_AFloatingActor_Curve_NoRegister()
{
	return AFloatingActor_Curve::StaticClass();
}
struct Z_Construct_UClass_AFloatingActor_Curve_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Test/FloatingActor_Curve.h" },
		{ "ModuleRelativePath", "Public/Test/FloatingActor_Curve.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeightCurve_MetaData[] = {
		{ "Category", "FloatingActor_Curve" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xeb\x86\x92\xec\x9d\xb4 \xec\x9b\x80\xec\xa7\x81\xec\x9e\x84\xec\x9d\x84 \xea\xb2\xb0\xec\xa0\x95\xed\x95\xa0 \xec\xbb\xa4\xeb\xb8\x8c\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/FloatingActor_Curve.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x86\x92\xec\x9d\xb4 \xec\x9b\x80\xec\xa7\x81\xec\x9e\x84\xec\x9d\x84 \xea\xb2\xb0\xec\xa0\x95\xed\x95\xa0 \xec\xbb\xa4\xeb\xb8\x8c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[] = {
		{ "Category", "FloatingActor_Curve" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\xbb\xa4\xeb\xb8\x8c \xed\x95\x9c\xec\xa3\xbc\xea\xb8\xb0 \xeb\x8f\x99\xec\x95\x88\xec\x9d\x98 \xec\x8b\x9c\xea\xb0\x84\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/FloatingActor_Curve.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xbb\xa4\xeb\xb8\x8c \xed\x95\x9c\xec\xa3\xbc\xea\xb8\xb0 \xeb\x8f\x99\xec\x95\x88\xec\x9d\x98 \xec\x8b\x9c\xea\xb0\x84" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeightCurve;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Duration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFloatingActor_Curve>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingActor_Curve_Statics::NewProp_HeightCurve = { "HeightCurve", nullptr, (EPropertyFlags)0x0114000000000015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor_Curve, HeightCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeightCurve_MetaData), NewProp_HeightCurve_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingActor_Curve_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor_Curve, Duration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Duration_MetaData), NewProp_Duration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFloatingActor_Curve_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Curve_Statics::NewProp_HeightCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Curve_Statics::NewProp_Duration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Curve_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFloatingActor_Curve_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AFloatingActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Curve_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFloatingActor_Curve_Statics::ClassParams = {
	&AFloatingActor_Curve::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFloatingActor_Curve_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Curve_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Curve_Statics::Class_MetaDataParams), Z_Construct_UClass_AFloatingActor_Curve_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFloatingActor_Curve()
{
	if (!Z_Registration_Info_UClass_AFloatingActor_Curve.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFloatingActor_Curve.OuterSingleton, Z_Construct_UClass_AFloatingActor_Curve_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFloatingActor_Curve.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<AFloatingActor_Curve>()
{
	return AFloatingActor_Curve::StaticClass();
}
AFloatingActor_Curve::AFloatingActor_Curve() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFloatingActor_Curve);
AFloatingActor_Curve::~AFloatingActor_Curve() {}
// End Class AFloatingActor_Curve

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_Curve_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFloatingActor_Curve, AFloatingActor_Curve::StaticClass, TEXT("AFloatingActor_Curve"), &Z_Registration_Info_UClass_AFloatingActor_Curve, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFloatingActor_Curve), 1275563151U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_Curve_h_3994142543(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_Curve_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_Curve_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
