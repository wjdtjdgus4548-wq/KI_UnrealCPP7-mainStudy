// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Player/ActionCharacter.h"
#include "AnimNotifyState_AttackEnable.generated.h"

/**
 *
 */
UCLASS()
class KI_UNREALCPP_API UAnimNotifyState_AttackEnable : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(
		USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		float TotalDuration,
		const FAnimNotifyEventReference& EventReference) override;

	virtual void NotifyEnd(
		USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		const FAnimNotifyEventReference& EventReference) override;
protected:
	// 소유자 캐릭터
	TWeakObjectPtr<AActionCharacter> OwnerCharacter;
	// 칼궤적 나이아가라 에셋
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttackTail")
	UNiagaraSystem* SwordTrailSystem = nullptr;

	//실제로 스폰된 나이아가라 컴포넌트
	TWeakObjectPtr<UNiagaraComponent> SpawnedTrail;

	//붙일 소켓 이름
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AttackTrail")
	FName TrailSocketName = TEXT("TrailSocket");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraShake")
	TSubclassOf<UCameraShakeBase> CameraShakeClass;

private:
	
};
