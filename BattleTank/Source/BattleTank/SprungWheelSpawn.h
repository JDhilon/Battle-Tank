// Copyright Jashan Dhilon

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SprungWheelSpawn.generated.h"

class ASprungWheel;

/**
* Class to attach SprungWheel to
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API USprungWheelSpawn : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USprungWheelSpawn();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Gets spawned actor
	AActor* GetSpawnedActor() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Previously was UPROPERTY(EditDefaultsOnly, Category = Setup) and private. Change back after fix to blueprint variables clearing bug
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	TSubclassOf<AActor> SprungWheelBlueprint;

private:	
	// Actor spawned in Begin Play
	UPROPERTY()
	AActor* SpawnedActor;
};
