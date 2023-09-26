#pragma once
#include "Definitions.generated.h"

UENUM(BlueprintType)
enum class ItemType: uint8
{
	It_None      UMETA(DisplayName="None"),
	It_Objet      UMETA(DisplayName="Object"),
	It_Consumable      UMETA(DisplayName="Consumable"),
	It_Product      UMETA(DisplayName="Product"),
	It_Effect      UMETA(DisplayName="Effect")
};

USTRUCT(BlueprintType)
struct FMaterialStore
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 ItemId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 ItemsCount = 0;
	
	FMaterialStore():ItemId(0),ItemsCount(0)
	{
		
	}
	FMaterialStore(const int32 NewId,const int32 NEwCount):ItemId(NewId),ItemsCount(NEwCount)
	{
	}
	
};

USTRUCT(BlueprintType)
struct FItemCombination
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	bool HasConditions = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	ItemType ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	float MinTemperature;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	float MaxTemperature;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 FailItemId;
	
};

USTRUCT(BlueprintType)
struct FItemCombinationInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 ResultId;

	FItemCombination CombinationInformation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	TArray<FMaterialStore> CombineMaterials;
	
};

USTRUCT(BlueprintType)
struct FItemDescription : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 ProductId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	bool bIsAFailItems = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	FName ItemDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=" Combination ")
	int32 MaxNumberOfItems;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=" Combination ")
	TArray<FItemCombinationInformation> PossibleCombinations;

};


USTRUCT(BlueprintType)
struct FItemInfoBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	int32 CurrentId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	FItemDescription ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	float CurrentTemperature;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Information")
	TArray<FMaterialStore> CurrentStoreItems;
	
	FORCEINLINE void operator+=(int NewId)
	{
		for (FMaterialStore& StoreMaterial : CurrentStoreItems)
		{
			if(StoreMaterial.ItemId == NewId)
			{
				StoreMaterial.ItemsCount++;
				return;
			}
		}
		const FMaterialStore NewMaterial = FMaterialStore(NewId,1);
		CurrentStoreItems.Add(NewMaterial);
	}
};

