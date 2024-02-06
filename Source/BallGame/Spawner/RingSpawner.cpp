// Fill out your copyright notice in the Description page of Project Settings.


#include "RingSpawner.h"
#include "Ring.h"
// Sets default values
ARingSpawner::ARingSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARingSpawner::BeginPlay()
{
	Super::BeginPlay();

	//STEP 2
	SpawnRing();

}

// Called every frame
void ARingSpawner::Tick(float const DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARingSpawner::SpawnRing()
{
	if (!IsValid(RingObject)) //spawns object if it is invalid
	{
		//STEP 2
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		//SpawnParams.Instigator; //related to actor that performs an action instigated by another actor
		//SpawnParams.Instigator = GetWorld()->GetFirstPlayerController()->GetPawn(); //setting instigator
		
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		
		//World/map/level is responsinble for spawning object
		UWorld* World = GetWorld(); //map or level

		RingObject = World->SpawnActor<ARing>(RingBlueprint, GetActorLocation(), GetActorRotation(), SpawnParams);
	}
}

