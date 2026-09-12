// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GUI/DeathScreen.h"
#include "GameFramework/HUD.h"
#include "DeathHUD.generated.h"

/**
 * 
 */
UCLASS()
class VGP221GRAPHICSFPS_API ADeathHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UDeathScreen> GameMenuWidgetClass;
	UDeathScreen* GameMenuWidgetContainer;

	void SpawnGameMenuWidget();
};
