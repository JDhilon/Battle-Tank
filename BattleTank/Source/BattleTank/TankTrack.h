// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	UTankTrack();

	// Called when the game starts
	virtual void BeginPlay() override;

	// OnHit delegate function
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// Limits the slippage of the tank, forcing a straigh drive path
	void PreventSidewaysSlip();

	// Sets a throttle between -1.0 and 1.0
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Moves track at current throttle
	void DriveTrack();

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.0; // Assume 40 tonne tank and 1g acceleration

	float CurrentThrottle = 0.0;
};
