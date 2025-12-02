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

	bUseControllerRotationYaw = true; // 컨트롤러의 yaw회전을 사용함 -> 컨트롤러의 yaw 회전을 캐릭터에 적용

	//GetCharacterMovement()->bOrientRotationToMovement = true; // 이동방향으로 몸을 돌림
	GetCharacterMovement()->RotationRate = FRotator(0, 360, 0); // 1초에 한바퀴 돌게



}

// Called when the game starts or when spawned
void AActionCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AActionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhanced = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (enhanced) // 향상된 입력 컴포넌트
	{
		enhanced->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AActionCharacter::OnMoveInput);
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

