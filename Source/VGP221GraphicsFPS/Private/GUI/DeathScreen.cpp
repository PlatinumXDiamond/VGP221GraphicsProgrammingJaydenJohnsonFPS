// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/DeathScreen.h"
#include "HUD/DeathHUD.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"



void UDeathScreen::NativeConstruct()
{
   Super::NativeConstruct();

    ExitButton->OnClicked.AddDynamic(this, &UDeathScreen::OnExitClicked);
    RestartLevelButton->OnClicked.AddDynamic(this, &UDeathScreen::OnRestartLevelClicked);
    MainMenuButton->OnClicked.AddDynamic(this, &UDeathScreen::OnMainMenuClicked);
}


void UDeathScreen::OnRestartLevelClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("GAME STARTED!"));

    UGameplayStatics::OpenLevel(this, FName("Level1"));

}

void UDeathScreen::OnMainMenuClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("MainMenu!"));
    UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}



void UDeathScreen::OnExitClicked()
{
    // UE_LOG(LogTemp, Warning, TEXT("GAME STOPPED!"));
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}