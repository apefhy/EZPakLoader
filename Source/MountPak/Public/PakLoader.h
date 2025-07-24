#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PakLoader.generated.h"

UCLASS()
class MOUNTPAK_API UPakLoader : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Pak")
    static bool MountPak(const FString& PakPath, int32 PakOrder = 0, const FString& MountPath = TEXT(""));

    UFUNCTION(BlueprintCallable, Category = "Pak")
    static TArray<FString> GetPakFilesInDirectory(const FString& DirectoryPath);
};
