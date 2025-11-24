// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MineActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UNiagaraSystem;



UCLASS()
class KI_UNREALCPP_API AMineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTriggerBeginOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MineMesh;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Trigger;

	UPROPERTY(VisibleAnywhere, Category = "Mine")
	USceneComponent* ExplosionPoint;

	UPROPERTY(EditAnywhere, Category = "Mine")
	UNiagaraSystem* ExplosionFX;

	UPROPERTY(EditAnywhere, Category = "Mine")
	float Damage = 20.0f;

	bool bExploded = false;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
