// Copyright Epic Games, Inc. All Rights Reserved.

#include "AAAGameVehicleGameMode.h"
#include "AAAGameVehiclePlayerController.h"

AAAAGameVehicleGameMode::AAAAGameVehicleGameMode()
{
	PlayerControllerClass = AAAAGameVehiclePlayerController::StaticClass();
}
