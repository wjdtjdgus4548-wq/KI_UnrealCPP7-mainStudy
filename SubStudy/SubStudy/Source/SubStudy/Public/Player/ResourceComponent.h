// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/ActionCharacter.h"
#include "ResourceComponent.generated.h"

//DELEGATE 
// 그냥 Delegate vs Dynamic Delegate
// - Dynamic Delegate는 블루프린트  사용가능
// - 일반 델리게이트보다 좀 느림;
// - Dynamic Delegate 에는 람다식 추가가 불가능함
// - Dynamic Delegate 에 바인딩 되는 함수는 UFUNTION 으로 선언되어야 함 (블루프린트에서 사용가능 하니까)
// 그냥 Delegate vs MulticastDelegate
// - MulticastDelegate 는 여러 리스너를 바인딩 할 수 있음 이름 부터가 멀티케스트 니깐
// 그냥 Delegate vs Event Delegate
// - Event Delegate 는 외부에서 바인딩만 가능함
// - 델리게이트는 외부에서 바인딩과 실행 모두 가능함
// 선언은 클래스 외부에서 선언한다

//DECLARE_DELEGATE
//DECLARE_DYNAMIC_DELEGATE
//DECLARE_MULTICAST_DELEGATE
//DECLARE_DYNAMIC_MULTICAST_DELEGATE
//DECLARE_DELEGATE_RetVal
//DECLARE_DELEGATE_RetVal_OneParam

//걍 FOnStaminaEmpty 이름의 델리게이트가 있음을 선언한것뿐임
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStaminaEmpty);

//사망 알림용
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDie);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStaminaChanged, float, Current, float, Max); //스태미너 변경 알림용
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, float); // 채룍 변경 알림용

UCLASS( BluePrintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBSTUDY_API UResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResourceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	//스태미너 추가 함수
	UFUNCTION(BlueprintCallable)
	void AddStamina(float InValue);
	//스태미너 잔량 확인 함수
	UFUNCTION(BlueprintCallable, BlueprintPure)
	inline bool HasEnoughStamina(float InValue){ return CurrentStamina >= InValue; }
	//체력 추가 함수
	UFUNCTION(BlueprintCallable)
	void AddHealth(float InValue);

	//사망을 알리는 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnDie OnDie;

	inline bool IsAlive() { return CurrentHealth >= 0; };


	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnStaminaEmpty OnStaminaEmpty;

	//스태미너 변화를 알리는 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnStaminaChanged OnStaminaChanged;

	//체력 변화를 알리는 델리게이트(일반 델리게이트는 블루프린트에서 안됨)
	FOnHealthChanged OnHealthChanged;

	
private:
	void StaminaAutoRegenCoolTimerSet();
	void StaminaRegenPerTick();

	inline void SetCurrentHealth(float InValue)
	{
		CurrentHealth = InValue;
		OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	};
	void SetCurrentStamina(float InValue)
	{
		CurrentStamina = InValue;
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
	};

protected:

	//현제 체력 최대체력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Health")
	float CurrentHealth = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Health")
	float MaxHealth = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Stamina")
	float CurrentStamina = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data|Stamina")
	float MaxStamina = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data|Stamina")//몇초뒤부터 회복 시작할건지
		float StaminaRegenCoolTime = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data|Stamina")//초당 스태미나 회복량
		float StaminaRegenAmount = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data|Stamina")//틱당 스태미나 회복량
		float StaminaRegenAmountByTick = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data|Stamina")//틱당 스태미나 회복퍼센트
		float StaminaRegenRateByTick = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data|Stamina")
	float StaminaTickInterval = 0.1f;
private:
	//float TimeSinceLastStaminaUse = 0.0f;
	FTimerHandle StaminaAutoRegenCoolTimer; // 스테미너 자동 회복용 타이머 핸들
	FTimerHandle StaminaRegenTickTimer; //스테미너 자동 회복 시 틱별 타이머 핸들 
	
		
};
