// Nicolas Nieto - GCC - Copyright - 2026

// Header include
#include "Public/Player/GVH_PlayerController.h"

// Engine Includes
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem))
	{
		return;
	}
	
	for (UInputMappingContext* Context : InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context, 0);
	}
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent))
	{
		return;
	}
	
	EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ThisClass::MoveForward);
	EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ThisClass::MoveRight);
	
	EnhancedInputComponent->BindAction(HandBrakeAction, ETriggerEvent::Started, this, &ThisClass::StartHandBrake);
	EnhancedInputComponent->BindAction(HandBrakeAction, ETriggerEvent::Completed, this, &ThisClass::StopHandBrake);
	
	EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Ongoing, this, &ThisClass::Brake);
	
	EnhancedInputComponent->BindAction(RotateCameraAction, ETriggerEvent::Triggered, this, &ThisClass::RotateCamera);
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::MoveForward(const FInputActionValue& Value)
{
	const float ForwardValue = Value.Get<float>();
	BP_MoveForward(ForwardValue);
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::MoveRight(const FInputActionValue& Value)
{
	const float RightValue = Value.Get<float>();
	BP_MoveRight(RightValue);
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::StartHandBrake()
{
	BP_StartHandBrake();
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::StopHandBrake()
{
	BP_StopHandBrake();
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::Brake(const FInputActionValue& Value)
{
	const float BrakeValue = Value.Get<float>();
	BP_Brake(BrakeValue);
}

//----------------------------------------------------------------------------------------------------------------------
void AGVH_PlayerController::RotateCamera(const FInputActionValue& Value)
{
	const FVector2D RotationValue = Value.Get<FVector2D>();
	BP_RotateCamera(RotationValue);
}