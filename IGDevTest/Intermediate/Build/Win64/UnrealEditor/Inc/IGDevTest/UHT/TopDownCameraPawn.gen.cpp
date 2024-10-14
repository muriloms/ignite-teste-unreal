// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/TopDownCameraPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTopDownCameraPawn() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_ATopDownCameraPawn();
	IGDEVTEST_API UClass* Z_Construct_UClass_ATopDownCameraPawn_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	void ATopDownCameraPawn::StaticRegisterNativesATopDownCameraPawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATopDownCameraPawn);
	UClass* Z_Construct_UClass_ATopDownCameraPawn_NoRegister()
	{
		return ATopDownCameraPawn::StaticClass();
	}
	struct Z_Construct_UClass_ATopDownCameraPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TopDownCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LookSensitivity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATopDownCameraPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "TopDownCameraPawn.h" },
		{ "ModuleRelativePath", "Public/TopDownCameraPawn.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_TopDownCamera_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Camera component to view the grid\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TopDownCameraPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera component to view the grid" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_TopDownCamera = { "TopDownCamera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATopDownCameraPawn, TopDownCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_TopDownCamera_MetaData), Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_TopDownCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/TopDownCameraPawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATopDownCameraPawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_SpringArm_MetaData), Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_SpringArm_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_LookSensitivity_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sensibilidade para a rota\xef\xbf\xbd\xef\xbf\xbdo do SprintArm\n" },
#endif
		{ "ModuleRelativePath", "Public/TopDownCameraPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sensibilidade para a rota\xef\xbf\xbd\xef\xbf\xbdo do SprintArm" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_LookSensitivity = { "LookSensitivity", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATopDownCameraPawn, LookSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_LookSensitivity_MetaData), Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_LookSensitivity_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATopDownCameraPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_TopDownCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_SpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATopDownCameraPawn_Statics::NewProp_LookSensitivity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATopDownCameraPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATopDownCameraPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATopDownCameraPawn_Statics::ClassParams = {
		&ATopDownCameraPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATopDownCameraPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ATopDownCameraPawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownCameraPawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATopDownCameraPawn()
	{
		if (!Z_Registration_Info_UClass_ATopDownCameraPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATopDownCameraPawn.OuterSingleton, Z_Construct_UClass_ATopDownCameraPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATopDownCameraPawn.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<ATopDownCameraPawn>()
	{
		return ATopDownCameraPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATopDownCameraPawn);
	ATopDownCameraPawn::~ATopDownCameraPawn() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_TopDownCameraPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_TopDownCameraPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATopDownCameraPawn, ATopDownCameraPawn::StaticClass, TEXT("ATopDownCameraPawn"), &Z_Registration_Info_UClass_ATopDownCameraPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATopDownCameraPawn), 439054977U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_TopDownCameraPawn_h_41750961(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_TopDownCameraPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_TopDownCameraPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
