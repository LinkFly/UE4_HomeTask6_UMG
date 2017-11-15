// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryWidget.h"
#include "UE4_HomeTask6_UMG_GameModeBase.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {
	

}

void UInventoryWidget::Create(FInventory & Inventory) {
	auto CurGameMode = Cast<AUE4_HomeTask6_UMG_GameModeBase>(GetWorld()->GetAuthGameMode());
	if (CurGameMode) {
		CurGameMode->EvtPickup.AddUObject(this, &UInventoryWidget::AddItem);
		CurGameMode->EvtSwitchAmmo.AddUObject(this, &UInventoryWidget::SwitchCurAmmo);
	}
	UGridPanel* Root = NewObject<UGridPanel>();
	if (Root) {
		Root->ColumnFill.Add(1);
		Root->ColumnFill.Add(1);
		Root->ColumnFill.Add(4);
		Root->RowFill.Add(1);
		Root->RowFill.Add(1);
		Root->RowFill.Add(4);
		WidgetTree->RootWidget = Root;
		for (int32 i = 0; i < 4; i++) {
			UButton* CurButton = NewObject<UButton>();

			UTextBlock* CurText = NewObject<UTextBlock>();
			CurButton->AddChild(CurText);
			ItemsSlots.Add(CurText);

			Root->AddChild(CurButton);
			UPanelSlot* PanelSlot = CurButton->Slot;
			UGridSlot* slot = Cast<UGridSlot>(PanelSlot);
			if (slot) {
				slot->SetColumn(i % 2);
				slot->SetRow(i / 2);
			}
		}
	}
	SwitchVisible();
	AddToViewport();
}

void UInventoryWidget::SwitchVisible()
{
	IsVisible = !IsVisible;
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = IsVisible;
	SetVisibility(IsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	if (IsVisible) {
		Show(CurInventory);
	}
}

void UInventoryWidget::Show(FInventory & Inventory)
{
	for (int32 i = 0; i < Inventory.Items.Num(); i++) {
		FBullet& Bullet = Inventory.Items[i].Bullet;

		FSlateColor Color;
		if (Bullet.Type == GetCurAmmo()) {
			Color = FSlateColor(FLinearColor(1, 0, 0));
		} else Color = FSlateColor(FLinearColor(1, 1, 1));
		ItemsSlots[i]->SetColorAndOpacity(Color);

		FString Caption = "Type: " + Bullet.Description + "\nWeight: " + FString::FromInt(Bullet.Weight) + "\n";
		ItemsSlots[i]->SetText(FText::FromString(Caption));
	}
}

TBulletTypes UInventoryWidget::GetCurAmmo() {
	return CurAmmo;
}

void UInventoryWidget::SwitchCurAmmo(TBulletTypes Ammo)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "SwitchCurAmmo");
	CurAmmo = Ammo;
	SwitchVisible();
	if (!IsVisible) SwitchVisible();
}

void UInventoryWidget::AddItem(TBulletTypes BulletType)
{
	FInventoryItem Item;
	Item.Bullet.ChangeBullet(BulletType);
	CurInventory.Items.Add(Item);
	SwitchCurAmmo(BulletType);
}
