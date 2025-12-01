// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()// - c++ 클래스를 언리얼 엔진의 객체 시스템에 등록(= UObject)
		// - 
class SUBSTUDY_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Test_NormalFuntion();

	UFUNCTION(BlueprintCallable, Category = "내 함수") // c++로 작성한 함수를 블루프린트에서 호출가능
	void Test_UFuntion();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "내함수") // c++에서 선언만 하고 구현은 블루 프린트 (기획자가 야랄할때 자주 사용)

	void Test_ImplementableFuntion();

	//BlueprintNativeEvent : c++ 에서 구혀은 했는데 블루 프린트에서 재정의 하고 싶은경우
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "내함수")

	void Test_NativeEventFunction();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
