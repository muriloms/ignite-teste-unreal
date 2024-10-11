// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/PathfindingController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathfindingController() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfinder_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingController();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingController_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	DEFINE_FUNCTION(APathfindingController::execUpdatePathfinding)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdatePathfinding();
		P_NATIVE_END;
	}
	void APathfindingController::StaticRegisterNativesAPathfindingController()
	{
		UClass* Class = APathfindingController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdatePathfinding", &APathfindingController::execUpdatePathfinding },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to update the pathfinding\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to update the pathfinding" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathfindingController, nullptr, "UpdatePathfinding", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics::Function_MetaDataParams), Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APathfindingController_UpdatePathfinding()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APathfindingController_UpdatePathfinding_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APathfindingController);
	UClass* Z_Construct_UClass_APathfindingController_NoRegister()
	{
		return APathfindingController::StaticClass();
	}
	struct Z_Construct_UClass_APathfindingController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathfindingGridClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PathfindingGridClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathfinderClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PathfinderClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathfinderInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PathfinderInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfCubes_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfCubes;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CubeArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CubeArray;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CubeMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartPointCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StartPointCube;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetPointCube_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetPointCube;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DebugDraw_MetaData[];
#endif
		static void NewProp_DebugDraw_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DebugDraw;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathfindingController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APathfindingController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APathfindingController_UpdatePathfinding, "UpdatePathfinding" }, // 773598309
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PathfindingController.h" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// References to the pathfinding components\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "References to the pathfinding components" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass = { "PathfindingGridClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, PathfindingGridClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APathfindingGrid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData[] = {
		{ "Category", "Pathfinding" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass = { "PathfinderClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, PathfinderClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APathfinder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance = { "GridInstance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, GridInstance), Z_Construct_UClass_APathfindingGrid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance = { "PathfinderInstance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, PathfinderInstance), Z_Construct_UClass_APathfinder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Number of cubes to spawn\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Number of cubes to spawn" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes = { "NumberOfCubes", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, NumberOfCubes), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray_Inner = { "CubeArray", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reference to the cubes\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the cubes" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray = { "CubeArray", nullptr, (EPropertyFlags)0x0010008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, CubeArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeMesh_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Static mesh for the cubes\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static mesh for the cubes" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeMesh = { "CubeMesh", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, CubeMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeMesh_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_StartPointCube_MetaData[] = {
		{ "Category", "PathfindingController" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Start and Target points represented by static mesh cubes\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start and Target points represented by static mesh cubes" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_StartPointCube = { "StartPointCube", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, StartPointCube), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_StartPointCube_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_StartPointCube_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_TargetPointCube_MetaData[] = {
		{ "Category", "PathfindingController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_TargetPointCube = { "TargetPointCube", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, TargetPointCube), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_TargetPointCube_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_TargetPointCube_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw_MetaData[] = {
		{ "Category", "Grid" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	void Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw_SetBit(void* Obj)
	{
		((APathfindingController*)Obj)->DebugDraw = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw = { "DebugDraw", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APathfindingController), &Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathfindingController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_CubeMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_StartPointCube,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_TargetPointCube,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_DebugDraw,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathfindingController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathfindingController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APathfindingController_Statics::ClassParams = {
		&APathfindingController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APathfindingController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::Class_MetaDataParams), Z_Construct_UClass_APathfindingController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APathfindingController()
	{
		if (!Z_Registration_Info_UClass_APathfindingController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APathfindingController.OuterSingleton, Z_Construct_UClass_APathfindingController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APathfindingController.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<APathfindingController>()
	{
		return APathfindingController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathfindingController);
	APathfindingController::~APathfindingController() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APathfindingController, APathfindingController::StaticClass, TEXT("APathfindingController"), &Z_Registration_Info_UClass_APathfindingController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APathfindingController), 2173107160U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_1794368722(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
