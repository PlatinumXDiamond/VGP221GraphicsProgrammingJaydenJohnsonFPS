// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "DeathScreen.generated.h"

/**
 * 
 */
UCLASS()
class VGP221GRAPHICSFPS_API UDeathScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;
	UPROPERTY(meta = (BindWidget))
	UButton* RestartLevelButton;
	UPROPERTY(meta = (BindWidget))
	UButton* MainMenuButton;


	UFUNCTION()
	void OnExitClicked();
	UFUNCTION()
	void OnRestartLevelClicked();
	UFUNCTION()
	void OnMainMenuClicked();
	
};
