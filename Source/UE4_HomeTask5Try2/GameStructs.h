// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.generated.h"

UENUM()
enum class TBulletTypes {
	EBulletLight, EBulletStandard, EBulletHard, EBulletNone
};

USTRUCT()
struct FBullet {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TBulletTypes Type;
	// While not using
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Weight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	void SetWeight(TBulletTypes& Type, float& Weight) {
		switch (Type) {
		case TBulletTypes::EBulletLight: 
			Weight = 100; Description = "Light"; break;
		case TBulletTypes::EBulletStandard:
			Weight = 300; Description = "Standard";  break;
		case TBulletTypes::EBulletHard:
			Weight = 1000; Description = "Hard";  break;
		case TBulletTypes::EBulletNone:
			Weight = 0; Description = "None";  break;
		}
	}
	FBullet() {
		ChangeBullet(TBulletTypes::EBulletLight);
	}
	void ChangeBullet(TBulletTypes BulletType) {
		Type = BulletType;
		SetWeight(Type, Weight);
	}
};