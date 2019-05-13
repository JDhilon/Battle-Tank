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
	Locked
};

class UTankBarrel; 
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = State)
	EFiringState FiringState = EFiringState::Aiming;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Aims at a specified FVector
	void AimAt(FVector AimLocation, float LaunchSpeed); 

	// Initialises references to Turret and Barrel
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	// Returns reference to Barrel
	UTankBarrel* GetBarrel();

private:
	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
};
