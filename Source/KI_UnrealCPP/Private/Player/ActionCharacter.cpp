/// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActionCharacter.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/ResourceComponent.h"
#include "Weapon/WeaponActor.h"
#include "Weapon/WeaponPickUp.h"
#include "StatusComponent.h"
#include "UI/MainHudWidget.h"

// Sets default values
AActionCharacter::AActionCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	SetActorTickEnabled(true);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 350.0f;
	SpringArm->SocketOffset = FVector(0, 0, 250);
	SpringArm->bUsePawnControlRotation = true;	// 스프링암의 회전을 컨트롤러에 맞춤

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(SpringArm);
	PlayerCamera->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));

	Resource = CreateDefaultSubobject<UResourceComponent>(TEXT("PlayerResource"));

	bUseControllerRotationYaw = false;	// 컨트롤러의 Yaw 회전 사용 안함
	GetCharacterMovement()->bOrientRotationToMovement = true;	// 이동 방향으로 캐릭터 회전
	GetCharacterMovement()->RotationRate = FRotator(0, 360, 0);

	Status = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));

	QuickSlotIDs.SetNum(4);

	
}

// Called when the game starts or when spawned
void AActionCharacter::BeginPlay()
{
	Super::BeginPlay();

	

	if (HUDWidgetClass)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		if (PC)
		{
			HUDWidget = CreateWidget<UMainHudWidget>(PC, HUDWidgetClass);
			if (HUDWidget)
			{
				HUDWidget->AddToViewport();
			}
		}
	}
	

	if (GetMesh())
	{
		AnimInstance = GetMesh()->GetAnimInstance();	// ABP 객체 가져오기
	}
	if (Resource)
	{
		Resource->OnStaminaEmpty.AddDynamic(this, &AActionCharacter::SetWalkMode);
	}

	// 게임 진행 중에 자주 변경되는 값은 시작 시점에서 리셋을 해주는 것이 좋다.
	bIsSprint = false;
	if (WeaponClass)	// UPROPERTY(EditAnywhere) TSubclassOf<AWeaponActor> WeaponClass; 라고 가정
	{
		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.Instigator = this;

		AWeaponActor* NewWeapon = GetWorld()->SpawnActor<AWeaponActor>(
			WeaponClass,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			Params);

		if (NewWeapon)
		{
			// hand_r_Socket 에 붙이기 (메쉬에 미리 소켓 만들어 놔야 함)
			FAttachmentTransformRules Rules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true);

			NewWeapon->AttachToComponent(
				GetMesh(),
				Rules,
				TEXT("hand_r_Socket")); // 소켓 이름

			// 서로 참조 연결
			CurrentWeapon = NewWeapon;        // TWeakObjectPtr<AWeaponActor> 라고 가정
			NewWeapon->SetWeaponOwner(this);    // WeaponActor.h 에 TWeakObjectPtr<AActionCharacter> WeaponOwner; 있다고 가정

			BaseWeapon = CurrentWeapon;
			EnhancedWeapon = nullptr;
			bUsingEnhancedWeapon = false;
			EnhancedMaxUses = 0;
			EnhancedRemainingUses = 0;


		}
	}

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay: HUD 생성 시도"));

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC && HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UMainHudWidget>(PC, HUDWidgetClass);
		if (HUDWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("HUDWidget 생성 완료! Viewport 추가"));
			HUDWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("HUDWidget 생성 실패..."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HUDWidgetClass 또는 PlayerController NULL"));
	}

}
void AActionCharacter::OnQuickSlot1(const FInputActionValue& Value)
{
	SelectQuickSlot(0); // 0번 슬롯
}

void AActionCharacter::OnQuickSlot2(const FInputActionValue& Value)
{
	SelectQuickSlot(1); // 1번 슬롯
}

void AActionCharacter::OnQuickSlot3(const FInputActionValue& Value)
{
	SelectQuickSlot(2); // 2번 슬롯
}

void AActionCharacter::OnQuickSlot4(const FInputActionValue& Value)
{
	SelectQuickSlot(3); // 3번 슬롯
}
// Called every frame
void AActionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpendRunStamina(DeltaTime);
}

