// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/LaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ALaunchPad::ALaunchPad() //생성자
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; // 이건 왜 끈지 모르겠음 나중에 설명 ㄱ

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root")); //루트에 신컴포넌트 생성
		SetRootComponent(Root); // 루트 컴포턴트를 루트로 지정

		PadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PadMesh")); // 스테틱매쉬 컴포넌트 지정 이름을 패드매쉬로 
		PadMesh->SetupAttachment(Root); // 패드매쉬에 정한 스태틱매쉬를 루트에 어태치

		PadMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // 패드매쉬에 콜리전 세팅


		LaunchBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LaunchBox"));// 박스 컴포넌트 설정  이름을 런치박스로 설정
		LaunchBox->SetupAttachment(Root); // 루트에 어태치
		LaunchBox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));// 박스 컴포넌ㅌ 크기 설정


		LaunchBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);// 런치박스 쿼리 온리로 설정(근데 쿼리가 뭔지 잊어버림)
		LaunchBox->SetCollisionObjectType(ECC_WorldDynamic);//월드에서 콜리전의 오브젝트 타입을 뭘로할지 설정 월드다이나믹으로 함
		LaunchBox->SetCollisionResponseToAllChannels(ECR_Ignore); // 아마 물리 무시아닌가? 콜리전이 캐릭터와 부딛히지 않게 설정(아니다 밑에거 보니까 저거네 일단 월드전체에서 충돌을 끈거임)
		LaunchBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); // 위에서 월드 전체 충돌 껐으니까 여기서 오버랩 됬을때 누가 효과를 받을지 설정

		LaunchBox->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OnLaunchBoxOverlap);// 오버랩 컴포넌트가 오버랩됬을때? 이거 이따가 자세히 설명좀

}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaunchPad::OnLaunchBoxOverlap( // 런치패드 랑 오버랩 됬을때 무슨 조건으로 발동시키나 조건인가? 이거도 이따가 설명좀
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (!OtherActor) // 액터가 아니면 무시
	{
		return;
	}

	ACharacter* Character = Cast<ACharacter>(OtherActor);//캐릭터액터 포인터주소에 있는 캐릭터 캐스팅
	if (!Character) // 캐릭터가 아니면 무시
	{
		return;
	}

	FVector MoveDir = Character->GetVelocity(); // 백터값이 캐릭터가 움직이고 있는방향을 받음

	if (MoveDir.SizeSquared() < 1.0f) // 움직이는 속도가 너무 적으면 이상하게 작동하니까 걍 설정된방향으로 작동되게함
	{
		MoveDir = GetActorForwardVector();
	}

	MoveDir = MoveDir.GetSafeNormal();// 이건 시발 모르겠는데

	const FVector Up = FVector::UpVector; //위로 날리는 힘을 고정시킴? 이것도 잘 몰?루

	FVector LaunchVelocity = MoveDir * LaunchStrength + Up * LaunchUpStrength; // 날릴방향과 힘 계산

	UE_LOG(LogTemp, Warning, TEXT("LaunchPad: %s 를 날립니다. Dir=%s Vel=%s"),
		*Character->GetName(), *MoveDir.ToString(), *LaunchVelocity.ToString());


	Character->LaunchCharacter( // 이것도 잘 몰?루 
		LaunchVelocity,
		true,
		true
		);
}

