// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/WinHUD.h"
#include "Widgets/SWeakWidget.h"

void AWinHUD::BeginPlay()
{
    Super::BeginPlay();

    //spawn and show using  UMG
    SpawnGameMenuWidget();
}

void AWinHUD::SpawnGameMenuWidget()
{
    if (!GameMenuWidgetClass) return;

    // Delete game menu widget if it already exists
    if (GameMenuWidgetContainer) {
        GameMenuWidgetContainer->RemoveFromParent();
        GameMenuWidgetContainer = nullptr;
    }

    GameMenuWidgetContainer = CreateWidget<UWinScreenWidget>(GetWorld(), GameMenuWidgetClass);
    GameMenuWidgetContainer->AddToViewport();
    UE_LOG(LogTemp, Warning, TEXT("Hello World"));

    PlayerOwner->bShowMouseCursor = true;
    // PlayerOwner->SetInputMode(FInputModeGameOnly());
}