// Called to bind functionality to input
void AActionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* enhanced = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhanced)	// 입력 컴포넌트가 향상된 입력 컴포넌트일 때
	{
		enhanced->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AActionCharacter::OnMoveInput);
		enhanced->BindActionValueLambda(IA_Sprint, ETriggerEvent::Started,
			[this](const FInputActionValue& _) {
				SetSprintMode();
			});
		enhanced->BindActionValueLambda(IA_Sprint, ETriggerEvent::Completed,
			[this](const FInputActionValue& _) {
				SetWalkMode();
			});
		enhanced->BindAction(IA_Roll, ETriggerEvent::Triggered, this, &AActionCharacter::OnRollInput);
		enhanced->BindAction(IA_Attack, ETriggerEvent::Triggered, this, &AActionCharacter::OnAttackInput);
		enhanced->BindAction(IA_DropItem, ETriggerEvent::Started, this, &AActionCharacter::DropWeapon);
		enhanced->BindAction(IA_QuickSlot1, ETriggerEvent::Started, this, &AActionCharacter::OnQuickSlot1);
		enhanced->BindAction(IA_QuickSlot2, ETriggerEvent::Started, this, &AActionCharacter::OnQuickSlot2);
		enhanced->BindAction(IA_QuickSlot3, ETriggerEvent::Started, this, &AActionCharacter::OnQuickSlot3);
		enhanced->BindAction(IA_QuickSlot4, ETriggerEvent::Started, this, &AActionCharacter::OnQuickSlot4);
		
	}
	
}

void AActionCharacter::OnAttackEnable(bool bEnable)
{
	
	if (CurrentWeapon)
	{
		CurrentWeapon->AttackEnable(bEnable);
	}
	
	UE_LOG(LogTemp, Warning, TEXT("OnAttackEnable: %s"), bEnable ? TEXT("True") : TEXT("False"));

	if (bEnable)
	{
		ConsumeEnhancedWeaponUse();
	}
}

void AActionCharacter::OnMoveInput(const FInputActionValue& InValue)
{
	FVector2D inputDirection = InValue.Get<FVector2D>();
	//UE_LOG(LogTemp, Log, TEXT("Dir : (%.1f, %.1f)"), inputDirection.X, inputDirection.Y);
	//UE_LOG(LogTemp, Log, TEXT("Dir : (%s)"), *inputDirection.ToString());
	FVector moveDirection(inputDirection.Y, inputDirection.X, 0.0f);

	FQuat controlYawRotation = FQuat(FRotator(0, GetControlRotation().Yaw, 0));	// 컨트롤러의 Yaw회전을 따로 뽑아와서
	moveDirection = controlYawRotation.RotateVector(moveDirection);	// 이동 방향에 적용

	AddMovementInput(moveDirection);

}

void AActionCharacter::OnRollInput(const FInputActionValue& InValue)
{
	if (AnimInstance.IsValid())
	{
		if (!AnimInstance->IsAnyMontagePlaying()
			&& Resource->HasEnoughStamina(RollStaminaCost))	// 몽타주 재생중이 아니고 충분한 스태미너가 있을 때만 작동
		{
			//if (!GetLastMovementInputVector().IsNearlyZero())	// 입력을 하는 중에만 즉시 회전
			//{
			//	SetActorRotation(GetLastMovementInputVector().Rotation());	// 마지막 입력 방향으로 즉시 회전 시키기
			//}
			Resource->AddStamina(-RollStaminaCost);	// 스태미너 감소
			PlayAnimMontage(RollMontage);
		}
	}
}

void AActionCharacter::OnAttackInput(const FInputActionValue& InValue)
{
	if (AnimInstance.IsValid() && Resource->HasEnoughStamina(AttackStaminaCost)) // 애님 인스턴스가 있고 스태미너도 충분할 때
	{
		if (!AnimInstance->IsAnyMontagePlaying())	// 몽타주가 재생 중이 아닐 때
		{
			// 첫번째 공격
			PlayAnimMontage(AttackMontage);
			Resource->AddStamina(-AttackStaminaCost);	// 스태미너 감소
		}
		else if (AnimInstance->GetCurrentActiveMontage() == AttackMontage)	// 몽타주가 재생 중인데, AttackMontage가 재생중이면
		{
			// 콤보 공격
			SectionJumpForCombo();
		}
	}
}

void AActionCharacter::SetSprintMode()
{
	//UE_LOG(LogTemp, Warning, TEXT("달리기 모드"));
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	bIsSprint = true;
}

void AActionCharacter::SetWalkMode()
{
	//UE_LOG(LogTemp, Warning, TEXT("걷기 모드"));
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	bIsSprint = false;
}

