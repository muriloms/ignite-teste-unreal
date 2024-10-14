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
	IGDEVTEST_API UClass* Z_Construct_UClass_AGridObject_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfinder_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingController();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingController_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	DEFINE_FUNCTION(APathfindingController::execSetGridVisibility)
	{
		P_GET_UBOOL(Z_Param_bVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGridVisibility(Z_Param_bVisible);
		P_NATIVE_END;
	}
	void APathfindingController::StaticRegisterNativesAPathfindingController()
	{
		UClass* Class = APathfindingController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetGridVisibility", &APathfindingController::execSetGridVisibility },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics
	{
		struct PathfindingController_eventSetGridVisibility_Parms
		{
			bool bVisible;
		};
		static void NewProp_bVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::NewProp_bVisible_SetBit(void* Obj)
	{
		((PathfindingController_eventSetGridVisibility_Parms*)Obj)->bVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PathfindingController_eventSetGridVisibility_Parms), &Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::NewProp_bVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Fun\xc3\xa7\xc3\xa3o para modificar o DebugDraw do Grid\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fun\xc3\xa7\xc3\xa3o para modificar o DebugDraw do Grid" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathfindingController, nullptr, "SetGridVisibility", nullptr, nullptr, Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PathfindingController_eventSetGridVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::PathfindingController_eventSetGridVisibility_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APathfindingController_SetGridVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APathfindingController_SetGridVisibility_Statics::FuncParams);
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
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridObjArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridObjArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GridObjArray;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridObj_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_GridObj;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DrawGrid_MetaData[];
#endif
		static void NewProp_DrawGrid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DrawGrid;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DrawPath_MetaData[];
#endif
		static void NewProp_DrawPath_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_DrawPath;
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
		{ &Z_Construct_UFunction_APathfindingController_SetGridVisibility, "SetGridVisibility" }, // 3421687563
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
		{ "Comment", "// Refer\xc3\xaancias para as classes de pathfinding\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refer\xc3\xaancias para as classes de pathfinding" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass = { "PathfindingGridClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, PathfindingGridClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APathfindingGrid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData[] = {
		{ "Category", "Pathfinding" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass = { "PathfinderClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, PathfinderClass), Z_Construct_UClass_UClass, Z_Construct_UClass_APathfinder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Inst\xc3\xa2ncias da grade de pathfinding e do pathfinder\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inst\xc3\xa2ncias da grade de pathfinding e do pathfinder" },
#endif
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
		{ "Comment", "// N\xc3\xbamero de cubos a serem gerados\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "N\xc3\xbamero de cubos a serem gerados" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes = { "NumberOfCubes", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, NumberOfCubes), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray_Inner = { "GridObjArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AGridObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Refer\xc3\xaancia aos componentes de malha est\xc3\xa1tica dos cubos\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refer\xc3\xaancia aos componentes de malha est\xc3\xa1tica dos cubos" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray = { "GridObjArray", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, GridObjArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObj_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Objeto do grid\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Objeto do grid" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObj = { "GridObj", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfindingController, GridObj), Z_Construct_UClass_UClass, Z_Construct_UClass_AGridObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObj_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObj_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Vari\xc3\xa1vel EditAnywhere para ativar/desativar o grid\n" },
#endif
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vari\xc3\xa1vel EditAnywhere para ativar/desativar o grid" },
#endif
	};
#endif
	void Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid_SetBit(void* Obj)
	{
		((APathfindingController*)Obj)->DrawGrid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid = { "DrawGrid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APathfindingController), &Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/PathfindingController.h" },
	};
#endif
	void Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath_SetBit(void* Obj)
	{
		((APathfindingController*)Obj)->DrawPath = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath = { "DrawPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APathfindingController), &Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath_MetaData), Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathfindingController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfindingGridClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_GridInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_PathfinderInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_NumberOfCubes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObjArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_GridObj,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawGrid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfindingController_Statics::NewProp_DrawPath,
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
		{ Z_Construct_UClass_APathfindingController, APathfindingController::StaticClass, TEXT("APathfindingController"), &Z_Registration_Info_UClass_APathfindingController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APathfindingController), 765356364U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_1806314939(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_PathfindingController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
