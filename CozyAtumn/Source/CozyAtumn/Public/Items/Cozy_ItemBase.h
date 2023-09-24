// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "CozyAtumn/Definitions.h"
#include "GameFramework/Actor.h"
#include "Cozy_ItemBase.generated.h"

class UCozyItemsAttributesBase;
class UStaticMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemInfoBaseChangeSignature,FItemInfoBase,NewInfo);
UCLASS()
class COZYATUMN_API ACozy_ItemBase : public AActor , public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACozy_ItemBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FItemInfoBase CurrentItemInfo;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Item Mesh")
	USceneComponent* ItemRoot;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category= "Item Mesh")
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Actor Abilitys")
	UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Actor Abilitys")
	UCozyItemsAttributesBase* AttributeSerBaseComp;
	

public:	

	UPROPERTY(BlueprintAssignable)
	FOnItemInfoBaseChangeSignature OnItemInfoBaseChangeDelegate;
	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	FItemInfoBase GetItemInformation() const { return CurrentItemInfo; }

	

};
