// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/Test/FloatingActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFloatingActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SUBSTUDY_API UClass* Z_Construct_UClass_AFloatingActor();
SUBSTUDY_API UClass* Z_Construct_UClass_AFloatingActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class AFloatingActor
void AFloatingActor::StaticRegisterNativesAFloatingActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFloatingActor);
UClass* Z_Construct_UClass_AFloatingActor_NoRegister()
{
	return AFloatingActor::StaticClass();
}
struct Z_Construct_UClass_AFloatingActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Test/FloatingActor.h" },
		{ "ModuleRelativePath", "Public/Test/FloatingActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[] = {
		{ "Category", "FloatingActor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\x9d\xb4\xea\xb1\xb4 \xeb\x94\xb1 \xeb\xb3\xb4\xeb\xa9\xb4 \xec\x95\x8c\xec\xa7\x80?\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/FloatingActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\xb4\xea\xb1\xb4 \xeb\x94\xb1 \xeb\xb3\xb4\xeb\xa9\xb4 \xec\x95\x8c\xec\xa7\x80?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpinSpeed_MetaData[] = {
		{ "Category", "FloatingActor" },
		{ "ModuleRelativePath", "Public/Test/FloatingActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveHeight_MetaData[] = {
		{ "Category", "FloatingActor" },
		{ "ModuleRelativePath", "Public/Test/FloatingActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodyMesh_MetaData[] = {
		{ "Category", "FloatingActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Test/FloatingActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpinSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveHeight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BodyMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFloatingActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, Speed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Speed_MetaData), NewProp_Speed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_SpinSpeed = { "SpinSpeed", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, SpinSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpinSpeed_MetaData), NewProp_SpinSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_MoveHeight = { "MoveHeight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, MoveHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveHeight_MetaData), NewProp_MoveHeight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFloatingActor_Statics::NewProp_BodyMesh = { "BodyMesh", nullptr, (EPropertyFlags)0x01240800000a0009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFloatingActor, BodyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodyMesh_MetaData), NewProp_BodyMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFloatingActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_Speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_SpinSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_MoveHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFloatingActor_Statics::NewProp_BodyMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFloatingActor_Statics::ClassParams = {
	&AFloatingActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AFloatingActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AFloatingActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFloatingActor()
{
	if (!Z_Registration_Info_UClass_AFloatingActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFloatingActor.OuterSingleton, Z_Construct_UClass_AFloatingActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFloatingActor.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<AFloatingActor>()
{
	return AFloatingActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFloatingActor);
AFloatingActor::~AFloatingActor() {}
// End Class AFloatingActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFloatingActor, AFloatingActor::StaticClass, TEXT("AFloatingActor"), &Z_Registration_Info_UClass_AFloatingActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFloatingActor), 3448424359U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_h_1466776485(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_FloatingActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
