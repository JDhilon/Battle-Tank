// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * Responsible for helping player to aim
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

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLoc = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLoc = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;
};
