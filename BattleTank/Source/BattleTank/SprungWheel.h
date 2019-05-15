// Copyright Jashan Dhilon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "SprungWheel.generated.h"

/**
* Handles wheel suspension physics to help movement system
*/
UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Applies force to wheel for driving 
	void AddDrivingForce(float ForceMagnitude);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Sets up componentsq for physics constraint
	void SetupConstraints();

private:	
	// Wheel of suspension system
	UPROPERTY(VisibleAnywhere, Category = Setup)
	USphereComponent* Wheel = nullptr;

	// Axle for wheeled movement
	UPROPERTY(VisibleAnywhere, Category = Setup)
	USphereComponent* Axle = nullptr;

	// Spring for suspension
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UPhysicsConstraintComponent* MassWheelConstraint = nullptr;

	// Constrains wheel to axle
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UPhysicsConstraintComponent* AxleWheelConstraint = nullptr;

	// Force applied this frame
	float TotalForceMagnitudeThisFrame = 0.f;

	// Applies and consumes force
	void ApplyForce();

	// On hit delegate
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
