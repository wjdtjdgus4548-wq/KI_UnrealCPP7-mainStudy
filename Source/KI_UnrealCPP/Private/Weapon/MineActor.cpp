// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/MineActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/ActionCharacter.h"

// Sets default values
AMineActor::AMineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//루트에 서브오브젝트 생성  이름을 루트라고 지정 루트 컴포넌트 설정
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//지뢰의 메쉬 이름은 마인메쉬 루트 컴포넌트에 붙임
	MineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MineMesh"));
	MineMesh->SetupAttachment(Root);

	// 트리거 이름은 트리거로 짓고 구의 반지름은 80짜리 루트에 붙임
	Trigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Root);
	Trigger->InitSphereRadius(80.0f);

	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Trigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	Trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ExplosionPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ExplosionPoint"));
	ExplosionPoint->SetupAttachment(Root);
	ExplosionPoint->SetRelativeLocation(FVector(0.0f, 0.0f, 20.0f));;

}

// Called when the game starts or when spawned
void AMineActor::BeginPlay()
{
	Super::BeginPlay();

	if (Trigger)
	{
		Trigger->OnComponentBeginOverlap.AddDynamic(
			this, &AMineActor::OnTriggerBeginOverlap);
	}
	
}

// Called every frame
void AMineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMineActor::OnTriggerBeginOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Mine Overlap Triggered: Other=%s"),
		*OtherActor->GetName());
	if (bExploded)
	{
		return;
	}

	if (!OtherActor || OtherActor == this)
	{
		return;
	}

	AActionCharacter* Player = Cast<AActionCharacter>(OtherActor);
	if (!Player)
	{
		return;
	}else if (Cast<AActionCharacter>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player detected!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap but not Player: %s"), *OtherActor->GetName());
	}

	bExploded = true;

	UGameplayStatics::ApplyDamage(
		Player,
		Damage,
		nullptr,
		this,
		nullptr
	);
	UE_LOG(LogTemp, Warning, TEXT("Applying Damage: %f to %s"),
		Damage, *Player->GetName());
	if (ExplosionFX)
	{
		const FVector SpawnLoc = ExplosionPoint
			? ExplosionPoint->GetComponentLocation()
			: GetActorLocation();

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			ExplosionFX,
			SpawnLoc,
			GetActorRotation()
		);
	}

	
	MineMesh->SetVisibility(false, true);
	MineMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Trigger->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	

	SetLifeSpan(2.0f);

}

