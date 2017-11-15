// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameStructs.h"
#include "Inventory.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.h"
#include "UE4_HomeTask6_UMG_GameModeBase.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEventPickupDelegate, TBulletTypes)
DECLARE_MULTICAST_DELEGATE_OneParam(FEventSwitchAmmoDelegate, TBulletTypes)

UCLASS()
class UE4_HOMETASK5TRY2_API AUE4_HomeTask6_UMG_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	FEventPickupDelegate EvtPickup;
	FEventSwitchAmmoDelegate EvtSwitchAmmo;

	AUE4_HomeTask6_UMG_GameModeBase();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Widgets")
		UInventoryWidget* InventoryWidget;

	FInventory Inventory;
	TBulletTypes CurAmmo;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void SwitchInventory();
	/*UFUNCTION(BlueprintCallable)
		void EnableMouseCursor();*/
};
