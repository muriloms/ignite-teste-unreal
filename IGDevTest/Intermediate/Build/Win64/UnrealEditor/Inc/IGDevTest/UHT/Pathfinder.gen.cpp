// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IGDevTest/Public/Pathfinder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePathfinder() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfinder();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfinder_NoRegister();
	IGDEVTEST_API UClass* Z_Construct_UClass_APathfindingGrid_NoRegister();
	IGDEVTEST_API UEnum* Z_Construct_UEnum_IGDevTest_EHeuristic();
	UPackage* Z_Construct_UPackage__Script_IGDevTest();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHeuristic;
	static UEnum* EHeuristic_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHeuristic.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHeuristic.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_IGDevTest_EHeuristic, (UObject*)Z_Construct_UPackage__Script_IGDevTest(), TEXT("EHeuristic"));
		}
		return Z_Registration_Info_UEnum_EHeuristic.OuterSingleton;
	}
	template<> IGDEVTEST_API UEnum* StaticEnum<EHeuristic>()
	{
		return EHeuristic_StaticEnum();
	}
	struct Z_Construct_UEnum_IGDevTest_EHeuristic_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enumerators[] = {
		{ "EHeuristic::Heuristic_Manhatten", (int64)EHeuristic::Heuristic_Manhatten },
		{ "EHeuristic::Heuristic_Euclidean", (int64)EHeuristic::Heuristic_Euclidean },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Heuristic_Euclidean.DisplayName", "Euclidean" },
		{ "Heuristic_Euclidean.Name", "EHeuristic::Heuristic_Euclidean" },
		{ "Heuristic_Manhatten.DisplayName", "Manhatten" },
		{ "Heuristic_Manhatten.Name", "EHeuristic::Heuristic_Manhatten" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_IGDevTest,
		nullptr,
		"EHeuristic",
		"EHeuristic",
		Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enum_MetaDataParams), Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_IGDevTest_EHeuristic()
	{
		if (!Z_Registration_Info_UEnum_EHeuristic.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHeuristic.InnerSingleton, Z_Construct_UEnum_IGDevTest_EHeuristic_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHeuristic.InnerSingleton;
	}
	DEFINE_FUNCTION(APathfinder::execFindPathArray)
	{
		P_GET_STRUCT(FVector,Z_Param_Start);
		P_GET_STRUCT(FVector,Z_Param_End);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=P_THIS->FindPathArray(Z_Param_Start,Z_Param_End);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APathfinder::execFindPath)
	{
		P_GET_STRUCT(FVector,Z_Param_Start);
		P_GET_STRUCT(FVector,Z_Param_End);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->FindPath(Z_Param_Start,Z_Param_End);
		P_NATIVE_END;
	}
	void APathfinder::StaticRegisterNativesAPathfinder()
	{
		UClass* Class = APathfinder::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindPath", &APathfinder::execFindPath },
			{ "FindPathArray", &APathfinder::execFindPathArray },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APathfinder_FindPath_Statics
	{
		struct Pathfinder_eventFindPath_Parms
		{
			FVector Start;
			FVector End;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_End;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPath_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPath_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPath_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APathfinder_FindPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_End,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathfinder_FindPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "AStar" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APathfinder_FindPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathfinder, nullptr, "FindPath", nullptr, nullptr, Z_Construct_UFunction_APathfinder_FindPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_APathfinder_FindPath_Statics::Pathfinder_eventFindPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_APathfinder_FindPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APathfinder_FindPath_Statics::Pathfinder_eventFindPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APathfinder_FindPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APathfinder_FindPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APathfinder_FindPathArray_Statics
	{
		struct Pathfinder_eventFindPathArray_Parms
		{
			FVector Start;
			FVector End;
			TArray<FVector> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_End;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPathArray_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPathArray_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pathfinder_eventFindPathArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APathfinder_FindPathArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_End,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APathfinder_FindPathArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APathfinder_FindPathArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "AStar" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APathfinder_FindPathArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APathfinder, nullptr, "FindPathArray", nullptr, nullptr, Z_Construct_UFunction_APathfinder_FindPathArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPathArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_APathfinder_FindPathArray_Statics::Pathfinder_eventFindPathArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPathArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_APathfinder_FindPathArray_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APathfinder_FindPathArray_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APathfinder_FindPathArray_Statics::Pathfinder_eventFindPathArray_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APathfinder_FindPathArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APathfinder_FindPathArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APathfinder);
	UClass* Z_Construct_UClass_APathfinder_NoRegister()
	{
		return APathfinder::StaticClass();
	}
	struct Z_Construct_UClass_APathfinder_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Heuristic_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Heuristic_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Heuristic;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CubeArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CubeArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CubeArray;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GridInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GridInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Debug_MetaData[];
#endif
		static void NewProp_Debug_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Debug;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APathfinder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IGDevTest,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APathfinder_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APathfinder_FindPath, "FindPath" }, // 3617301184
		{ &Z_Construct_UFunction_APathfinder_FindPathArray, "FindPathArray" }, // 2000674163
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfinder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Pathfinder.h" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic_MetaData[] = {
		{ "Category", "Enum" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic = { "Heuristic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfinder, Heuristic), Z_Construct_UEnum_IGDevTest_EHeuristic, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic_MetaData), Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic_MetaData) }; // 4124415309
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray_Inner = { "CubeArray", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray_MetaData[] = {
		{ "Category", "Pathfinding" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Nova vari\xef\xbf\xbdvel para armazenar os cubos instanciados\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Nova vari\xef\xbf\xbdvel para armazenar os cubos instanciados" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray = { "CubeArray", nullptr, (EPropertyFlags)0x0010008000000009, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfinder, CubeArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray_MetaData), Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfinder_Statics::NewProp_GridInstance_MetaData[] = {
		{ "Category", "Pathfinding" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_GridInstance = { "GridInstance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APathfinder, GridInstance), Z_Construct_UClass_APathfindingGrid_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::NewProp_GridInstance_MetaData), Z_Construct_UClass_APathfinder_Statics::NewProp_GridInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APathfinder_Statics::NewProp_Debug_MetaData[] = {
		{ "Category", "Pathfinding" },
		{ "ModuleRelativePath", "Public/Pathfinder.h" },
	};
#endif
	void Z_Construct_UClass_APathfinder_Statics::NewProp_Debug_SetBit(void* Obj)
	{
		((APathfinder*)Obj)->Debug = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APathfinder_Statics::NewProp_Debug = { "Debug", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APathfinder), &Z_Construct_UClass_APathfinder_Statics::NewProp_Debug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::NewProp_Debug_MetaData), Z_Construct_UClass_APathfinder_Statics::NewProp_Debug_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APathfinder_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_Heuristic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_CubeArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_GridInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APathfinder_Statics::NewProp_Debug,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APathfinder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APathfinder>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APathfinder_Statics::ClassParams = {
		&APathfinder::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APathfinder_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::Class_MetaDataParams), Z_Construct_UClass_APathfinder_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APathfinder_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APathfinder()
	{
		if (!Z_Registration_Info_UClass_APathfinder.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APathfinder.OuterSingleton, Z_Construct_UClass_APathfinder_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APathfinder.OuterSingleton;
	}
	template<> IGDEVTEST_API UClass* StaticClass<APathfinder>()
	{
		return APathfinder::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APathfinder);
	APathfinder::~APathfinder() {}
	struct Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::EnumInfo[] = {
		{ EHeuristic_StaticEnum, TEXT("EHeuristic"), &Z_Registration_Info_UEnum_EHeuristic, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4124415309U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APathfinder, APathfinder::StaticClass, TEXT("APathfinder"), &Z_Registration_Info_UClass_APathfinder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APathfinder), 1580966884U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_2884480284(TEXT("/Script/IGDevTest"),
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
