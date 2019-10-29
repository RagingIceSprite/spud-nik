// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class PotatoModule : ModuleRules
{
	public PotatoModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "DetailCustomizations", "PropertyEditor", "EditorStyle" });
        
        if(Target.Type == TargetRules.TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd" });
            PublicDependencyModuleNames.AddRange(new string[] { "SpudNik_PoCT" });
        }

        PublicIncludePaths.AddRange(new string[] {"PotatoModule/Public"});
        PrivateIncludePaths.AddRange(new string[] {"PotatoModule/Private"});
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
