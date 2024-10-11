// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pathfinder.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IGDEVTEST_Pathfinder_generated_h
#error "Pathfinder.generated.h already included, missing '#pragma once' in Pathfinder.h"
#endif
#define IGDEVTEST_Pathfinder_generated_h

#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_SPARSE_DATA
#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFindPathArray); \
	DECLARE_FUNCTION(execFindPath);


#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_ACCESSORS
#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPathfinder(); \
	friend struct Z_Construct_UClass_APathfinder_Statics; \
public: \
	DECLARE_CLASS(APathfinder, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/IGDevTest"), NO_API) \
	DECLARE_SERIALIZER(APathfinder)


#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APathfinder(APathfinder&&); \
	NO_API APathfinder(const APathfinder&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APathfinder); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APathfinder); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APathfinder) \
	NO_API virtual ~APathfinder();


#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_19_PROLOG
#define FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_SPARSE_DATA \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_ACCESSORS \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_INCLASS_NO_PURE_DECLS \
	FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IGDEVTEST_API UClass* StaticClass<class APathfinder>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID__Projetos_Game_ignite_teste_unreal_IGDevTest_Source_IGDevTest_Public_Pathfinder_h


#define FOREACH_ENUM_EHEURISTIC(op) \
	op(EHeuristic::Heuristic_Manhatten) \
	op(EHeuristic::Heuristic_Euclidean) 

enum class EHeuristic : uint8;
template<> struct TIsUEnumClass<EHeuristic> { enum { Value = true }; };
template<> IGDEVTEST_API UEnum* StaticEnum<EHeuristic>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
