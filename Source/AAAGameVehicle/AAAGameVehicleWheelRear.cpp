// Copyright Epic Games, Inc. All Rights Reserved.

#include "AAAGameVehicleWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UAAAGameVehicleWheelRear::UAAAGameVehicleWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}