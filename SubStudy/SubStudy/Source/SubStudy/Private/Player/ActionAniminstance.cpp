// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ActionAniminstance.h"
#include "GameFramework//PawnMovementComponent.h"


void UActionAniminstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* OwnerPawn = TryGetPawnOwner();

	if (OwnerPawn)
	{
		OwnerMovementComponent = OwnerPawn->GetMovementComponent();

	}
}

void UActionAniminstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
    APawn* OwnerPawn = TryGetPawnOwner();
    if (!OwnerPawn)
    {
        return; // Pawn 없으면 더 할 게 없으니 바로 종료
    }

    // 혹시 BeginPlay 전에 Initialize에서 못 잡았을 수도 있으니까 한 번 더 보정
    if (!OwnerMovementComponent.IsValid())
    {
        OwnerMovementComponent = OwnerPawn->GetMovementComponent();
    }

    if (OwnerMovementComponent.IsValid())
    {
        Speed = OwnerMovementComponent.Get()->Velocity.Size();
    }
	
}
