// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Design1EditorTarget : TargetRules
{
	public Design1EditorTarget( TargetInfo Target) : base(Target)
	{
        // Ìí¼ÓÂ·¾¶Õï¶ÏÊä³ö
        System.Console.WriteLine($"Building for path: {Target.ProjectFile}");

        Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("Design1");
	}
}
