// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UE4VRPNPrivatePCH.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"
//#include "ExampleLibrary.h"

// @third party code - BEGIN
#include "AllowWindowsPlatformTypes.h"
#include "include/vrpn_Tracker.h"
#include "HideWindowsPlatformTypes.h"
// @third party code - END


#define LOCTEXT_NAMESPACE "FUE4VRPNModule"

void FUE4VRPNModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("UE4VRPN")->GetBaseDir();

	UE_LOG(LogTemp, Warning, TEXT("StartupModule() UE4VRPN %s"), *BaseDir);

//	// Add on the relative location of the third party dll and load it
//	FString LibraryPath;
//#if PLATFORM_WINDOWS
//	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UE4VRPNLibrary/Win64/ExampleLibrary.dll"));
//#elif PLATFORM_MAC
//    LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/UE4VRPNLibrary/Mac/Release/libExampleLibrary.dylib"));
//#endif // PLATFORM_WINDOWS
//
//	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
//
//	if (ExampleLibraryHandle)
//	{
//		// Call the test function in the third party library that opens a message box
//		ExampleLibraryFunction();
//	}
//	else
//	{
//		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
//	}
}

void FUE4VRPNModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	//// Free the dll handle
	//FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	//ExampleLibraryHandle = nullptr;

	UE_LOG(LogTemp, Warning, TEXT("ShutdownModule() UE4VRPN"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUE4VRPNModule, UE4VRPN)