// Copyright Epic Games, Inc. All Rights Reserved.

#include "AAAGameVehicleWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UAAAGameVehicleWheelFront::UAAAGameVehicleWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}