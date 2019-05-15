// Copyright Jashan Dhilon

#include "SprungWheelSpawn.h"

// Sets default values for this component's properties
USprungWheelSpawn::USprungWheelSpawn()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USprungWheelSpawn::BeginPlay()
{
	Super::BeginPlay();

	// ...

	SpawnedActor = GetWorld()->SpawnActorDeferred<AActor>(SprungWheelBlueprint, GetComponentTransform());
	if (!ensure(SpawnedActor)) { return; }
	SpawnedActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(SpawnedActor, GetComponentTransform());
}


// Called every frame
void USprungWheelSpawn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor * USprungWheelSpawn::GetSpawnedActor() const
{
	return SpawnedActor;
}

