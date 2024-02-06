#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RingSpawner.generated.h"

UCLASS()
class BALLGAME_API ARingSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARingSpawner();

	// Called every frame
	virtual void Tick(float const DeltaTime) override;

	//STEP 2

	//UPROPERTY(EditAnywhere, Category = "Class to Spawn")
	//UClass* RingBlueprint;

	//Can assign bluprint to a C++ class, but it lacks mesh
	UPROPERTY(EditAnywhere, Category = "Class to Spawn")
	TSubclassOf<class ARing> RingBlueprint; //the keyword class is used for forward declaration to avoid adding an include statement for ARing which avoids issues related to circular dependencies

	void SpawnRing();

	//Transient prevents object from being serialized into disc
	UPROPERTY(Transient)
		class ARing* RingObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};