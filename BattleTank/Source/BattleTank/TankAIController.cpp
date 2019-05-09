// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Gets name of AI possessed tank

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("AIController not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()))
	}

	// Gets name of player tank

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("FirstPlayer not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("FirstPlayer possessing: %s"), *(PlayerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
