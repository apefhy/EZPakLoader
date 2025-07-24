#include "PakLoader.h"
#include "HAL/PlatformFilemanager.h"
#include "IPlatformFilePak.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

bool UPakLoader::MountPak(const FString& PakPath, int32 PakOrder, const FString& MountPath)
{
    FPakPlatformFile* PakPlatform = (FPakPlatformFile*)(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")));
    if (!PakPlatform)
    {
        UE_LOG(LogTemp, Warning, TEXT("PakPlatform not found!"));
        return false;
    }

    const bool bMounted = PakPlatform->Mount(*PakPath, PakOrder, *MountPath);
    if (!bMounted)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to mount pak: %s"), *PakPath);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Mounted pak: %s"), *PakPath);
    }

    return bMounted;
}

TArray<FString> UPakLoader::GetPakFilesInDirectory(const FString& DirectoryPath)
{
    TArray<FString> PakFiles;
    FString SearchPath = DirectoryPath / TEXT("*.pak");

    IFileManager& FileManager = IFileManager::Get();
    FileManager.FindFiles(PakFiles, *SearchPath, true, false);

    return PakFiles;
}