void AActionCharacter::SectionJumpForCombo()
{
	if (SectionJumpNotify.IsValid() && bComboReady)	// SectionJumpNotify가 있고 콤보가 가능한 상태이면
	{
		UAnimMontage* current = AnimInstance->GetCurrentActiveMontage();
		AnimInstance->Montage_SetNextSection(					// 다음 섹션으로 점프하기
			AnimInstance->Montage_GetCurrentSection(current),		// 현재 섹션
			SectionJumpNotify->GetNextSectionName(),				// 다음 섹션의 이름
			current);												// 실행될 몽타주

		bComboReady = false;	// 중복실행 방지
		Resource->AddStamina(-AttackStaminaCost);	// 스태미너 감소
	}
}

void AActionCharacter::SpendRunStamina(float DeltaTime)
{
	if ((bIsSprint && !GetVelocity().IsNearlyZero())							// 달리기 상태이고 움직이지 않고 있다.			
		&& (AnimInstance.IsValid() && !AnimInstance->IsAnyMontagePlaying()))	// 어떤 몽타쥬도 재생중이지 않다.(루트모션 때문에 Velocity 변경있음)
	{
		Resource->AddStamina(-SprintStaminaCost * DeltaTime);	// 스태미너 감소
		//UE_LOG(LogTemp, Log, TEXT("Velocity : %s"), *GetVelocity().ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Stamina : %.1f"), Resource->GetCurrentStamina());
	}

	//GetWorld()->GetFirstPlayerController()->GetHUD();
}

float AActionCharacter::GetAttackPower() 
{
	if (Status)
	{
		return Status->GetAttackPower();
	}
	return 0.0f;
}
void AActionCharacter::OnPickUpEnhancedWeapon(AWeaponPickUp* Pickup)
{
	

	if (!Pickup || !Pickup->WeaponClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pickup or WeaponClass is null"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("1"));


	if (!CurrentWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnPickUpEnhancedWeapon: CurrentWeapon is NULL"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnPickUpEnhancedWeapon: CurrentWeaponID=%s, PickupID=%s"),
			*CurrentWeapon->WeaponID.ToString(),
			*Pickup->WeaponID.ToString());
	}

	if (CurrentWeapon && CurrentWeapon->WeaponID == Pickup->WeaponID)
	{
		//같은 무기는 인벤토리에 저장 후 종료
		AddWeaponToInventory(Pickup->WeaponID, Pickup->StackValue);
		//인벤토리 로그
		UE_LOG(LogTemp, Warning, TEXT(" %s 가  %d개 있음. 총 %d 개의 아이템이 존재함"),
			*Pickup->WeaponID.ToString(),
			Pickup->StackValue,
			WeaponInventory[Pickup->WeaponID]);

		return;
	}
	if (!BaseWeapon && CurrentWeapon)
	{
		BaseWeapon = CurrentWeapon;
	}
	if (bUsingEnhancedWeapon && CurrentWeapon && CurrentWeapon != BaseWeapon)
	{
		CurrentWeapon->AttackEnable(false);

		CurrentWeapon->Destroy();
		CurrentWeapon = nullptr;
		bUsingEnhancedWeapon = false;
	}
	
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.Instigator = this;

	AWeaponActor* NewEnhanced = GetWorld()->SpawnActor<AWeaponActor>(
		Pickup->WeaponClass,
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		Params);

	const FName SocketName = TEXT("hand_r_Socket");

	FAttachmentTransformRules Rules(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	NewEnhanced->AttachToComponent(GetMesh(), Rules, SocketName);
	NewEnhanced->SetWeaponOwner(this);
	UE_LOG(LogTemp, Warning, TEXT("2"));
	if (BaseWeapon)
	{
		BaseWeapon->SetActorHiddenInGame(true);
		BaseWeapon->SetActorEnableCollision(false);

	}
	UE_LOG(LogTemp, Warning, TEXT("3"));
	EnhancedWeapon = NewEnhanced;
	CurrentWeapon = NewEnhanced;
	bUsingEnhancedWeapon = true;

	if (Pickup->CurrentUses >= 0)
	{
		EnhancedRemainingUses = Pickup->CurrentUses;
	}
	else
	{
		EnhancedRemainingUses = Pickup->MaxUses;
	}
	UE_LOG(LogTemp, Warning, TEXT("Enhanced picked: %s, RemainingUses=%d"),
		*NewEnhanced->GetName(), EnhancedRemainingUses);

	
}
//강화 무기 공격 횟수 구현
void AActionCharacter::ConsumeEnhancedWeaponUse()
{
	// 현재 들고있는 무기가 강화 무기가 아니라면
	if (!bUsingEnhancedWeapon)
	{
		return;
	}
	//남은 사용 횟수가 0이하라면 
	if (EnhancedRemainingUses <= 0)
	{
		return;
	}
	EnhancedRemainingUses = EnhancedRemainingUses - 1;
	UE_LOG(LogTemp, Warning, TEXT("강화무기 남은 공격 횟수 : %d"), EnhancedRemainingUses);

	// 다썼으면 이제 기본 무기로 가야지
	if (EnhancedRemainingUses <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("강화무기 남은 공격 횟수가 없습니다 : 기본무기 변환"));
		if (CurrentWeapon && CurrentWeapon != BaseWeapon)
		{
			CurrentWeapon->AttackEnable(false);
			CurrentWeapon->Destroy();
			CurrentWeapon = nullptr;
		}

		if (BaseWeapon)
		{
			BaseWeapon->SetActorHiddenInGame(false);
			BaseWeapon->SetActorEnableCollision(true);
			CurrentWeapon = BaseWeapon;
		}
		bUsingEnhancedWeapon = false;
		

	}
}

