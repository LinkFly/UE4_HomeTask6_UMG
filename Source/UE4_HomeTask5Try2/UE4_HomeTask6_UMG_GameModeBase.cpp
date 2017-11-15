// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4_HomeTask6_UMG_GameModeBase.h"

AUE4_HomeTask6_UMG_GameModeBase::AUE4_HomeTask6_UMG_GameModeBase()
{
	
}

void AUE4_HomeTask6_UMG_GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), UInventoryWidget::StaticClass());
	if (InventoryWidget) {
		InventoryWidget->Create(Inventory);
	}	
}

void AUE4_HomeTask6_UMG_GameModeBase::SwitchInventory()
{
	InventoryWidget->SwitchVisible();
}

//void AUE4_HomeTask6_UMG_GameModeBase::EnableMouseCursor()
//{
//	GetPlayerController()
//}
