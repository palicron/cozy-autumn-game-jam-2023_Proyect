// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CozyAtumn : ModuleRules
{
	public CozyAtumn(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","GameplayAbilities","GameplayTags","GameplayTasks","AIModule" });
	}
}
