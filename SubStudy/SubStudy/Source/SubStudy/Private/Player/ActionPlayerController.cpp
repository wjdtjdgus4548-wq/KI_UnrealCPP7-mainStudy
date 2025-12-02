// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActionPlayerController.h"
#include "Player/ActionCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"




void AActionPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = 
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()); // 개씨빨련;
	if (Subsystem)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, GameInputPriorty);
	}

	PlayerCameraManager->ViewPitchMax = ViewPitchMax;
	PlayerCameraManager->ViewPitchMin = ViewPitchMin;

}

void AActionPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* enhanced = Cast<UEnhancedInputComponent>(InputComponent);

	if (enhanced) // 향상된 입력 컴포넌트
	{
		enhanced->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AActionPlayerController::OnLookInput);
	}
}

void AActionPlayerController::OnLookInput(const FInputActionValue& Invalue)
{
	FVector2D lookAxis = Invalue.Get<FVector2D>();
	AddYawInput(lookAxis.X);
	AddPitchInput(lookAxis.Y);
}
