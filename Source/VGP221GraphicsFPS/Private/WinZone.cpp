// Fill out your copyright notice in the Description page of Project Settings.


#include "WinZone.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
AWinZone::AWinZone()
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(DefaultSceneRoot);
	Box = CreateDefaultSubobject<UBoxComponent>(FName("Box"));
	Box->SetBoxExtent(FVector(74.0f, 125.0f, 100.0f));
	Box->SetupAttachment(StaticMesh);
	Box->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
}

void AWinZone::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AWinZone::OverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &AWinZone::OverlapEnd);
}

void AWinZone::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->ActorHasTag("Player"))
	{
		UGameplayStatics::OpenLevel(this, FName("WinMenu"));
		UE_LOG(LogTemp, Warning, TEXT("win zone hit by %s"), *OtherActor->GetName());
	}
}

void AWinZone::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}
/*AWinZone::AWinZone()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComp = CreateDefaultSubobject
	//RootComponent = BoxComp;
}

void AWinZone::BeginPlay()
{

	Super::BeginPlay();
	
}

void AWinZone::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

//void AWinZone::OnOverlapStart(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}*/
