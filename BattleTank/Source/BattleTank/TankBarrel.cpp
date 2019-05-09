// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ClampedSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; // Per Frame
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}