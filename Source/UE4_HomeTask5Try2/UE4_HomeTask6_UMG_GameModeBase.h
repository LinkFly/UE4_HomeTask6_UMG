// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameStructs.h"
#include "UE4_HomeTask6_UMG_GameModeBase.generated.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FEventPickupDelegate, TBulletTypes)

UCLASS()
class UE4_HOMETASK5TRY2_API AUE4_HomeTask6_UMG_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	FEventPickupDelegate EvtPickup;
	
	
};
