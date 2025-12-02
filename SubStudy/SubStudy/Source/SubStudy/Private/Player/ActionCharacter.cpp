// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActionCharacter.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
AActionCharacter::AActionCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 350.0f;
	SpringArm->SocketOffset = FVector(0, 0, 250);
	SpringArm->bUsePawnControlRotation = true; // 스프링암이 컨트롤러에 맞춰 회전함

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(SpringArm);
	PlayerCamera->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));

	bUseControllerRotationYaw = false; // 컨트롤러의 yaw회전을 사용함 -> 컨트롤러의 yaw 회전을 캐릭터에 적용

	//GetCharacterMovement()->bOrientRotationToMovement = true; // 이동방향으로 몸을 돌림
	GetCharacterMovement()->RotationRate = FRotator(0, 360, 0); // 1초에 한바퀴 돌게



}

// Called when the game starts or when spawned
void AActionCharacter::BeginPlay()
{
	Super::BeginPlay();

	AnimInstance = GetMesh()->GetAnimInstance(); // ABP 객체 가져오기
	//시작시 리셋 시키기 안정성 up
	CurrentStamina = MaxStamina;

	bIsSprint = false;
}

// Called every frame
void AActionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceLastStaminaUse += DeltaTime;
	if (TimeSinceLastStaminaUse > StaminaRegenCoolTime && CurrentStamina <= MaxStamina)
	{
		CurrentStamina = FMath::Min(CurrentStamina + StaminaRegenAmount * DeltaTime, MaxStamina);
		
		UE_LOG(LogTemp, Warning, TEXT("Stamina Regen : %.1f"), CurrentStamina);
	}

	if (bIsSprint)
	{
		CurrentStamina -= SprintStaminaCost * DeltaTime;
		//TimeSinceLastStaminaUse = 0;

		StaminaRegenTimerSet();
		
		if (CurrentStamina <= 0)
		{
			CurrentStamina = 0.0f;
			SetWalkMode();
		}
		UE_LOG(LogTemp, Warning, TEXT("스태미나 남은거 : %.1f"), CurrentStamina);
			
	}

}

// Called to bind functionality to input
void AActionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhanced = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (enhanced) // 향상된 입력 컴포넌트
	{
		enhanced->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AActionCharacter::OnMoveInput);
		enhanced->BindActionValueLambda(IA_Sprint, ETriggerEvent::Started, [this](const FInputActionValue& _) {
			SetSprintMode();
			});
		enhanced->BindActionValueLambda(IA_Sprint, ETriggerEvent::Completed, [this](const FInputActionValue& _) {
			SetWalkMode();
			});
		enhanced->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AActionCharacter::OnRollInput);
	}

}

void AActionCharacter::OnMoveInput(const FInputActionValue& Invalue)
{
	FVector2D InputDirection = Invalue.Get<FVector2D>();
	//UE_LOG(LogTemp, Log, TEXT("Dir : (%.1f, %.1f"), InputDirection.X, InputDirection.Y);
	//UE_LOG(LogTemp, Log, TEXT("Dir : (%s"), *InputDirection.ToString());

	FVector moveDirection(InputDirection.Y, InputDirection.X, 0.0f);

	FQuat ControlYawRotation = FQuat(FRotator(0, GetControlRotation().Yaw, 0)); // 컨트롤러의 yaw 회전을 따로 뽑아와서
	moveDirection = ControlYawRotation.RotateVector(moveDirection); // 이동방향에 적용

	AddMovementInput(moveDirection);

}

void AActionCharacter::OnSprintInput(const FInputActionValue& Invalue)
{
}

void AActionCharacter::OnRollInput(const FInputActionValue& Invalue)
{
	if (AnimInstance.IsValid())
	{
		if (!AnimInstance->IsAnyMontagePlaying() && CurrentStamina > RollStaminaCost)
		{
			//SetActorRotation(GetLastMovementInputVector().Rotation()); //마지막 입력 방향으로 회전 시키기
			CurrentStamina -= RollStaminaCost;
			//TimeSinceLastStaminaUse = 0;
			StaminaRegenTimerSet();
			UE_LOG(LogTemp, Warning, TEXT("현재 스태미나 잔량 : %.1f"), CurrentStamina);
			PlayAnimMontage(RollMontage);
		}
	}
	
}

void AActionCharacter::SetSprintMode()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	bIsSprint = true;
}

void AActionCharacter::SetWalkMode()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bIsSprint = false;
}

void AActionCharacter::StaminaRegenTimerSet()
{

	GetWorldTimerManager().SetTimer(
		StaminaCoolTimer,
		[this]() {
			bRengenStamina = true;
		},
		StaminaRegenCoolTime,
		false);
}

