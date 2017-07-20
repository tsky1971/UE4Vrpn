// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class VRPN : ModuleRules
{
	public VRPN(TargetInfo Target)
	{
		Type = ModuleType.External;

		string includePath = Path.Combine(ModuleDirectory, "include");
        PublicIncludePaths.AddRange(new string[] { includePath });

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));
			PublicAdditionalLibraries.Add("vrpn.lib");
            PublicAdditionalLibraries.Add("quat.lib");
            PublicAdditionalLibraries.Add("gpsnmea.lib");
            PublicAdditionalLibraries.Add("vrpnserver.lib");
            PublicAdditionalLibraries.Add("vrpn_timecode_generator.lib");

            // Delay-load the DLL, so we can load it from the right place first
            // PublicDelayLoadDLLs.Add("libzmq.dll");
        }
	}
}
