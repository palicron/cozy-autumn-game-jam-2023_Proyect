// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CozyItemsAttributesBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class COZYATUMN_API UCozyItemsAttributesBase : public UAttributeSet
{
	GENERATED_BODY()

public:

	UCozyItemsAttributesBase();

	UPROPERTY(ReplicatedUsing = OnRep_CurrentWeight, EditAnywhere, BlueprintReadWrite, Category="Attribute Weight")
	FGameplayAttributeData CurrentWeight;
	ATTRIBUTE_ACCESSORS(UCozyItemsAttributesBase, CurrentWeight)
	UFUNCTION()
	virtual void OnRep_CurrentWeight(const FGameplayAttributeData& OldCurrentWeight);

	UPROPERTY(ReplicatedUsing = OnRep_CurrentTemperature, EditAnywhere, BlueprintReadWrite, Category="Attribute Temperature")
	FGameplayAttributeData CurrentTemperature;
	ATTRIBUTE_ACCESSORS(UCozyItemsAttributesBase, CurrentTemperature)
	UFUNCTION()
	virtual void OnRep_CurrentTemperature(const FGameplayAttributeData& OldCurrentTemperature);

	UPROPERTY(ReplicatedUsing = OnRep_MaxTemperature, EditAnywhere, BlueprintReadWrite, Category="Attribute Temperature")
	FGameplayAttributeData MaxTemperature;
	ATTRIBUTE_ACCESSORS(UCozyItemsAttributesBase, MaxTemperature)
	UFUNCTION()
	virtual void OnRep_MaxTemperature(const FGameplayAttributeData& OldMaxTemperature);

	UPROPERTY(ReplicatedUsing = OnRep_MaxTemperature, EditAnywhere, BlueprintReadWrite, Category="Attribute Temperature")
	FGameplayAttributeData TemperatureDecayPerSecond;
	ATTRIBUTE_ACCESSORS(UCozyItemsAttributesBase, TemperatureDecayPerSecond)
	UFUNCTION()
	virtual void OnRep_TemperatureDecayPerSecond(const FGameplayAttributeData& OldTemperatureDecayPerSecond);

	UPROPERTY(ReplicatedUsing = OnRep_ProductQuality, EditAnywhere, BlueprintReadWrite, Category="Attribute Quality")
	FGameplayAttributeData ProductQuality;
	ATTRIBUTE_ACCESSORS(UCozyItemsAttributesBase, ProductQuality)
	UFUNCTION()
	virtual void OnRep_ProductQuality(const FGameplayAttributeData& OldProductQuality);

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
};
