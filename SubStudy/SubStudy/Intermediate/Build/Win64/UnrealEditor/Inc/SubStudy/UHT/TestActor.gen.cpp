// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SubStudy/Public/Test/TestActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SUBSTUDY_API UClass* Z_Construct_UClass_ATestActor();
SUBSTUDY_API UClass* Z_Construct_UClass_ATestActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_SubStudy();
// End Cross Module References

// Begin Class ATestActor Function Test_ImplementableFuntion
static const FName NAME_ATestActor_Test_ImplementableFuntion = FName(TEXT("Test_ImplementableFuntion"));
void ATestActor::Test_ImplementableFuntion()
{
	UFunction* Func = FindFunctionChecked(NAME_ATestActor_Test_ImplementableFuntion);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "\xeb\x82\xb4\xed\x95\xa8\xec\x88\x98" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// c++\xec\x97\x90\xec\x84\x9c \xec\x84\xa0\xec\x96\xb8\xeb\xa7\x8c \xed\x95\x98\xea\xb3\xa0 \xea\xb5\xac\xed\x98\x84\xec\x9d\x80 \xeb\xb8\x94\xeb\xa3\xa8 \xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 (\xea\xb8\xb0\xed\x9a\x8d\xec\x9e\x90\xea\xb0\x80 \xec\x95\xbc\xeb\x9e\x84\xed\x95\xa0\xeb\x95\x8c \xec\x9e\x90\xec\xa3\xbc \xec\x82\xac\xec\x9a\xa9)\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/TestActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "c++\xec\x97\x90\xec\x84\x9c \xec\x84\xa0\xec\x96\xb8\xeb\xa7\x8c \xed\x95\x98\xea\xb3\xa0 \xea\xb5\xac\xed\x98\x84\xec\x9d\x80 \xeb\xb8\x94\xeb\xa3\xa8 \xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 (\xea\xb8\xb0\xed\x9a\x8d\xec\x9e\x90\xea\xb0\x80 \xec\x95\xbc\xeb\x9e\x84\xed\x95\xa0\xeb\x95\x8c \xec\x9e\x90\xec\xa3\xbc \xec\x82\xac\xec\x9a\xa9)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATestActor, nullptr, "Test_ImplementableFuntion", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class ATestActor Function Test_ImplementableFuntion

// Begin Class ATestActor Function Test_NativeEventFunction
static const FName NAME_ATestActor_Test_NativeEventFunction = FName(TEXT("Test_NativeEventFunction"));
void ATestActor::Test_NativeEventFunction()
{
	UFunction* Func = FindFunctionChecked(NAME_ATestActor_Test_NativeEventFunction);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		Test_NativeEventFunction_Implementation();
	}
}
struct Z_Construct_UFunction_ATestActor_Test_NativeEventFunction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "\xeb\x82\xb4\xed\x95\xa8\xec\x88\x98" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//BlueprintNativeEvent : c++ \xec\x97\x90\xec\x84\x9c \xea\xb5\xac\xed\x98\x80\xec\x9d\x80 \xed\x96\x88\xeb\x8a\x94\xeb\x8d\xb0 \xeb\xb8\x94\xeb\xa3\xa8 \xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\xa0\x95\xec\x9d\x98 \xed\x95\x98\xea\xb3\xa0 \xec\x8b\xb6\xec\x9d\x80\xea\xb2\xbd\xec\x9a\xb0\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/TestActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BlueprintNativeEvent : c++ \xec\x97\x90\xec\x84\x9c \xea\xb5\xac\xed\x98\x80\xec\x9d\x80 \xed\x96\x88\xeb\x8a\x94\xeb\x8d\xb0 \xeb\xb8\x94\xeb\xa3\xa8 \xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xec\x9e\xac\xec\xa0\x95\xec\x9d\x98 \xed\x95\x98\xea\xb3\xa0 \xec\x8b\xb6\xec\x9d\x80\xea\xb2\xbd\xec\x9a\xb0" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATestActor_Test_NativeEventFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATestActor, nullptr, "Test_NativeEventFunction", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_Test_NativeEventFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATestActor_Test_NativeEventFunction_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATestActor_Test_NativeEventFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATestActor_Test_NativeEventFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATestActor::execTest_NativeEventFunction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Test_NativeEventFunction_Implementation();
	P_NATIVE_END;
}
// End Class ATestActor Function Test_NativeEventFunction

// Begin Class ATestActor Function Test_UFuntion
struct Z_Construct_UFunction_ATestActor_Test_UFuntion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "\xeb\x82\xb4 \xed\x95\xa8\xec\x88\x98" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// c++\xeb\xa1\x9c \xec\x9e\x91\xec\x84\xb1\xed\x95\x9c \xed\x95\xa8\xec\x88\x98\xeb\xa5\xbc \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\xea\xb0\x80\xeb\x8a\xa5\n" },
#endif
		{ "ModuleRelativePath", "Public/Test/TestActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "c++\xeb\xa1\x9c \xec\x9e\x91\xec\x84\xb1\xed\x95\x9c \xed\x95\xa8\xec\x88\x98\xeb\xa5\xbc \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\xea\xb0\x80\xeb\x8a\xa5" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATestActor_Test_UFuntion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATestActor, nullptr, "Test_UFuntion", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_Test_UFuntion_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATestActor_Test_UFuntion_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ATestActor_Test_UFuntion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATestActor_Test_UFuntion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATestActor::execTest_UFuntion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Test_UFuntion();
	P_NATIVE_END;
}
// End Class ATestActor Function Test_UFuntion

// Begin Class ATestActor
void ATestActor::StaticRegisterNativesATestActor()
{
	UClass* Class = ATestActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Test_NativeEventFunction", &ATestActor::execTest_NativeEventFunction },
		{ "Test_UFuntion", &ATestActor::execTest_UFuntion },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATestActor);
UClass* Z_Construct_UClass_ATestActor_NoRegister()
{
	return ATestActor::StaticClass();
}
struct Z_Construct_UClass_ATestActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Test/TestActor.h" },
		{ "ModuleRelativePath", "Public/Test/TestActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATestActor_Test_ImplementableFuntion, "Test_ImplementableFuntion" }, // 3175166849
		{ &Z_Construct_UFunction_ATestActor_Test_NativeEventFunction, "Test_NativeEventFunction" }, // 223982932
		{ &Z_Construct_UFunction_ATestActor_Test_UFuntion, "Test_UFuntion" }, // 1159827054
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATestActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SubStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATestActor_Statics::ClassParams = {
	&ATestActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ATestActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATestActor()
{
	if (!Z_Registration_Info_UClass_ATestActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATestActor.OuterSingleton, Z_Construct_UClass_ATestActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATestActor.OuterSingleton;
}
template<> SUBSTUDY_API UClass* StaticClass<ATestActor>()
{
	return ATestActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATestActor);
ATestActor::~ATestActor() {}
// End Class ATestActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_TestActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATestActor, ATestActor::StaticClass, TEXT("ATestActor"), &Z_Registration_Info_UClass_ATestActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATestActor), 3738603403U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_TestActor_h_1215169331(TEXT("/Script/SubStudy"),
	Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_TestActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_KI_UnrealCPP7_mainStudy_SubStudy_SubStudy_Source_SubStudy_Public_Test_TestActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
