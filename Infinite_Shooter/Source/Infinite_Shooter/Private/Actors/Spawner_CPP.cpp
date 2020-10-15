
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


	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawner_CPP::Spawn, 1.f, true, 2.f);

}

void ASpawner_CPP::Spawn()
{
	UWorld* World = GetWorld();
	if (Target && World)
	{
		const int32 Random_X_Position{ static_cast<int32>(GetActorLocation().X - 50.f) };
		const int32 Random_Y_Position{ Get_RandomInt(GetActorLocation().Y - 700.f, GetActorLocation().Y + 700.f) };
		const int32 Random_Z_Position{ Get_RandomInt(GetActorLocation().Z, GetActorLocation().Z + 300.f) };

		const FVector SpawnLocation(FVector(static_cast<float>(Random_X_Position), static_cast<float>(Random_Y_Position), static_cast<float>(Random_Z_Position)));
		const FRotator SpawnRotation(RootComponent->GetComponentRotation());
		
		const FTransform SpawnLocAndRotation(SpawnRotation, SpawnLocation);

		ATarget_CPP* Target_CPP = World->SpawnActorDeferred<ATarget_CPP>(Target, SpawnLocAndRotation);
		if (Target_CPP)
		{
			Target_CPP->Set_Player(PPlayer);
			Target_CPP->FinishSpawning(SpawnLocAndRotation);
		}
	}
}
