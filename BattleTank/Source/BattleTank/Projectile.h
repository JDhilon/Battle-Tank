// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile.generated.h"

/**
 * Class controlling projectile collisions and effects
 */
UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Projectile Movement for applying force and firing projectile
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	// Collision Mesh for calculating hits
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UStaticMeshComponent* CollisionMesh = nullptr;

	// Launch Blast particles
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UParticleSystemComponent* LaunchBlast = nullptr;

	// Impact Blast particles
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UParticleSystemComponent* ImpactBlast = nullptr;

	// Radial Force for damage calculations
	UPROPERTY(VisibleAnywhere, Category = Setup)
	URadialForceComponent* ExplosionForce = nullptr;

	// How long until the projectile despawns in Seconds
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float DestroyDelay = 10.f;

	// Base damage done by projectile at center of impact
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ProjectileDamage = 20.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Launch projectile at given speed from barrel's projectile socket
	void LaunchProjectile(float Speed);

private:
	// OnHit delegate function
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
	// Handles proper destruction of projectile after set delay
	void OnTimerExpire();
};
