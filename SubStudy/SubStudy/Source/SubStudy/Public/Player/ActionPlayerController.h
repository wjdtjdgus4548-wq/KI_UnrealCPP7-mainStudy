// Fill out your copyright notice in the Description page of Project Settings.



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"        // 🔹 EnhancedInput 헤더들
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ActionPlayerController.generated.h"

class UInputMappingContext; // UInputMappingContext 걍 이런놈이 있다 고 알려만줌 딱히 기능은 없음..;
class UInputAction;
/**
 * 
 */
UCLASS()
class SUBSTUDY_API AActionPlayerController : public APlayerController
{
	GENERATED_BODY()
	//UInputMappingContext a;요따구론 안됨; 전방선언 떄리삐면 헤더가 없응께 인스턴스를 못만듬;
	//UInputMappingContext* b; 이건 어짜피 포인터 주소라 상관은 없음 어차피 모든 타입이 주소 크기는 같으니까

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupInputComponent() override;

private:
	void OnLookInput(const FInputActionValue& Invalue);

protected:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext>DefaultMappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")

	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Pitch")
	float ViewPitchMin = -40;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera|Pitch")
	float ViewPitchMax = 30;


private:
	int32 GameInputPriorty = 1;

};
