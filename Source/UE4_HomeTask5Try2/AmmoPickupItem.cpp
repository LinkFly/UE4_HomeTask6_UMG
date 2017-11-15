// Fill out your copyright notice in the Description page of Project Settings.

#include "AmmoPickupItem.h"


// Sets default values
AAmmoPickupItem::AAmmoPickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	RootComponent = TriggerBox;
	ItemMeshCmp = CreateDefaultSubobject<UStaticMeshComponent>("ItemMeshCmp");
	ItemMeshCmp->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	ItemMeshCmp->SetupAttachment(TriggerBox);
	ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (Mesh.Object) {
		ItemMeshCmp->SetStaticMesh(Mesh.Object);
	}
	/*ExampleAmmo = CreateDefaultSubobject<AMyBulletProjectile>("ExampleAmmo");
	ExampleAmmo->AttachToComponent(ItemMeshCmp);*/
}

// Called when the game starts or when spawned
void AAmmoPickupItem::BeginPlay()
{
	Super::BeginPlay();
	AMyBulletProjectile* ExampleAmmo = NewObject<AMyBulletProjectile>();
	ExampleAmmo->SetBulletType(CurAmmo);
	ItemMeshCmp->SetMaterial(0, ExampleAmmo->CurMaterial);
}

// Called every frame
void AAmmoPickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoPickupItem::NotifyActorBeginOverlap(AActor* OtherActor) {
	auto CurGameMode = Cast<AUE4_HomeTask6_UMG_GameModeBase>(GetWorld()->GetAuthGameMode());
	if (CurGameMode) {
		/*SetActorHiddenInGame(true);*/
		/*CurGameMode->EvtPickup.ExecuteIfBound(CurAmmo);*/
		CurGameMode->EvtPickup.Broadcast(CurAmmo);
		Destroy();
	}
}
