// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/FloatingActor_Curve.h"


void AFloatingActor_Curve::OnFloatingMeshUpdate(float DeltaTime)
{
	if (HeightCurve)
	{
		//커브가 있음

		ElapsedTime += DeltaTime;

		float curveInput = FMath::Fmod(ElapsedTime / Duration,1.0f); // 0.0~1.0사이의 범위 숫자로 반복하게 함
		float curveValue = HeightCurve->GetFloatValue(curveInput);

		
		BodyMesh->SetRelativeLocation(FVector(0, 0, curveValue * MoveHeight));
		BodyMesh->AddRelativeRotation(FRotator(0, SpinSpeed * DeltaTime, 0));
	}
	else
	{
		Super::OnFloatingMeshUpdate(DeltaTime);
	}
	
};
