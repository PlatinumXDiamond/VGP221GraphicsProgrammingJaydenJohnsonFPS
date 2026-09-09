// Fill out your copyright notice in the Description page of Project Settings.

#include "Logging/StructuredLog.h"
#include "FPSProjectGameMode.h"

void AFPSProjectGameMode::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // 1. Print to screen
    // Display a debug message for five seconds.
    // The -1 "Key" value argument prevents the message from being updated or refreshed.
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode! Hybrid with editor open!"));

    // 2. Print to log
    UE_LOG(LogTemp, Warning, TEXT("Hello World"));

    // 3. Printing values using specifiers
    int TestNumber = 5;
    bool TestBool = true; // 0 = false 1 = true
    UE_LOG(LogTemp, Warning, TEXT("Test Number: %i"), TestNumber);
    UE_LOG(LogTemp, Warning, TEXT("Test Bool: %i"), TestBool);
    UE_LOG(LogTemp, Warning, TEXT("Test Bool String: %s"), TestBool ? TEXT("true") : TEXT("false"));

    // 4. Pointers & References
    //pointers need be initalized but refereces dont                 * = pointer & = reference
    int* TestNumberPtr = &TestNumber;

    UE_LOG(LogTemp, Warning, TEXT("TestNumber Ref: %p"), &TestNumber);
    UE_LOG(LogTemp, Warning, TEXT("TestNumberPtr: %p"), TestNumberPtr);

    //5. giving a nickname to a varible

    int& NicknameForTestNumber = TestNumber;
    NicknameForTestNumber = 10;
    UE_LOG(LogTemp, Warning, TEXT("New Test Number is: %i"), TestNumber);

    // 6. Printing a string
    FString TestString = TEXT("Hello, Unreal!");
    UE_LOG(LogTemp, Warning, TEXT("Test String: %s"), *TestString);

    //skipped 7

    // 8. Using structured logging
    UE_LOGFMT(LogTemp, Warning, "Structured Logging: Test Number: {0}, Test Bool: {1}, Test String: {2}", TestNumber, TestBool, *TestString);
}