// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * Controls AI tanks movement and firing
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// How far from player tank the AI tank stops
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float StopRadius = 8000.0;

private:
	// Used to initialize broadcast for death
	virtual void SetPawn(APawn *InPawn) override;

	// On death handler
	UFUNCTION()
	void OnPossessedTankDeath();

	// Aims AI tanks and Fires if locked on target
	void AimAndFire();

};
