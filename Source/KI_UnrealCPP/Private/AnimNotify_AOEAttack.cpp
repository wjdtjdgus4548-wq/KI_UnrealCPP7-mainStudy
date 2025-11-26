// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AOEAttack.h"
#include "Player/ActionCharacter.h"
#include "Weapon/WeaponActor.h"

void UAnimNotify_AOEAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	if (!MeshComp) return;

	AActionCharacter* OwnerChar = Cast<AActionCharacter>(MeshComp->GetOwner());
	if (!OwnerChar)
	{
		return;
	}

	AWeaponActor* Weapon = OwnerChar->GetCurrentWeapon();
	if (!Weapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("AOENotify : CurrentWeapon없음"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AOENotify 실행 → 무기 AOE 호출"));
	Weapon->PerformAOEAttack();
}