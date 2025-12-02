// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ActionCharacter.generated.h"

class UInputAction;

UCLASS()
class SUBSTUDY_API AActionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void OnMoveInput(const FInputActionValue& Invalue);
	void OnSprintInput(const FInputActionValue& Invalue);
	void OnRollInput(const FInputActionValue& Invalue);
	void SetSprintMode();
	void SetWalkMode();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Camera")
	TObjectPtr<class USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Camera")
	TObjectPtr<class UCameraComponent> PlayerCamera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")

	TObjectPtr<UInputAction> IA_Move = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")

	TObjectPtr<UInputAction> IA_Sprint = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Roll = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Palyer|Movemnt")
	float SprintSpeed = 1250.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Movement")
	float WalkSpeed = 550.0f;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation|Montage")
	TObjectPtr <UAnimMontage> RollMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Resorurce")
	float CurrentStamina = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Resorurce")
	float MaxStamina = 200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|State")//뜀?
	bool bIsSprint = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//초당 달리기 스테미나사용량
	float SprintStaminaCost = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//몇초뒤부터 회복 시작할건지
	float StaminaRegenCoolTime = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//초당 스태미나 회복량
	float StaminaRegenAmount = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//회당 구르기 스테미나사용량
	float RollStaminaCost = 20.0f;

private:
	UPROPERTY()
	TWeakObjectPtr<UAnimInstance> AnimInstance = nullptr;

	
	float TimeSinceLastStaminaUse = 0.0f;
	FTimerHandle StaminaCoolTimer;
	bool bRengenStamina = false;

	void StaminaRegenTimerSet();


};
