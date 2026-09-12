// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/WinScreenWidget.h"
#include "HUD/WinHUD.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void UWinScreenWidget::NativeConstruct()
{
    Super::NativeConstruct();

    ExitButton->OnClicked.AddDynamic(this, &UWinScreenWidget::OnExitClicked);
    RestartLevelButton->OnClicked.AddDynamic(this, &UWinScreenWidget::OnRestartLevelClicked);
    MainMenuButton->OnClicked.AddDynamic(this, &UWinScreenWidget::OnMainMenuClicked);
    HighScoresButton->OnClicked.AddDynamic(this, &UWinScreenWidget::OnHighScoreClicked);
}


void UWinScreenWidget::OnRestartLevelClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("GAME STARTED!"));

    UGameplayStatics::OpenLevel(this, FName("Level1"));

}

void UWinScreenWidget::OnMainMenuClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("MainMenu!"));
    UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}

void UWinScreenWidget::OnHighScoreClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("HighScores!"));
}



void UWinScreenWidget::OnExitClicked()
{
    // UE_LOG(LogTemp, Warning, TEXT("GAME STOPPED!"));
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}