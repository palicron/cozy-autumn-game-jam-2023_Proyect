// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CozyAtumn/Definitions.h"
#include "Engine/GameInstance.h"
#include "Cozy_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class COZYATUMN_API UCozy_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Itemes Information")
	TMap<ItemType,UDataTable*> ItemsInformation;

	virtual void Init() override;

	UDataTable* GetDataTableByType(ItemType Type) const;


	
};
