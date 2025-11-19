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
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;   // 🔥 시작부터 Tick 켜기
    SetActorTickEnabled(true);                       // 🔥 혹시 모르니 명시적으로

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
    
    if (!OtherActor)
    {
        return;
    }

    //이미 흡입중인지 체크
    if (bIsAbsorbing)
    {
        if (!TargetCharacter.IsValid())
        {
        return;

        }
    }

    AActionCharacter* ActionChar = Cast<AActionCharacter>(OtherActor);

    if (!ActionChar)
    {
        UE_LOG(LogTemp, Warning, TEXT("오버렙 하지만 액션캐릭터는 아님"));
        return;
    }
    //여기서 흡입모드로 전환시킴
    bIsAbsorbing = true;
    TargetCharacter = ActionChar;

    // 시작위치 저장
    AbsorbStartLocation = GetActorLocation();
    AbsorbElapsedTime = 0.0f;

    //더이상 다른것과 겹치지 않도록 충돌 끔
    if(PickUpCollision)
    {
        PickUpCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        PickUpCollision->SetGenerateOverlapEvents(false);
    }

    UE_LOG(LogTemp, Warning, TEXT("흡수 픽업 : %s"), *ActionChar->GetName());
    

    RefreshVisualFromWeaponClass();
}


// Called when the game starts or when spawned
void AWeaponPickUp::BeginPlay()
{

	Super::BeginPlay();
    //시작위치를 게임이 시작되자마자 저장시킴
    StartLocation = GetActorLocation();
    //대충 어디 던져놔도 z 좌표를 20 더하니까 대충 그럴싸한 위치에 떠있음
    StartLocation.Z = StartLocation.Z + 150.0f;



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

            PickUpMesh->SetRelativeLocation(FVector::ZeroVector);
            
            PickUpMesh->SetRelativeScale3D(WeaponMeshComp->GetRelativeScale3D());

            const FRotator SrcRot = WeaponMeshComp->GetRelativeRotation();

            FRotator TiltedRot(TiltPitch, SrcRot.Yaw, TiltRoll);

            PickUpMesh->SetRelativeRotation(TiltedRot);
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

    //흡입 중이라면: 플레이어 쪽으로 빨려들어가는 처리만 수행
    if (bIsAbsorbing)
    {
        // 타겟이 유효한지 체크
        if (!TargetCharacter.IsValid())
        {
            Destroy();
            return;
        }

        // 진행 시간 증가
        AbsorbElapsedTime += DeltaTime;

        // 0~1 사이의 진행도
        float Alpha = 0.0f;
        if (AbsorbDuration > 0.0f)
        {
            Alpha = AbsorbElapsedTime / AbsorbDuration;
        }
        Alpha = FMath::Clamp(Alpha, 0.0f, 1.0f);

        // 목표 위치 = 캐릭터 위치 + 오프셋
        FVector TargetLocation = TargetCharacter->GetActorLocation();
        TargetLocation.Z += AbsorbHeightOffset;

        // 위치 Lerp
        FVector AbsorbLocation = FMath::Lerp(AbsorbStartLocation, TargetLocation, Alpha);
        SetActorLocation(AbsorbLocation);

        // 스케일 줄이기
        float NewScaleValue = FMath::Lerp(1.0f, 0.0f, Alpha);
        SetActorScale3D(FVector(NewScaleValue));

        // 완료되면 아이템 지급 후 삭제
        if (Alpha >= 1.0f)
        {
            if (TargetCharacter.IsValid())
            {
                TargetCharacter->OnPickUpEnhancedWeapon(this);
            }

            Destroy();
        }

        return; //흡입 중이면 아래 떠다니기/회전 로직 건너뛰기
    }


    //흡입 중이 아닐 때는 "마크 아이템" 스타일로 둥둥 떠다니고 회전

    RunningTime += DeltaTime;

    float OffsetZ = FMath::Sin(RunningTime * BobSpeed) * BobAmplitude;

    FVector FloatLocation = StartLocation;
    FloatLocation.Z = StartLocation.Z + OffsetZ;
    SetActorLocation(FloatLocation);

    FRotator Rot = GetActorRotation();
    Rot.Yaw += RotationSpeed * DeltaTime;
    Rot.Pitch = 0.0f;
    Rot.Roll = 0.0f;
    SetActorRotation(Rot);
}

void AWeaponPickUp::RefreshVisualFromWeaponClass()
{
    if (!WeaponClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Pickup: WeaponClass is NONE in RefreshVisualFromWeaponClass"));
        return;
    }

    AWeaponActor* DefaultWeapon = WeaponClass->GetDefaultObject<AWeaponActor>();
    if (!DefaultWeapon)
    {
        UE_LOG(LogTemp, Warning, TEXT("Pickup: DefaultWeapon is nullptr"));
        return;
    }

    // 🔸 무기 메쉬 복사
    USkeletalMeshComponent* WeaponMeshComp = DefaultWeapon->GetWeaponMesh();
    if (WeaponMeshComp && PickUpMesh)
    {
        PickUpMesh->SetSkeletalMesh(WeaponMeshComp->GetSkeletalMeshAsset());

        PickUpMesh->SetRelativeLocation(FVector::ZeroVector);
        PickUpMesh->SetRelativeScale3D(WeaponMeshComp->GetRelativeScale3D());

        const FRotator SrcRot = WeaponMeshComp->GetRelativeRotation();
        FRotator TiltedRot(TiltPitch, SrcRot.Yaw, TiltRoll);
        PickUpMesh->SetRelativeRotation(TiltedRot);
    }

    // 🔸 나이아가라 복사
    UNiagaraComponent* NiagaraComp = DefaultWeapon->GetNiagaraComp();
    if (NiagaraComp && PickUpNiagara)
    {
        PickUpNiagara->SetAsset(NiagaraComp->GetAsset());
        PickUpNiagara->SetRelativeLocation(NiagaraComp->GetRelativeLocation());
        PickUpNiagara->SetRelativeRotation(NiagaraComp->GetRelativeRotation());
        PickUpNiagara->SetRelativeScale3D(NiagaraComp->GetRelativeScale3D());
        PickUpNiagara->Activate(true);
    }
    else
    {
        UE_LOG(LogTemp, Warning,
            TEXT("Pickup: Niagara is nullptr (WeaponNiagara=%s, PickUpNiagara=%s)"),
            NiagaraComp ? TEXT("Valid") : TEXT("Null"),
            PickUpNiagara ? TEXT("Valid") : TEXT("Null"));
    }
}
