// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/TestActor.h"



// Sets default values
ATestActor::ATestActor() // 생성자
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	//super: 부모클래스
	Super::BeginPlay(); // 부모 클래스의 beginPlay를 실행해라.

	UE_LOG(LogTemp, Log, TEXT("헬로우 씌뽕빵"));
	UE_LOG(LogTemp, Warning, TEXT("헬로우 씌뽕빵"));
	UE_LOG(LogTemp, Error, TEXT("헬로우 씌뽕빵"));
	
}

void ATestActor::Test_NormalFuntion()
{
	UE_LOG(LogTemp, Log, TEXT("테스트 펑션 호출"));
}

void ATestActor::Test_UFuntion()
{
	UE_LOG(LogTemp, Log, TEXT("U 펑션 호출"));
}

void ATestActor::Test_NativeEventFunction_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Test_NativeEventFunction_Implementation 펑션 호출"));
	//Implementation 뒤에 이거 붙여줘야함 ;;, 근대 다른 곳에서 호출할때는 Test_NativeEventFunction이거만 사용
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

