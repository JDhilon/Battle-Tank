// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	NoAmmo
};

class UTankBarrel; 
class UTankTurret;
class AProjectile;

/**
* Class responsible for aiming player and AI tank barrels and firing projectiles
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void FindFiringState();

	// Aims at a specified FVector
	void AimAt(FVector AimLocation); 

	// Initialises references to Turret and Barrel
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	// Fire at where the barrel is currently pointing
	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void Fire();

	// Returns reference to Barrel
	UTankBarrel* GetBarrel();

	// Returns firing state
	EFiringState GetFiringState() const;

	// Get Ammo remaining
	int32 GetAmmo() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// State of the firing component
	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringState FiringState = EFiringState::Reloading;

	// Base ammo per tank
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Firing)
	int32 Ammo = 20; 

	// Previously was UPROPERTY(EditDefaultsOnly, Category = Setup) and private. Change back after fix to blueprint variables clearing bug
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

private:
	// Adjust barrel and turret rotations to face a spoecified vector
	void MoveBarrelTowards(FVector AimDirection);

	// Returns if barrel is currently moving/adjusting aim
	bool IsBarrelMoving();

	// Reference to barrel of tank
	UTankBarrel* Barrel = nullptr;

	// Reference to turret of tank
	UTankTurret* Turret = nullptr;

	// Speed projectile is launched at, used for firing and aim calculations
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 12000.0; 

	// Time in between shots
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.0; 

	// How far the barrel has to be from the target to be considered locked on
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LockedRadius = 0.1; 

	// Time last fired. Used for reload calculations
	double LastFireTime = 0.0;

	// Direction the barrel is currently aiming. Used for BarrelMoving calculations
	FVector AimDirection = FVector(0);


};
