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

	

};
