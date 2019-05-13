// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* RightTrackToSet, UTankTrack* LeftTrackToSet)
{
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendRotateClockwise(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(AIForwardIntention, TankForwardDirection);
	IntendMoveForward(ForwardThrow);

	auto ClockwiseThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntention).Z;
	IntendRotateClockwise(ClockwiseThrow);
}