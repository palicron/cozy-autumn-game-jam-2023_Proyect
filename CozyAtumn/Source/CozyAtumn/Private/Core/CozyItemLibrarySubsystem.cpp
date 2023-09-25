// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CozyItemLibrarySubsystem.h"

bool UCozyItemLibrarySubsystem::GetItemInformationById(const int32 ItemId, FItemDescription& OutInformation) const
{
	return false;
}

bool UCozyItemLibrarySubsystem::GetItemInformationByCombination(const TArray<int32> ItemIdList,
	FItemDescription& OutInformation) const
{
	return false;
}
