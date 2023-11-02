// Copyright Epic Games, Inc. All Rights Reserved.

#include "HoloSoulsGameMode.h"
#include "HoloSoulsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHoloSoulsGameMode::AHoloSoulsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
