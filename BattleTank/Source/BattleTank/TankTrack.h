// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * Class controlling tracks of the tanks. Used for movement
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	UTankTrack();

	// Sets a throttle between -1.0 and 1.0
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Moves track at current throttle
	void DriveTrack(float CurrentThrottle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.0; // Assume 40 tonne tank and 1g acceleration

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Returns all wheels attached to track
	TArray<ASprungWheel*> GetWheels() const;
};
