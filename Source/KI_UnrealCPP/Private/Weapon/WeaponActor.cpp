// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponActor.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/ActionCharacter.h"
#include "NiagaraComponent.h"
#include "StatusComponent.h"



void AWeaponActor::OnWeaponBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	//UE_LOG(LogTemp, Warning, TEXT("OnWeaponBeginOverlap: this=%p, bAttackCollisionActive=%d, Other=%s"),
	//	this,
	//	bAttackCollisionActive ? 1 : 0,
	//	OtherActor ? *OtherActor->GetName() : TEXT("None"));

	if (!bAttackCollisionActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap ignored (not attacking)"));
		return;
	}

	if (!OtherActor || OtherActor == this)
		return;

	float finalDamage = Damage;
	AController* instigator = nullptr;

	if (WeaponOwner.IsValid())
	{
		if (WeaponOwner == OtherActor)
			return;

		finalDamage += WeaponOwner->GetAttackPower();
		instigator = WeaponOwner->GetController();
	}

	UE_LOG(LogTemp, Warning, TEXT("ApplyDamage! Damage=%f, Target=%s"),
		finalDamage,
		*OtherActor->GetName());

	UGameplayStatics::ApplyDamage(OtherActor, finalDamage, instigator, this, DamageType);
}
// Sets default values
AWeaponActor::AWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(root);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetupAttachment(root);
	WeaponMesh->SetCollisionProfileName(TEXT("NoCollision"));

	WeaponCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	WeaponCollision->SetupAttachment(WeaponMesh);

	// 디버그용
	WeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	WeaponCollision->SetCollisionObjectType(ECC_WorldDynamic);
	WeaponCollision->SetCollisionResponseToAllChannels(ECR_Overlap);  // ← 일단 전부 오버랩
	WeaponCollision->SetGenerateOverlapEvents(true);

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComp"));
	NiagaraComp->SetupAttachment(WeaponMesh);
	NiagaraComp->bAutoActivate = true;
	NiagaraComp->SetRelativeLocation(FVector::ZeroVector);
}





// Called when the game starts or when spawned
void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("WeaponActor BeginPlay")); // ✅ 테스트용

	if (WeaponCollision)
	{
		WeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponActor::OnWeaponBeginOverlap);
		UE_LOG(LogTemp, Warning, TEXT("Overlap delegate bound")); // ✅ 바인딩 확인용
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WeaponCollision is nullptr!!"));
	}
	
}

void AWeaponActor::AttackEnable(bool bEnable)
{

	if (!WeaponCollision)
		return;

	UE_LOG(LogTemp, Warning, TEXT("AttackEnable: %s"), bEnable ? TEXT("True") : TEXT("False")); // ✅ 추가
	bAttackCollisionActive = bEnable;

	if (bEnable)
	{
		WeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	
}

void AWeaponActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// CDO(Class Default Object)의 설정대로 초기화 된 이후( = OverlapOnlyPawn 설정 이후)
	//WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

