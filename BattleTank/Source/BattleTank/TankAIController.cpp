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
	if (!ensure(PlayerPawn)) { return; }
	ATank* PlayerTank = Cast<ATank>(PlayerPawn);
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	MoveToActor(
		PlayerTank, 
		1.f,
		true,
		true,
		false,
		0, 
		true); //TODO Check Radius is in CM

	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	// ControlledTank->Fire();
}
