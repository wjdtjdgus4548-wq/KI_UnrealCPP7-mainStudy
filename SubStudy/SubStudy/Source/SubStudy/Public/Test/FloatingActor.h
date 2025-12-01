// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class SUBSTUDY_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//움직임 업데이트 함수
	virtual void OnFloatingMeshUpdate(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//이건 딱 보면 알지?
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)

	float SpinSpeed = 360.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveHeight = 300.0f;


protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BodyMesh = nullptr;

	float ElapsedTime = 0.0f;

};
 