// Copyright Epic Games, Inc. All Rights Reserved.

#include "CozyAtumnCharacter.h"

#include "AbilitySystemComponent.h"
#include "CozyAtumnProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "Stats/CozyPlayerAttributeSetBase.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ACozyAtumnCharacter

ACozyAtumnCharacter::ACozyAtumnCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem Comp"));
	AttributeSerBaseComp = CreateDefaultSubobject<UCozyPlayerAttributeSetBase>(TEXT("Attribute Base"));
}

void ACozyAtumnCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	if(IsValid(AbilitySystemComp))
	{
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(AttributeSerBaseComp->GetEnergyAttribute()).AddUObject(this,&ACozyAtumnCharacter::OnEnergyChange);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(AttributeSerBaseComp->GetMaxEnergyAttribute()).AddUObject(this,&ACozyAtumnCharacter::OnMaxEnergyChange);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(AttributeSerBaseComp->GetMaxCarryWeightAttribute()).AddUObject(this,&ACozyAtumnCharacter::OnMaxWeightChange);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(AttributeSerBaseComp->GetMovementSpeedAttribute()).AddUObject(this,&ACozyAtumnCharacter::OnMovementSpeedChange);
	}
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

//////////////////////////////////////////////////////////////////////////// Input

void ACozyAtumnCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACozyAtumnCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACozyAtumnCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}



void ACozyAtumnCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACozyAtumnCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

///////Reps/////////
/////--------------------------------------------------------------------------
void ACozyAtumnCharacter::OnEnergyChange(const FOnAttributeChangeData& Data)
{
	const float CurrentEnergy = AbilitySystemComp->GetNumericAttribute(UCozyPlayerAttributeSetBase::GetEnergyAttribute());
}

void ACozyAtumnCharacter::OnMaxEnergyChange(const FOnAttributeChangeData& Data)
{
	const float CurrentMaxEnergy = AbilitySystemComp->GetNumericAttribute(UCozyPlayerAttributeSetBase::GetMaxEnergyAttribute());
}

void ACozyAtumnCharacter::OnMaxWeightChange(const FOnAttributeChangeData& Data)
{
	const float CurrentMaxCarry = AbilitySystemComp->GetNumericAttribute(UCozyPlayerAttributeSetBase::GetMaxCarryWeightAttribute());
}

void ACozyAtumnCharacter::OnMovementSpeedChange(const FOnAttributeChangeData& Data)
{
	const float CurrentMovementSpeed = AbilitySystemComp->GetNumericAttribute(UCozyPlayerAttributeSetBase::GetMovementSpeedAttribute());
}


//--------------------------------------------------------------------------
UAbilitySystemComponent* ACozyAtumnCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

