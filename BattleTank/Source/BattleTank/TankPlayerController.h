// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping player to aim and move
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Helps to set UI reference to aiming only after the aiming component is initialized
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	// Moves barrel so a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// True if hits landscape, returns an OUT Parameter
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Returns direction player is looking at with crosshair as a unit vector
	bool GetLookDirection(FVector2D ScreenLoc, FVector& OutLookDirection) const;

	// Raytraces out in a direction for a specified distance and returns the first visible object hit
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	// Used to initialize broadcast for death
	virtual void SetPawn(APawn *InPawn) override;

	// On death handler
	UFUNCTION()
	void OnPossessedTankDeath();

	// X location of crosshair on display
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLoc = 0.5;

	// Y location of crosshair on display
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLoc = 0.3333;

	// How far to trace to see if hit would occur
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;
};
