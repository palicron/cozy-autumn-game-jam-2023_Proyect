// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CozyPlayerAttributeSetBase.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class COZYATUMN_API UCozyPlayerAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UCozyPlayerAttributeSetBase();

	UPROPERTY(ReplicatedUsing = OnRep_Energy, EditAnywhere, BlueprintReadWrite, Category="Attribute Energy")
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UCozyPlayerAttributeSetBase, Energy)
	UFUNCTION()
	virtual void OnRep_Energy(const FGameplayAttributeData& OldEnergy);

	UPROPERTY(ReplicatedUsing = OnRep_MaxEnergy, EditAnywhere, BlueprintReadWrite, Category="Attribute Energy")
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UCozyPlayerAttributeSetBase, MaxEnergy)
	UFUNCTION()
	virtual void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy);

	UPROPERTY(ReplicatedUsing = OnRep_MaxCarryWeight, EditAnywhere, BlueprintReadWrite, Category="Attribute Weight")
	FGameplayAttributeData MaxCarryWeight;
	ATTRIBUTE_ACCESSORS(UCozyPlayerAttributeSetBase, MaxCarryWeight)
	UFUNCTION()
	virtual void OnRep_MaxCarryWeight(const FGameplayAttributeData& OldMaxCarryWeight);

	UPROPERTY(ReplicatedUsing = OnRep_MovementSpeed, EditAnywhere, BlueprintReadWrite, Category="Attribute Movement")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UCozyPlayerAttributeSetBase, MovementSpeed)
	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
