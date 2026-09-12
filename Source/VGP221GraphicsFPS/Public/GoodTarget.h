// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Player/FPSCharacter.h"
#include "GoodTarget.generated.h"

UCLASS()
class VGP221GRAPHICSFPS_API AGoodTarget : public AActor
{
	GENERATED_BODY()

public:
	AGoodTarget();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "Changeables")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	USceneComponent* DefaultSceneRoot;

	UPROPERTY()
	UBoxComponent* Box;
	UPROPERTY(VisibleDefaultsOnly, Category = "Targets")
	UBoxComponent* CollisionComponent;

	//UFUNCTION()
	//void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
	//void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void OnCollide(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};
