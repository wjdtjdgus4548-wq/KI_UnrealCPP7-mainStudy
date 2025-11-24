// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHudWidget.generated.h"

/**
 * 
 */

class UTextBlock;
class UBorder;
class UImage;

UCLASS()
class KI_UNREALCPP_API UMainHudWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;

protected:
	// meta = (BindWidget)
	// 위젯 블루프린트의 변수와 이 클래스의 변수를 바인드하겠다라는 의미(=둘이 같은 거라고 설정)
	// 위젯 블루프린트의 변수명과 이 클래스의 변수명이 반드시 같아야 한다.(대소문자도 같아야 한다)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Resource", meta = (BindWidget))
	TWeakObjectPtr<class UResourceBarWidget> HealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Resource", meta = (BindWidget))
	TWeakObjectPtr<class UResourceBarWidget> StaminaBar;
	//퀵 슬롯 1번칸
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UBorder> Slot0_Border;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UTextBlock> Slot0_CountText;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UImage> Image_Slot0;

	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UBorder> Slot1_Border;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UTextBlock> Slot1_CountText;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UImage> Image_Slot1;

	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UBorder> Slot2_Border;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UTextBlock> Slot2_CountText;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UImage> Image_Slot2;

	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UBorder> Slot3_Border;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UTextBlock> Slot3_CountText;
	UPROPERTY(meta = (BindWiget))
	TObjectPtr<UImage> Image_Slot3;

public:
	void UpdateQuickSlot(int32 SlotIndex, int32 Stack, bool bSelected);
	void UpdateQuickSlotIcon(int32 SlotIndex, UTexture2D* Icon);
};
