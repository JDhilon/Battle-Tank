// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Class controlling the turret of the tank. Used for aiming and firing
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	// Elevates barrel at a speed relative to max speed
	void Elevate(float RelativeSpeed);

private:
	// Max speed the barrel can move up or down at
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.0; // TODO Set to sensible value

	// Max height the barrel can be elevated
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 40.0;	

	// Min height the barrel can be elevated
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0.0;	
};
