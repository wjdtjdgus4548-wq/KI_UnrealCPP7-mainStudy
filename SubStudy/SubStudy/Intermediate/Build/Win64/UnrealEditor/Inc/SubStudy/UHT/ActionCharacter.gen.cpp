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
SUBSTUDY_API UClass* Z_Construct_UClass_AActionCharacter();
SUBSTUDY_API UClass* Z_Construct_UClass_AActionCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class AActionCharacter
void AActionCharacter::StaticRegisterNativesAActionCharacter()
{
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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActionCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_AActionCharacter, AActionCharacter::StaticClass, TEXT("AActionCharacter"), &Z_Registration_Info_UClass_AActionCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActionCharacter), 3263505884U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_1082872444(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Player_ActionCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
