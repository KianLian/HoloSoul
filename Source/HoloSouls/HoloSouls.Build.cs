// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HoloSouls : ModuleRules
{
	public HoloSouls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameplayAbilities" });

	//	PrivateDependencyModuleNames.AddRange(new string[] { "Gameplay Abilities", "GameplayTags", "GameplayTasks" });
        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });
    }
}
