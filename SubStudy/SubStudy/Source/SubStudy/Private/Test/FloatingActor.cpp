// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);//루트로 지정해줌

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(root);

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFloatingActor::OnFloatingMeshUpdate(float DeltaTime)
{

	ElapsedTime += DeltaTime; // 시간누적


	//Cos
	//1 -> -1 -> 1 이 됨 근데 우린 0 -> 1- > 0 이렇게 해주고 싶음
	float cosValue = FMath::Cos(ElapsedTime * 2);
	cosValue += 1;			 // 2 - 0 - 2
	cosValue *= 0.5f;		 // 1 - 0 - 1
	cosValue = 1 - cosValue; // 0 - 1 - 0


	BodyMesh->SetRelativeLocation(FVector(0, 0, cosValue * MoveHeight)); // 위치

	BodyMesh->AddRelativeRotation(FRotator(0, SpinSpeed * DeltaTime, 0)); // 회전
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OnFloatingMeshUpdate(DeltaTime);
	/*
	BodyMesh->AddRelativeLocation(FVector::UpVector * DeltaTime * Speed);

	if (BodyMesh->GetRelativeLocation().Z > MoveHeight || BodyMesh->GetRelativeLocation().Z < 0)
	{
		Speed *= -1.0f;
	}
	*/

	

}

