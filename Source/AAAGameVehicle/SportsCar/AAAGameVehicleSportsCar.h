// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AAAGameVehiclePawn.h"
#include "AAAGameVehicleSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class AAAAGameVehicleSportsCar : public AAAAGameVehiclePawn
{
	GENERATED_BODY()
	
public:

	AAAAGameVehicleSportsCar();
};
