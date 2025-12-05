// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSubStudy_init() {}
	SUBSTUDY_API UFunction* Z_Construct_UDelegateFunction_SubStudy_OnDie__DelegateSignature();
	SUBSTUDY_API UFunction* Z_Construct_UDelegateFunction_SubStudy_OnStaminaChanged__DelegateSignature();
	SUBSTUDY_API UFunction* Z_Construct_UDelegateFunction_SubStudy_OnStaminaEmpty__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SubStudy;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SubStudy()
	{
		if (!Z_Registration_Info_UPackage__Script_SubStudy.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SubStudy_OnDie__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SubStudy_OnStaminaChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SubStudy_OnStaminaEmpty__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SubStudy",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x10B1DA3B,
				0x30BB7807,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SubStudy.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SubStudy.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SubStudy(Z_Construct_UPackage__Script_SubStudy, TEXT("/Script/SubStudy"), Z_Registration_Info_UPackage__Script_SubStudy, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x10B1DA3B, 0x30BB7807));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
