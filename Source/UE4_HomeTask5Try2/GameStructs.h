// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.generated.h"

UENUM()
enum class TBulletTypes {
	EBulletLight, EBulletStandard, EBulletHard, EBulletNone
};

USTRUCT()
struct FNameToBulletType {
	GENERATED_USTRUCT_BODY()

	/*static TBulletTypes ToBulletType(FName bulletTypeName) {
		if (bulletTypeName == "EBulletLight") return EBulletLight;
		if (bulletTypeName == "EBulletStandard") return EBulletStandard;
		if (bulletTypeName == "EBulletHard") return EBulletHard;
		return EBulletNone;
	}
	static FName ToBulletTypeName(TBulletTypes bulletType) {
		if (bulletType == EBulletLight) return "EBulletLight";
		if (bulletType == EBulletStandard) return "EBulletStandard";
		if (bulletType == EBulletHard) return "EBulletHard";
		return "EBulletNone";
	}*/
};

/**
 * 
 */
//class UE4_HOMETASK5TRY2_API GameStructs
//{
//public:
//	GameStructs();
//	~GameStructs();
//};
