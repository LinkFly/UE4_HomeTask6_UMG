// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "Inventory.generated.h"

USTRUCT()
struct FInventoryItem {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FBullet Bullet;	
};

USTRUCT()
struct FInventory {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInventoryItem> Items;

	FInventory() {
		FInventoryItem Item;
		Item.Bullet.ChangeBullet(TBulletTypes::EBulletLight);
		Items.Add(Item);
	}
};
