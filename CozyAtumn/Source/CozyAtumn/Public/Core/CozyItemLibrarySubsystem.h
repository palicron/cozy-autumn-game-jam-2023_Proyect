// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CozyAtumn/Definitions.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CozyItemLibrarySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class COZYATUMN_API UCozyItemLibrarySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool GetItemInformationById(const int32 ItemId, FItemDescription& OutInformation) const;

	UFUNCTION(BlueprintCallable)
	bool GetItemInformationByCombination(const TArray<int32> ItemIdList, FItemDescription& OutInformation) const;
	
};
