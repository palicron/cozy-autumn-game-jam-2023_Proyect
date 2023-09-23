// Copyright Epic Games, Inc. All Rights Reserved.

#include "CozyAtumnGameMode.h"
#include "CozyAtumnCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACozyAtumnGameMode::ACozyAtumnGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
