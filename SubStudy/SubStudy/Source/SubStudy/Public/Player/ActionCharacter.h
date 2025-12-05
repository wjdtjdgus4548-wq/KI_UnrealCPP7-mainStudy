// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ActionCharacter.generated.h"

class UInputAction;
class UResourceComponent;

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
	
	UResourceComponent* GetResourceComponent() { return Resource; }

protected:
	void OnMoveInput(const FInputActionValue& Invalue);
	void OnSprintInput(const FInputActionValue& Invalue);
	void OnRollInput(const FInputActionValue& Invalue);
	void SetSprintMode();

	//걷기모드 설정(다이나믹 델리게이트 떔시 저거 유펑션인가 뭔가 붙어둠
	UFUNCTION()
	void SetWalkMode();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Camera")
	TObjectPtr<class USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Camera")
	TObjectPtr<class UCameraComponent> PlayerCamera = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Resource")
	TObjectPtr<class UResourceComponent> Resource = nullptr;

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

	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|State")//뜀?
	bool bIsSprint = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//초당 달리기 스테미나사용량
	float SprintStaminaCost = 20.0f;

	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player|Resource")//회당 구르기 스테미나사용량
	float RollStaminaCost = 20.0f;

private:
	UPROPERTY()
	TWeakObjectPtr<UAnimInstance> AnimInstance = nullptr;

	


	


};
