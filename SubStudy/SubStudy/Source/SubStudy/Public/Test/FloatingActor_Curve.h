// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Test/FloatingActor.h"
#include "FloatingActor_Curve.generated.h"

/**
 * 
 */
UCLASS()
class SUBSTUDY_API AFloatingActor_Curve : public AFloatingActor
{
	GENERATED_BODY()

protected:
	//스테틱메시 움직임 업데이트 하는 함수
	virtual void OnFloatingMeshUpdate(float DeltaTime) override;

public:
	//높이 움직임을 결정할 커브
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCurveFloat> HeightCurve = nullptr;

	//커브 한주기 동안의 시간
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Duration = 5.0f;
};
