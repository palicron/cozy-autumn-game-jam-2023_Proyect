// Fill out your copyright notice in the Description page of Project Settings.


#include "Stats/CozyPlayerAttributeSetBase.h"

#include "GameplayEffectExtension.h"

UCozyPlayerAttributeSetBase::UCozyPlayerAttributeSetBase()
{
	Energy.SetCurrentValue(MaxEnergy.GetBaseValue());
}

void UCozyPlayerAttributeSetBase::OnRep_Energy(const FGameplayAttributeData& OldEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyPlayerAttributeSetBase, Energy, OldEnergy);
}

void UCozyPlayerAttributeSetBase::OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyPlayerAttributeSetBase, MaxEnergy, OldMaxEnergy);
}

void UCozyPlayerAttributeSetBase::OnRep_MaxCarryWeight(const FGameplayAttributeData& OldMaxCarryWeight)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyPlayerAttributeSetBase, MaxCarryWeight, OldMaxCarryWeight);
}

void UCozyPlayerAttributeSetBase::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCozyPlayerAttributeSetBase, MovementSpeed, OldMovementSpeed);
}

void UCozyPlayerAttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute.GetUProperty() ==
	FindFieldChecked<FProperty>(UCozyPlayerAttributeSetBase::StaticClass(),GET_MEMBER_NAME_CHECKED(UCozyPlayerAttributeSetBase,Energy)))
	{
		UE_LOG(LogTemp,Warning,TEXT("healt %f"),Energy.GetCurrentValue());
		Energy.SetCurrentValue(FMath::Clamp(Energy.GetCurrentValue(),0.f,MaxEnergy.GetCurrentValue()));
		Energy.SetBaseValue(FMath::Clamp(Energy.GetBaseValue(),0.f,MaxEnergy.GetCurrentValue()));
	}
}

void UCozyPlayerAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
