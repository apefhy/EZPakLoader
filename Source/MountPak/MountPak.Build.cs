using UnrealBuildTool;

public class MountPak : ModuleRules
{
    public MountPak(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "PakFile",
            "Projects"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Uncomment if using Slate UI:
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you need to access Editor functionality (not needed for runtime use)
        // PrivateDependencyModuleNames.Add("UnrealEd");
    }
}
