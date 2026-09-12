// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/MainMenu.h"
#include "HUD/MainMenuHUD.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"


void UMainMenu::NativeConstruct()
{
    Super::NativeConstruct();


    ExitButton->OnClicked.AddDynamic(this, &UMainMenu::OnExitClicked);
    StartButton->OnClicked.AddDynamic(this, &UMainMenu::OnGameStartClicked);
}



void UMainMenu::OnGameStartClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("GAME STARTED!"));
 
    UGameplayStatics::OpenLevel(this, FName("Level1"));
  
}

void UMainMenu::OnExitClicked()
{
   // UE_LOG(LogTemp, Warning, TEXT("GAME STOPPED!"));
    UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}