#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponActor.generated.h"

// ====== 전방 선언 ======
class AActionCharacter;
class USkeletalMeshComponent;
class UCapsuleComponent;
class UNiagaraComponent;

UCLASS()
class KI_UNREALCPP_API AWeaponActor : public AActor
{
    GENERATED_BODY()

public:
    AWeaponActor();

    USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
    UNiagaraComponent* GetNiagaraComp() const { return NiagaraComp; }
    TSubclassOf<class AWeaponPickUp> GetPickupClass() const { return PickupClass; }

    UFUNCTION(BlueprintCallable)
    void AttackEnable(bool bEnable);

    virtual void PostInitializeComponents() override;

    UFUNCTION(BlueprintCallable)
    inline void SetWeaponOwner(AActionCharacter* InOwner) { WeaponOwner = InOwner; }

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup")
    TSubclassOf<class AWeaponPickUp> PickupClass;

    UFUNCTION(BlueprintCallable, Category = "Weapon|AOE")
    void PerformAOEAttack();

    //인벤토리

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    FName WeaponID = TEXT("DefaultWeapon");

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
    int32 StackValue = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    int32 DefaultMaxUses = 10;


protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnWeaponBeginOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );


    // ====== 컴포넌트 ======
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USkeletalMeshComponent> WeaponMesh = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UCapsuleComponent> WeaponCollision = nullptr;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<UNiagaraComponent> NiagaraComp = nullptr;


   

    // ====== 데이터 ======
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
    float Damage = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
    TSubclassOf<UDamageType> DamageType = nullptr;

    // ====== 내부 상태 ======
    TWeakObjectPtr<AActionCharacter> WeaponOwner = nullptr;

    bool bAttackCollisionActive = false;

    // ====== 3타 범위공격 ======

    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon|AOE")
    bool bUseAOE = true; // 이무기가 AOE를 쓸지 여부

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|AOE", meta = (ClampMin = "0.0"))
    float AOERadius = 300.0f; //범위 반경

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon|AOE", meta = (ClampMin = "0.0"))
    float AOEDamage = 20.0f;  // 범위딜
};