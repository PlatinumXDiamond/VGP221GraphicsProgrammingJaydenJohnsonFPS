// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GUI/WinScreenWidget.h"
#include "WinHUD.generated.h"

/**
 * 
 */
UCLASS()
class VGP221GRAPHICSFPS_API AWinHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UWinScreenWidget> GameMenuWidgetClass;
	UWinScreenWidget* GameMenuWidgetContainer;

	void SpawnGameMenuWidget();
	
};
