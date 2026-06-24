// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GVH_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AAAGAMEVEHICLE_API AGVH_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	
	virtual void SetupInputComponent() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_MoveForward(const float Value);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_MoveRight (const float Value);
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_StartHandBrake();
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_StopHandBrake();
	
	UFUNCTION(BlueprintImplementableEvent)
	void BP_Brake (const float Value);
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "GVH|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "GVH|Input|Movement")
	TObjectPtr<UInputAction> MoveForwardAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "GVH|Input|Movement")
	TObjectPtr<UInputAction> MoveRightAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "GVH|Input|Movement")
	TObjectPtr<UInputAction> HandBrakeAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "GVH|Input|Movement")
	TObjectPtr<UInputAction> BrakeAction;
	
	void MoveForward(const FInputActionValue& Value);
	
	void MoveRight (const FInputActionValue& Value);
	
	void StartHandBrake();
	
	void StopHandBrake();
	
	void Brake (const FInputActionValue& Value);
};
