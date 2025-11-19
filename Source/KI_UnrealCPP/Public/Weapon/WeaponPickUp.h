// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h" 
#include "WeaponPickUp.generated.h"


class USphereComponent;
class USaticMeshComponent;
class AWeaponActor;

UCLASS()
class KI_UNREALCPP_API AWeaponPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponPickUp();
	
	
	void RefreshVisualFromWeaponClass();

protected:
	//겹침 감지
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent>PickUpMesh = nullptr;
	// 바닥에 보이는 메쉬(무기 외형을 따라감)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class USphereComponent>PickUpCollision = nullptr;
	// 픽업용 나이아가라이펙트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UNiagaraComponent>PickUpNiagara = nullptr;
public:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Pickup")
	TSubclassOf<class AWeaponActor> WeaponClass;

	

public:
	// 어떤 무기를 줄 건지 (강화무기 BP를 넣을 예정)
	

	// 무기 타입 구분용 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	FName WeaponId = "Default";

	// 이 무기를 줍으면 채워줄 최대 회수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	int32 MaxUses = 0;

	// 남은 회수(드랍된 무기 다시 줍는 용도, 처음엔 -1로 두고 MaxUses 사용)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
	int32 CurrentUses = -1;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPickupOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult

	);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//마크같이 무기 세우기, 위아래로 움직임 , 오른쪽으로 회전시키기부분

protected:
	

	//시작 위치 저장
	FVector StartLocation;

	//시간 누적
	float RunningTime = 0.0f;

	//위 아래로 움직이는 크기
	UPROPERTY(EditAnywhere, Category = "Floating")
	float BobAmplitude = 20.0f;

	//위 아래로 움직이는 속도
	UPROPERTY(EditAnywhere, Category = "Floating")
	float BobSpeed = 2.0f;

	// 회전속도
	UPROPERTY(EditAnywhere, Category = "Flaoting")
	float RotationSpeed = 45.0f;

	UPROPERTY(EditAnywhere,Category = "Flaoting")
	float TiltRoll = 0.0f; // 좌우 기울기
	UPROPERTY(EditAnywhere,Category = "Flaoting")
	float TiltPitch = -25.0f; // 앞뒤로 살짝 숙이기


protected:
	//흡입 가능 체크
	bool bIsAbsorbing = false;

	//타겟 캐릭터
	TWeakObjectPtr<class AActionCharacter> TargetCharacter = nullptr;

	//흡입시간, 시작위치
	FVector AbsorbStartLocation;
	float AbsorbElapsedTime = 0.0f;

	//흡입하는데 걸리는 시간
	UPROPERTY(EditAnywhere, Category = "Absorb")
	float AbsorbDuration = 0.25f;

	//플레이어의 몸통 쯤으로 빨려들어가게 오프셋
	UPROPERTY(EditAnywhere, Category = "Absorb")
	float AbsorbHeightOffset = 50.0f;



	

};
