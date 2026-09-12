// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnCollide);
	RootComponent = CollisionComponent;


	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Engine/BasicShapes/Sphere")); how to get assets from unreal

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/Meshes/Common/Sphere.Sphere"));

	if (ProjectileMeshAsset.Succeeded())
	{
		ProjectileMeshComponent->SetStaticMesh(ProjectileMeshAsset.Object);
	}

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = BulletSpeed;
	ProjectileMovementComponent->MaxSpeed = BulletSpeed;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f; // No gravity

	InitialLifeSpan = 3.0f; // Destroy after 3 seconds. Unity Destroy(3.0f);

	ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);

	///Game/Materials/M_Projectile.M_Projectile
	static ConstructorHelpers::FObjectFinder<UMaterial> ProjectileMaterialAsset(TEXT("/Game/Materials/M_Projectile.M_Projectile"));
	if (ProjectileMaterialAsset.Succeeded())
	{
		ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
	// 1. FVector ShootDirection: Pass by value, least efficient. Making a copy of the vector
   // 2. FVector* ShootDirection: Pass by pointer, more efficient. Can be null, need to check for null. 
   // 3. FVector& ShootDirection: Pass by reference, most efficient. No dereferencing, no null check needed.
   // 4. const FVector& ShootDirection: Pass by const reference, most efficient. Cannot modify the original vector.
}

void AFPSProjectile::OnCollide(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// If physics, add impulse then destroy projectile
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()) {
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
		//OnHurtPlayer(10.0f);
	//	AFPSCharacter* 
		Destroy();

	
	}
	// if no physics just destroy projectile
	if (OtherActor != this) {
		Destroy();


	}
	UE_LOG(LogTemp, Warning, TEXT("Projectile hit: %s"), *OtherActor->GetName());
}

