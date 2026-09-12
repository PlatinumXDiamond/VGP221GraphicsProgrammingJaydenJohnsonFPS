// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/DeathHUD.h"
#include "Widgets/SWeakWidget.h"

void ADeathHUD::BeginPlay()
{
    Super::BeginPlay();

    //spawn and show using  UMG
    SpawnGameMenuWidget();
}

void ADeathHUD::SpawnGameMenuWidget()
{
    if (!GameMenuWidgetClass) return;

    // Delete game menu widget if it already exists
    if (GameMenuWidgetContainer) {
        GameMenuWidgetContainer->RemoveFromParent();
        GameMenuWidgetContainer = nullptr;
    }

    GameMenuWidgetContainer = CreateWidget<UDeathScreen>(GetWorld(), GameMenuWidgetClass);
    GameMenuWidgetContainer->AddToViewport();
    UE_LOG(LogTemp, Warning, TEXT("Hello World"));

    PlayerOwner->bShowMouseCursor = true;
     // PlayerOwner->SetInputMode(FInputModeGameOnly());
}
