// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATestEnemy::ATestEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	Mesh->SetCollisionProfileName(TEXT("Pawn"));
	Mesh->SetGenerateOverlapEvents(true);

	MaxHp = 100.0f;
	CurrentHp = MaxHp;
}

// Called when the game starts or when spawned
void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

float ATestEnemy::TakeDamage(
	float DamageAmount,
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser
)
{

	const float ActualDamage = Super::TakeDamage(
		DamageAmount, 
		DamageEvent, 
		EventInstigator, 
		DamageCauser
	);

	if (ActualDamage <= 0.0f)
	{
		return 0.0f;
	}

	CurrentHp = CurrentHp - ActualDamage;

	UE_LOG(LogTemp, Log, TEXT("TestEnemy HP : %f"), CurrentHp);

	if (CurrentHp <= 0.0f)
	{
		Die();
	}
	return ActualDamage;
}

void ATestEnemy::Die()
{
	UE_LOG(LogTemp, Warning, TEXT("TestEnemy Dead -> Destroy"));
	Destroy();
}

