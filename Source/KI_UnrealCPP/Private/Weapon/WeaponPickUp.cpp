// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/WeaponPickUp.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Player/ActionCharacter.h"
#include "Weapon/WeaponActor.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"


// Sets default values
AWeaponPickUp::AWeaponPickUp()
{
    PrimaryActorTick.bCanEverTick = false;

    PickUpCollision = CreateDefaultSubobject<USphereComponent>(TEXT("PickUpCollision"));
    SetRootComponent(PickUpCollision);

    PickUpMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PickUpMesh"));
    PickUpMesh->SetupAttachment(RootComponent);

    PickUpNiagara = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PickUpNiagara"));
    PickUpNiagara->SetupAttachment(PickUpMesh);   // 혹은 RootComponent
    PickUpNiagara->bAutoActivate = true;
}

void AWeaponPickUp::OnPickupOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult
)
{
    UE_LOG(LogTemp, Warning, TEXT("OnPickupOverlap fired! Other=%s"),
        OtherActor ? *OtherActor->GetName() : TEXT("None"));
    if (!OtherActor)
    {
        return;
    }

    AActionCharacter* ActionChar = Cast<AActionCharacter>(OtherActor);
    if (!ActionChar)
    {
        UE_LOG(LogTemp, Warning, TEXT("Overlap but not ActionCharacter"));
        return;
    }
    UE_LOG(LogTemp, Warning, TEXT("Calling OnPickupEnhancedWeapon"));
    ActionChar->OnPickUpEnhancedWeapon(this);

    Destroy();
}


// Called when the game starts or when spawned
void AWeaponPickUp::BeginPlay()
{

	Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Pickup BeginPlay: %s, WeaponClass=%s"),
        *GetName(),
        WeaponClass ? *WeaponClass->GetName() : TEXT("None"));

    if (PickUpCollision)
    {
        PickUpCollision->OnComponentBeginOverlap.AddDynamic(
            this, &AWeaponPickUp::OnPickupOverlap);
    }

    if (!WeaponClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Pickup: WeaponClass is NONE"));
        return;
    }

    AWeaponActor* DefaultWeapon = WeaponClass->GetDefaultObject<AWeaponActor>();
    if (!DefaultWeapon)
    {
        UE_LOG(LogTemp, Warning, TEXT("Pickup: DefaultWeapon is nullptr"));
        return;
    }

    
    USkeletalMeshComponent* WeaponMeshComp = DefaultWeapon->GetWeaponMesh();
    if (WeaponMeshComp && PickUpMesh)
    {
        if (PickUpMesh)
        {
            PickUpMesh->SetSkeletalMesh(WeaponMeshComp->GetSkeletalMeshAsset());

            PickUpMesh->SetRelativeLocation(WeaponMeshComp->GetRelativeLocation());
            PickUpMesh->SetRelativeRotation(WeaponMeshComp->GetRelativeRotation());
            PickUpMesh->SetRelativeScale3D(WeaponMeshComp->GetRelativeScale3D());
        }
    }

    UNiagaraComponent* NiagaraComp = DefaultWeapon->GetNiagaraComp();
    if (NiagaraComp && PickUpNiagara)
    {
        if (PickUpNiagara)
        {

            PickUpNiagara->SetAsset(NiagaraComp->GetAsset());

            PickUpNiagara->SetRelativeLocation(NiagaraComp->GetRelativeLocation());
            PickUpNiagara->SetRelativeRotation(NiagaraComp->GetRelativeRotation());
            PickUpNiagara->SetRelativeScale3D(NiagaraComp->GetRelativeScale3D());

            PickUpNiagara->Activate(true);
        }
    }

    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("Pickup: Niagara is nullptr (WeaponNiagara=%s, PickUpNiagara=%s)"),
            NiagaraComp ? TEXT("Valid") : TEXT("Null"),
            PickUpNiagara ? TEXT("Valid") : TEXT("Null"));
    }
   


}

// Called every frame
void AWeaponPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