void AActionCharacter::DropWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("DropWeapon 호출됨"));

	// 1) 강화 무기 안 들고 있으면 바로 리턴
	if (!bUsingEnhancedWeapon || !EnhancedWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("DropWeapon: 강화 무기 없음"));
		return;
	}

	// 2) 드롭용 픽업 베이스 클래스 체크 (BP_WeaponPickUp_Base)
	if (!WeaponPickupClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("DropWeapon: WeaponPickupClass 없음 (BP에서 설정 안 됨)"));
		return;
	}

	// 3) 스폰 위치: 캐릭터 앞 + 살짝 위
	const FVector Forward = GetActorForwardVector();
	const FVector SpawnLocation =
		GetActorLocation()
		+ Forward * 150.0f            // 👉 앞으로 많이 띄워서 캐릭터랑 안 겹치게
		+ FVector(0.0f, 0.0f, 50.0f); // 위로 조금

	const FRotator SpawnRotation = GetActorRotation();

	FActorSpawnParameters Params;
	Params.Owner = this;

	// 4) 픽업 액터 스폰
	AWeaponPickUp* DroppedPickup = GetWorld()->SpawnActor<AWeaponPickUp>(
		WeaponPickupClass,
		SpawnLocation,
		SpawnRotation,
		Params
	);

	if (!DroppedPickup)
	{
		UE_LOG(LogTemp, Warning, TEXT("DropWeapon: 픽업 스폰 실패"));
		return;
	}
	//어떤무기 아이디인지 넘겨주기
	DroppedPickup->WeaponID = EnhancedWeapon->WeaponID;
	//드롭직후 무기세팅
	DroppedPickup->WeaponClass = EnhancedWeapon->GetClass();
	DroppedPickup->CurrentUses = EnhancedRemainingUses;
	//스택 최대 사용횟수
	DroppedPickup->StackValue = 1;
	DroppedPickup->MaxUses = EnhancedWeapon->DefaultMaxUses;

	//외형갱신
	DroppedPickup->RefreshVisualFromWeaponClass();

	UE_LOG(LogTemp, Warning, TEXT("DropWeapon: 픽업 스폰 성공: %s"), *DroppedPickup->GetName());

	// 5) 이 픽업이 어떤 무기인지 + 남은 사용횟수 전달
	DroppedPickup->WeaponClass = EnhancedWeapon->GetClass();
	DroppedPickup->CurrentUses = EnhancedRemainingUses;

	UE_LOG(LogTemp, Warning, TEXT("DropWeapon: WeaponClass = %s, Remaining=%d"),
		*EnhancedWeapon->GetClass()->GetName(),
		EnhancedRemainingUses);

	// 6) (일단 테스트용으로) 강화무기만 없애고, 기본무기로 복귀
	EnhancedWeapon->Destroy();
	EnhancedWeapon = nullptr;
	bUsingEnhancedWeapon = false;
	EnhancedRemainingUses = 0;

	if (BaseWeapon)
	{
		CurrentWeapon = BaseWeapon;
		BaseWeapon->SetActorHiddenInGame(false);
		BaseWeapon->SetActorEnableCollision(false);
	}
	else
	{
		CurrentWeapon = nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("DropWeapon: 드롭 완료, 기본 무기로 복귀"));
}
//데미지 수신
float AActionCharacter::TakeDamage(
	float DamageAmount,
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	//기본처리
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	//실제로 데미지 들어가는지 확인용
	UE_LOG(LogTemp, Warning, TEXT("AActionCharacter::TakeDamage called! Damage=%.2f"), ActualDamage);

	if (Resource)
	{
		Resource->AddHealth(-ActualDamage);

		if (!Resource->IsAlive())
		{
			UE_LOG(LogTemp, Warning, TEXT("지뢰밟고 죽어버림"));
		}
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("뭔가 없는데?"));
	}
	return ActualDamage;

}

