// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainMenuHUD.h"
#include "Widgets/SWeakWidget.h"

void AMainMenuHUD::BeginPlay()
{
    Super::BeginPlay();
    // 2. Spawn & show slate
   // ShowSettingsWidget();

    //spawn and show using  UMG
    SpawnGameMenuWidget();
}

void AMainMenuHUD::SpawnGameMenuWidget()
{
    if (!GameMenuWidgetClass) return;

    // Delete game menu widget if it already exists
    if (GameMenuWidgetContainer) {
        GameMenuWidgetContainer->RemoveFromParent();
        GameMenuWidgetContainer = nullptr;
    }

    GameMenuWidgetContainer = CreateWidget<UMainMenu>(GetWorld(), GameMenuWidgetClass);
    GameMenuWidgetContainer->AddToViewport();
    UE_LOG(LogTemp, Warning, TEXT("Hello World"));

    PlayerOwner->bShowMouseCursor = true;
   // PlayerOwner->SetInputMode(FInputModeGameOnly());
}
