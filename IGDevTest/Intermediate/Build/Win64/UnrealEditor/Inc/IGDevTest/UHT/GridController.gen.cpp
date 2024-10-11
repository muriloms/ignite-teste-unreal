// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/GridController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridController() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_AGridController();
	IGDEVTEST_API UClass* Z_Construct_UClass_AGridController_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfinder_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	DEFINE_FUNCTION(AGridController::execOnLeftMouseClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLeftMouseClick();
		P_NATIVE_END;
	}
	void AGridController::StaticRegisterNativesAGridController()
	{
		UClass* Class = AGridController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnLeftMouseClick", &AGridController::execOnLeftMouseClick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Click handling methods\n" },
#endif
		{ "ModuleRelativePath", "Public/GridController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Click handling methods" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridController, nullptr, "OnLeftMouseClick", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics::Function_MetaDataParams), Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AGridController_OnLeftMouseClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AGridController_OnLeftMouseClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGridController);
	UClass* Z_Construct_UClass_AGridController_NoRegister()
	{
		return AGridController::StaticClass();
	}
	struct Z_Construct_UClass_AGridController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathfinderInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PathfinderInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SetDestinationClickAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SetDestinationClickAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AGridController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridController_OnLeftMouseClick, "OnLeftMouseClick" }, // 3572660353
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "GridController.h" },
		{ "ModuleRelativePath", "Public/GridController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridController_Statics::NewProp_GridInstance_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Pathfinding related\n" },
#endif
		{ "ModuleRelativePath", "Public/GridController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pathfinding related" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridController_Statics::NewProp_GridInstance = { "GridInstance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridController, GridInstance), Z_Construct_UClass_APathfindingGrid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::NewProp_GridInstance_MetaData), Z_Construct_UClass_AGridController_Statics::NewProp_GridInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridController_Statics::NewProp_PathfinderInstance_MetaData[] = {
		{ "Category", "Pathfinding" },
		{ "ModuleRelativePath", "Public/GridController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridController_Statics::NewProp_PathfinderInstance = { "PathfinderInstance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridController, PathfinderInstance), Z_Construct_UClass_APathfinder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::NewProp_PathfinderInstance_MetaData), Z_Construct_UClass_AGridController_Statics::NewProp_PathfinderInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridController_Statics::NewProp_SetDestinationClickAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Input action for mouse click\n" },
#endif
		{ "ModuleRelativePath", "Public/GridController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Input action for mouse click" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridController_Statics::NewProp_SetDestinationClickAction = { "SetDestinationClickAction", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridController, SetDestinationClickAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::NewProp_SetDestinationClickAction_MetaData), Z_Construct_UClass_AGridController_Statics::NewProp_SetDestinationClickAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridController_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/GridController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridController_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AGridController, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AGridController_Statics::NewProp_DefaultMappingContext_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridController_Statics::NewProp_GridInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridController_Statics::NewProp_PathfinderInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridController_Statics::NewProp_SetDestinationClickAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridController_Statics::NewProp_DefaultMappingContext,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGridController_Statics::ClassParams = {
		&AGridController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AGridController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::Class_MetaDataParams), Z_Construct_UClass_AGridController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGridController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AGridController()
	{
		if (!Z_Registration_Info_UClass_AGridController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGridController.OuterSingleton, Z_Construct_UClass_AGridController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGridController.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<AGridController>()
	{
		return AGridController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridController);
	AGridController::~AGridController() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGridController, AGridController::StaticClass, TEXT("AGridController"), &Z_Registration_Info_UClass_AGridController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGridController), 1907200745U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridController_h_1395403342(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_GridController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
