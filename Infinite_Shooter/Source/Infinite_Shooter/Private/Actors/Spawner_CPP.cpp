
#include "Actors/Spawner_CPP.h"

#include "Actors/Target_CPP.h"

#include "TimerManager.h"


ASpawner_CPP::ASpawner_CPP()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawner_CPP::BeginPlay()
{
	Super::BeginPlay();


	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner_CPP::Spawn, 2.f, true, 1.f);

}

void ASpawner_CPP::Spawn()
{
	UWorld* World = GetWorld();
	if (Target && World)
	{
		const FRotator SpawnRotation(RootComponent->GetComponentRotation());
		FVector SpawnLocation(RootComponent->GetComponentLocation());

				
		const FTransform SpawnLocAndRotation(SpawnRotation, SpawnLocation);

		ATarget_CPP* Target_CPP = World->SpawnActorDeferred<ATarget_CPP>(Target, SpawnLocAndRotation);
		if (Target_CPP)
		{
			Target_CPP->Set_Player(PPlayer);
			Target_CPP->FinishSpawning(SpawnLocAndRotation);
		}
	}
}
