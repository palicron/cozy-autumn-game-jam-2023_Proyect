// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Cozy_ItemBase.h"

#include "AbilitySystemComponent.h"
#include "Stats/CozyItemsAttributesBase.h"

// Sets default values
ACozy_ItemBase::ACozy_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Item Root"));
	RootComponent = ItemRoot;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item Mesh"));
	ItemMesh->SetupAttachment(RootComponent);

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability Component"));
	
	AttributeSerBaseComp = CreateDefaultSubobject<UCozyItemsAttributesBase>(TEXT("Attribute Base"));
	
}

UAbilitySystemComponent* ACozy_ItemBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

// Called when the game starts or when spawned
void ACozy_ItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACozy_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

