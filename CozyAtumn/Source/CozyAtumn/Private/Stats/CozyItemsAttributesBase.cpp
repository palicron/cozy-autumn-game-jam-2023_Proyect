// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/CozyItemsAttributesBase.h"

UCozyItemsAttributesBase::UCozyItemsAttributesBase()
{
}

void UCozyItemsAttributesBase::OnRep_CurrentWeight(const FGameplayAttributeData& OldCurrentWeight)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyItemsAttributesBase, CurrentWeight, OldCurrentWeight);
}

void UCozyItemsAttributesBase::OnRep_CurrentTemperature(const FGameplayAttributeData& OldCurrentTemperature)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyItemsAttributesBase, CurrentTemperature, OldCurrentTemperature);
}

void UCozyItemsAttributesBase::OnRep_MaxTemperature(const FGameplayAttributeData& OldMaxTemperature)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyItemsAttributesBase, MaxTemperature, OldMaxTemperature);
}

void UCozyItemsAttributesBase::OnRep_TemperatureDecayPerSecond(
	const FGameplayAttributeData& OldTemperatureDecayPerSecond)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyItemsAttributesBase, TemperatureDecayPerSecond, OldTemperatureDecayPerSecond);
}

void UCozyItemsAttributesBase::OnRep_ProductQuality(const FGameplayAttributeData& OldProductQuality)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyItemsAttributesBase, ProductQuality, OldProductQuality);
}

void UCozyItemsAttributesBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UCozyItemsAttributesBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