void AActionCharacter::AddWeaponToInventory(FName InWeaponID, int32 Amount)
{
	if (Amount <= 0)
	{
		return;
	}

	int32& StoredAmount = WeaponInventory.FindOrAdd(InWeaponID);
	StoredAmount += Amount;

	UE_LOG(LogTemp, Warning, TEXT("Inventory [%s] = %d"), *InWeaponID.ToString(), StoredAmount);
	ReFreshAllQuickSlotsUI();
}

void AActionCharacter::SelectQuickSlot(int32 SlotIndex)
{

	
	if (SlotIndex < 0 || SlotIndex >= QuickSlotIDs.Num())
	{
		return;// 이상한 숫자가 입력되 크래쉬 되는걸 방지하는 함수
	}

	const FName WeaponID = QuickSlotIDs[SlotIndex];
	if (WeaponID.IsNone())
	{
		UE_LOG(LogTemp, Warning, TEXT("퀵슬롯이 %d 가비어있으"), SlotIndex + 1);
		return;
	}

	int32* FoundAmount = WeaponInventory.Find(WeaponID);
	if (!FoundAmount || *FoundAmount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("퀵슬롯 %d: %s 재고 없음"), SlotIndex + 1, *WeaponID.ToString());
		return;
	}

	// 지금 들고 있는 강화무기 인벤토리로 돌려놓기
	if (bUsingEnhancedWeapon && CurrentWeapon && CurrentWeapon != BaseWeapon)
	{
		AddWeaponToInventory(CurrentWeapon->WeaponID, 1); // 한자루는 아이템 1개
		CurrentWeapon->AttackEnable(false);
		CurrentWeapon->Destroy();
		CurrentWeapon = nullptr;
		bUsingEnhancedWeapon = false;
	}

	// 인벤토리에서 1개 소비한다.
	(*FoundAmount) -= 1;

	//새 강화무기 스폰
	TSubclassOf<AWeaponActor>* FoundClass = WeaponClassMap.Find(WeaponID);
	if (!FoundClass || !(*FoundClass))
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaponClassMap에 %s 없음"), *WeaponID.ToString());
		return;
	}

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.Instigator = this;

	AWeaponActor* NewEnhanced = GetWorld()->SpawnActor<AWeaponActor>
		(*FoundClass,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			Params
		);

	if (!NewEnhanced)
	{
		UE_LOG(LogTemp, Warning, TEXT("QuickSlot 스폰실패"));
		(*FoundAmount) += 1;
		return;
	}

	const FName SocketName = TEXT("hand_r_Socket");
	FAttachmentTransformRules Rules(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true
	);

	NewEnhanced->AttachToComponent(GetMesh(), Rules, SocketName);
	NewEnhanced->SetWeaponOwner(this);

	if (BaseWeapon)
	{
		BaseWeapon->SetActorHiddenInGame(true);
		BaseWeapon->SetActorEnableCollision(false);
	}

	EnhancedWeapon = NewEnhanced;
	CurrentWeapon = NewEnhanced;
	bUsingEnhancedWeapon = true;

	EnhancedRemainingUses = NewEnhanced->DefaultMaxUses;

	CurrentQuickSlotIndex = SlotIndex;

	ReFreshAllQuickSlotsUI();
}

FName AActionCharacter::GetQuickSlotID(int32 SlotIndex) const
{
	if (SlotIndex < 0 || SlotIndex >= QuickSlotIDs.Num())
	{
		return NAME_None;
	}
		return QuickSlotIDs[SlotIndex];
}

int32 AActionCharacter::GetQuickSlotStack(int32 SlotIndex) const
{
	if (SlotIndex < 0 || SlotIndex >= QuickSlotIDs.Num())
	{
		return 0;
	}

	const FName WeaponID = QuickSlotIDs[SlotIndex];
	if (WeaponID.IsNone())
	{
		return 0;
	}

	const int32* FoundAmount = WeaponInventory.Find(WeaponID);
	return FoundAmount ? *FoundAmount : 0;
}

void AActionCharacter::ReFreshAllQuickSlotsUI()
{
	if (!HUDWidget)
	{
		return;
	}

	const int32 NumSlots = QuickSlotIDs.Num();

	for (int32 i = 0; i < NumSlots; ++i)
	{
		const int32 Stack = GetQuickSlotStack(i);
		const bool bSelected = (i == CurrentQuickSlotIndex);

		HUDWidget->UpdateQuickSlot(i, Stack, bSelected);
	}
}