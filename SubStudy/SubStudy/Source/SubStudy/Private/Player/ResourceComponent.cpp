// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ResourceComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UResourceComponent::UResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UResourceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//초기화 안하면 븅신같아지니 한번 하는 습관 들이기
	SetCurrentHealth(MaxHealth);
	SetCurrentStamina(MaxStamina);

	
	
}


// Called every frame


void UResourceComponent::StaminaAutoRegenCoolTimerSet()
{

	UE_LOG(LogTemp, Warning, TEXT("World OK, setting timer..."));
	UWorld* world = GetWorld();
	FTimerManager& timerManager = world->GetTimerManager();
	timerManager.SetTimer(
		StaminaAutoRegenCoolTimer,
		[this]() {
			//bRegenStamina = true;
			UE_LOG(LogTemp, Log, TEXT("타이머 스태미나 리젠"));

			UWorld* world = GetWorld();
			FTimerManager& timerManager = world->GetTimerManager();

			timerManager.SetTimer(
				StaminaRegenTickTimer,
				this,
				&UResourceComponent::StaminaRegenPerTick,
				StaminaTickInterval,		//실행간격
				true,		//반복재생 할거임?
				StaminaTickInterval);		//실행될 때 딜레이
		},
		StaminaRegenCoolTime,
		false);
}

void UResourceComponent::StaminaRegenPerTick()
{
	float stamina = CurrentStamina + StaminaRegenAmountByTick;

	stamina = FMath::Clamp(stamina, 0.0f, MaxStamina);
	
	if (stamina > MaxStamina)
	{
		stamina = MaxStamina;

		UWorld* world = GetWorld();
		FTimerManager& timerManager = world->GetTimerManager();
		timerManager.ClearTimer(StaminaRegenTickTimer);
	}
	//UE_LOG(LogTemp, Log, TEXT("스태미나 리젠 : %.1f"), CurrentStamina)

	SetCurrentStamina(stamina);

}

void UResourceComponent::AddStamina(float InValue)
{
	//TimeSinceLastStaminaUse = 0; // 디버깅용; 시간 직접 제어

	//스태미너를 소비하고 일정 시간 뒤에 자동재생되게 타이머 세팅
	StaminaAutoRegenCoolTimerSet();
	
	SetCurrentStamina(FMath::Clamp(CurrentStamina + InValue, 0, MaxStamina));

	if (CurrentStamina <= 0)
	{
		//델리게이트로 스테미너가 떨어졌음을 알림
		OnStaminaEmpty.Broadcast();
	}
}

void UResourceComponent::AddHealth(float InValue)
{
	float health = CurrentHealth + InValue;
	SetCurrentHealth(FMath::Clamp(health, 0, MaxHealth));

	if (IsAlive())
	{
		OnDie.Broadcast();
	}

}


