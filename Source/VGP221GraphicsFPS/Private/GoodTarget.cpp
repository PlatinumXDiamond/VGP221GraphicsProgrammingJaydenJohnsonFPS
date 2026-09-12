// Fill out your copyright notice in the Description page of Project Settings.


#include "GoodTarget.h"
#include "Components/BoxComponent.h"
//#include "FPSCharacter.generated.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoodTarget::AGoodTarget()
{
	PrimaryActorTick.bCanEverTick = false;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(DefaultSceneRoot);
	//Box = CreateDefaultSubobject<UBoxComponent>(FName("Box"));
	//Box->SetBoxExtent(FVector(74.0f, 125.0f, 100.0f));
	//Box->SetupAttachment(StaticMesh);
	//Box->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionComponent->SetBoxExtent(FVector(74.0f, 125.0f, 100.0f));
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("GoodTarget"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AGoodTarget::OnCollide);
	RootComponent = CollisionComponent;
}



void AGoodTarget::BeginPlay()
{
	Super::BeginPlay();
	//Box->OnComponentBeginOverlap.AddDynamic(this, &AGoodTarget::OverlapBegin);
	//Box->OnComponentEndOverlap.AddDynamic(this, &AGoodTarget::OverlapEnd);
}

/*void AGoodTarget::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->ActorHasTag("Player"))
	{
		UGameplayStatics::OpenLevel(this, FName("WinMenu"));
		UE_LOG(LogTemp, Warning, TEXT("win zone hit by %s"), *OtherActor->GetName());
	}
}

void AGoodTarget::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}*/
void AGoodTarget::OnCollide(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// If physics, add impulse then destroy projectile
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()) {
		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		//OnHurtPlayer(10.0f);
	//	AFPSCharacter* 
		Destroy();
	}
	// if no physics just destroy projectile
	if (OtherActor != this) {
		
		Destroy();


	}
	UE_LOG(LogTemp, Warning, TEXT("OBJECT HIT ME!: %s"), *OtherActor->GetName());
}

