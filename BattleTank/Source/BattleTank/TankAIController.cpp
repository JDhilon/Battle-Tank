// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return; }
	ATank* PlayerTank = Cast<ATank>(PlayerPawn);

	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	}

	ControlledTank->Fire();
}
