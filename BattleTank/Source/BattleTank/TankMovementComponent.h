// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Engine/World.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	// Moves tank forward and backwards
	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendMoveForward(float Throw);

	// Turns tank right and left 
	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendRotateClockwise(float Throw);

	// Passes reference of left and right track
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet);

private:
	// Called from the pathfinding logic by the AI Controller
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	// Reference to left track of tank
	UTankTrack* LeftTrack = nullptr;

	// Reference to right track of tank
	UTankTrack* RightTrack = nullptr;
};
