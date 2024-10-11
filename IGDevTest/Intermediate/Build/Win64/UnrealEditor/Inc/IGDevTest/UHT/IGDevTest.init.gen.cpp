// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIGDevTest_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_IGDevTest;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_IGDevTest()
	{
		if (!Z_Registration_Info_UPackage__Script_IGDevTest.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/IGDevTest",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x4323215A,
				0x098659EC,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_IGDevTest.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_IGDevTest.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_IGDevTest(Z_Construct_UPackage__Script_IGDevTest, TEXT("/Script/IGDevTest"), Z_Registration_Info_UPackage__Script_IGDevTest, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4323215A, 0x098659EC));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
