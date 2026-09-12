// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Player/FPSCharacter.h"
#include "WinZone.generated.h"

UCLASS()
class VGP221GRAPHICSFPS_API AWinZone : public AActor
	{
		GENERATED_BODY()

	public:
		AWinZone();

	protected:
		virtual void BeginPlay() override;

		UPROPERTY(EditInstanceOnly, Category = "Changeables")
		UStaticMeshComponent* StaticMesh;

		UPROPERTY()
		USceneComponent* DefaultSceneRoot;

		UPROPERTY()
		UBoxComponent* Box;

		UFUNCTION()
		void OverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

		UFUNCTION()
		void OverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex);

	};
	/*GENERATED_BODY()
public:
	AWinZone();
	UPROPERTY(VisibleAnywhere, Category = "Components") class UboxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, Category = "Components") class UStaticMeshComponent* BaseMesh;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	
};*/
