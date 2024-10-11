// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/PathfindingGrid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathfindingGrid() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EObjectTypeQuery();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	void APathfindingGrid::StaticRegisterNativesAPathfindingGrid()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APathfindingGrid);
	UClass* Z_Construct_UClass_APathfindingGrid_NoRegister()
	{
		return APathfindingGrid::StaticClass();
	}
	struct Z_Construct_UClass_APathfindingGrid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridSize_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GridSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NodeSize;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Trace_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Trace_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Trace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugDraw_MetaData[];
#endif
		static void NewProp_DebugDraw_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DebugDraw;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathfindingGrid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingGrid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PathfindingGrid.h" },
		{ "ModuleRelativePath", "Public/PathfindingGrid.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingGrid_Statics::NewProp_GridSize_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/PathfindingGrid.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APathfindingGrid_Statics::NewProp_GridSize = { "GridSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingGrid, GridSize), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::NewProp_GridSize_MetaData), Z_Construct_UClass_APathfindingGrid_Statics::NewProp_GridSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingGrid_Statics::NewProp_NodeSize_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/PathfindingGrid.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APathfindingGrid_Statics::NewProp_NodeSize = { "NodeSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingGrid, NodeSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::NewProp_NodeSize_MetaData), Z_Construct_UClass_APathfindingGrid_Statics::NewProp_NodeSize_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace_Inner = { "Trace", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Engine_EObjectTypeQuery, METADATA_PARAMS(0, nullptr) }; // 3930035403
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/PathfindingGrid.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace = { "Trace", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingGrid, Trace), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace_MetaData), Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace_MetaData) }; // 3930035403
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/PathfindingGrid.h" },
	};
#endif
	void Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw_SetBit(void* Obj)
	{
		((APathfindingGrid*)Obj)->DebugDraw = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw = { "DebugDraw", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APathfindingGrid), &Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw_MetaData), Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathfindingGrid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingGrid_Statics::NewProp_GridSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingGrid_Statics::NewProp_NodeSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingGrid_Statics::NewProp_Trace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingGrid_Statics::NewProp_DebugDraw,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathfindingGrid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathfindingGrid>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APathfindingGrid_Statics::ClassParams = {
		&APathfindingGrid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APathfindingGrid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::Class_MetaDataParams), Z_Construct_UClass_APathfindingGrid_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingGrid_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APathfindingGrid()
	{
		if (!Z_Registration_Info_UClass_APathfindingGrid.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APathfindingGrid.OuterSingleton, Z_Construct_UClass_APathfindingGrid_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APathfindingGrid.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<APathfindingGrid>()
	{
		return APathfindingGrid::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathfindingGrid);
	APathfindingGrid::~APathfindingGrid() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingGrid_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingGrid_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APathfindingGrid, APathfindingGrid::StaticClass, TEXT("APathfindingGrid"), &Z_Registration_Info_UClass_APathfindingGrid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APathfindingGrid), 2135611325U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingGrid_h_1418709568(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingGrid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingGrid_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
