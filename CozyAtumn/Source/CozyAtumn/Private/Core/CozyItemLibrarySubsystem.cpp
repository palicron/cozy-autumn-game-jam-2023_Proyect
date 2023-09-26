// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CozyItemLibrarySubsystem.h"

#include "Core/Cozy_GameInstance.h"

void UCozyItemLibrarySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GameInstanceRef = Cast<UCozy_GameInstance>(GetGameInstance()) ;	
}

bool UCozyItemLibrarySubsystem::GetItemInformationById(const int32 ItemId,const ItemType Type, FItemInfoBase& OutInformation) const
{
	if(!IsValid(GameInstanceRef))
	{
		return false;
	}

	const UDataTable* InformationTable = GameInstanceRef->GetDataTableByType(Type);
	if(IsValid(InformationTable))
	{
		const FString ContextString(TEXT("Item Infor Retrive"));
	
		FString SerachId = FString::FromInt(ItemId);
		FItemDescription* ItemDescription = InformationTable->FindRow<FItemDescription>(FName(*SerachId),ContextString);
		if(ItemDescription)
		{
			OutInformation.CurrentId = ItemDescription->ProductId;
			OutInformation.ItemDescription = *ItemDescription;
			return true;
		}
	}
	return false;
}

bool UCozyItemLibrarySubsystem::GetItemInformationByCombination(const TArray<int32> ItemIdList,
	FItemDescription& OutInformation) const
{
	return false;
}
