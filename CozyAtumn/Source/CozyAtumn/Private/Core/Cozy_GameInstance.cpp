// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Cozy_GameInstance.h"

void UCozy_GameInstance::Init()
{
	Super::Init();
	
}

UDataTable* UCozy_GameInstance::GetDataTableByType(ItemType Type) const
{
	if(ItemsInformation.Contains(Type))
	{
		return ItemsInformation[Type];
	}
	
	return nullptr;
}
