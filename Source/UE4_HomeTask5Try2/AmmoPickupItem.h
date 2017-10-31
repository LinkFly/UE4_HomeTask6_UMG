// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "UE4_HomeTask6_UMG_GameModeBase.h"
#include "GameStructs.h"
#include "MyBulletProjectile.h"
#include "AmmoPickupItem.generated.h"

UCLASS()
class UE4_HOMETASK5TRY2_API AAmmoPickupItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoPickupItem();
	UPROPERTY()
		UBoxComponent* TriggerBox;
	 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
		/*FName CurAmmo = FNameToBulletType::ToBulletTypeName(EBulletHard);*/
		TBulletTypes CurAmmo = TBulletTypes::EBulletStandard;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* ItemMeshCmp;
	AMyBulletProjectile* ExampleAmmo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
