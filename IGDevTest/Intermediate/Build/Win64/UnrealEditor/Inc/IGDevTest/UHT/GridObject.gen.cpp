// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/GridObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridObject() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_AGridObject();
	IGDEVTEST_API UClass* Z_Construct_UClass_AGridObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	void AGridObject::StaticRegisterNativesAGridObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridObject);
	UClass* Z_Construct_UClass_AGridObject_NoRegister()
	{
		return AGridObject::StaticClass();
	}
	struct Z_Construct_UClass_AGridObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CubeMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridObject_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GridObject.h" },
		{ "ModuleRelativePath", "Public/GridObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridObject_Statics::NewProp_CubeMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GridObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridObject_Statics::NewProp_CubeMesh = { "CubeMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridObject, CubeMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridObject_Statics::NewProp_CubeMesh_MetaData), Z_Construct_UClass_AGridObject_Statics::NewProp_CubeMesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridObject_Statics::NewProp_CubeMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridObject_Statics::ClassParams = {
		&AGridObject::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGridObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGridObject_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridObject_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridObject_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridObject_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AGridObject()
	{
		if (!Z_Registration_Info_UClass_AGridObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridObject.OuterSingleton, Z_Construct_UClass_AGridObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGridObject.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<AGridObject>()
	{
		return AGridObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridObject);
	AGridObject::~AGridObject() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGridObject, AGridObject::StaticClass, TEXT("AGridObject"), &Z_Registration_Info_UClass_AGridObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridObject), 977178222U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridObject_h_2877333088(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
