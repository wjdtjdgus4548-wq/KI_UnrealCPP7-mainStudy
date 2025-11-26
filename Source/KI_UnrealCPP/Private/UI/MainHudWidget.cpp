// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainHudWidget.h"
#include "UI/ResourceBarWidget.h"      // 🔹 추가
#include "Player/ActionCharacter.h"    // 🔹 추가 (네 캐릭터 클래스)
#include "Player/ResourceComponent.h"  // 🔹 추가
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Components/Image.h"

void UMainHudWidget::NativeConstruct()
{
    Super::NativeConstruct();

    AActionCharacter* Player = Cast<AActionCharacter>(GetOwningPlayerPawn());

    if (!Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("HUDOwning 플러이어가 액션 캐릭터가 아님"))
            return;
    }

    UResourceComponent* Resource = Player->FindComponentByClass<UResourceComponent>();
    if (!Resource)
    {
        UE_LOG(LogTemp, Warning, TEXT("[HUD] ResourceComponent를 찾을 수 없음"));
        return;
    }

    Resource->OnHealthChanged.AddUObject(this, &UMainHudWidget::HandleHealthChanged);
    Resource->OnStaminaChanged.AddDynamic(this, &UMainHudWidget::HandleStaminaChanged);

    UE_LOG(LogTemp, Warning, TEXT("[HUD] ResourceComponent 델리게이트 바인딩 완료"));
    // 필요하면 여기서 초기화 코드 작성

    HandleHealthChanged(Resource->GetCurrentHealth(), Resource->GetMaxHealth());
    HandleStaminaChanged(Resource->GetCurrentStamina(), Resource->GetMaxStamina());
}

void UMainHudWidget::UpdateQuickSlot(int32 SlotIndex, int32 Stack, bool bSelected)
{
    UE_LOG(LogTemp, Warning, TEXT("HUD UpdateQuickSlot 호출됨 - Slot:%d, Stack:%d, Selected:%d"),
        SlotIndex, Stack, bSelected);
    // 슬롯별로 참조할 위젯 포인터 준비
    UBorder* TargetBorder = nullptr;
    UTextBlock* TargetText = nullptr;

    switch (SlotIndex)
    {
    case 0:
        TargetBorder = Slot0_Border;
        TargetText = Slot0_CountText;
        break;

    case 1:
        TargetBorder = Slot1_Border;
        TargetText = Slot1_CountText;
        break;

    case 2:
        TargetBorder = Slot2_Border;
        TargetText = Slot2_CountText;
        break;

    case 3:
        TargetBorder = Slot3_Border;
        TargetText = Slot3_CountText;
        break;

    default:
        // 잘못된 인덱스면 그냥 리턴
        UE_LOG(LogTemp, Error, TEXT("HUD UpdateQuickSlot: 잘못된 SlotIndex=%d"), SlotIndex);
    
        return;
    }
    // 개수 텍스트 갱신
    if (TargetText)
    {
        TargetText->SetText(FText::AsNumber(Stack));
        
    }
    

    // 선택 여부에 따라 테두리 색 변경
    if (TargetBorder)
    {
        const FLinearColor SelectedColor(1.0f, 1.0f, 1.0f, 1.0f);   // 노란 느낌
        const FLinearColor NormalColor(0.2f, 0.2f, 0.2f, 0.0f);     // 어두운 회색

        TargetBorder->SetBrushColor(bSelected ? SelectedColor : NormalColor);
    }
}

void UMainHudWidget::UpdateQuickSlotIcon(int32 SlotIndex, UTexture2D* IconTexture)
{
    UImage* TargetIcon = nullptr;

    switch (SlotIndex)
    {
    case 0:
        TargetIcon = Image_Slot0;
        break;
    case 1:
        TargetIcon = Image_Slot1;
        break;
    case 2:
        TargetIcon = Image_Slot2;
        break;
    case 3:
        TargetIcon = Image_Slot3;
        break;
    default:
        UE_LOG(LogTemp, Error, TEXT("Icon: 잘못된 SlotIndex = %d"), SlotIndex);
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("Icon Update - Slot:%d, Texture:%s, TargetIcon:%s"),
        SlotIndex,
        IconTexture ? *IconTexture->GetName() : TEXT("NULL"),
        TargetIcon ? TEXT("OK") : TEXT("NULL"));

    if (!TargetIcon)
    {
        return;
    }

    if (IconTexture)
    {
        // ✅ 실제 텍스처 적용
        TargetIcon->SetBrushFromTexture(IconTexture);
        TargetIcon->SetBrushTintColor(FLinearColor::White);
    }
    else
    {
        // ✅ 아이콘 없으면 비우기
        TargetIcon->SetBrushFromTexture(nullptr);
    }
}

void UMainHudWidget::HandleHealthChanged(float Current, float Max)
{
    UE_LOG(LogTemp, Warning, TEXT("[HUD] HandleHealthChanged: %.1f / %.1f"), Current, Max);

    if (HealthBar)
    {
        HealthBar->RefreshWidget(Current, Max);
    }
}

void UMainHudWidget::HandleStaminaChanged(float Current, float Max)
{
    UE_LOG(LogTemp, Warning, TEXT("[HUD] HandleStaminaChanged: %.1f / %.1f"), Current, Max);

    if (StaminaBar)
    {
        StaminaBar->RefreshWidget(Current, Max);
    }
}