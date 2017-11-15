// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/GridPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/UMG/Public/Components/GridSlot.h"
#include "Inventory.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE4_HOMETASK5TRY2_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FInventory CurInventory;

	TArray<UTextBlock*> ItemsSlots;
	TBulletTypes CurAmmo;

	UFUNCTION(BlueprintCallable)
		void Show(FInventory& Inventory);
	UFUNCTION(BlueprintCallable)
		void Create(FInventory& Inventory);
	UFUNCTION(BlueprintCallable)
		void SwitchVisible();
	UFUNCTION()
		void AddItem(TBulletTypes BulletType);
	UFUNCTION()
		TBulletTypes GetCurAmmo();
	UFUNCTION()
		void SwitchCurAmmo(TBulletTypes Ammo);

private:

	bool IsVisible = false;
};
