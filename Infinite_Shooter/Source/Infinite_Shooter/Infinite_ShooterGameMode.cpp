// Copyright Epic Games, Inc. All Rights Reserved.

#include "Infinite_ShooterGameMode.h"
#include "Infinite_ShooterHUD.h"
#include "Infinite_ShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInfinite_ShooterGameMode::AInfinite_ShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AInfinite_ShooterHUD::StaticClass();
}
