
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
		constexpr float Spawning_Radius = 1500.f;
		FVector Spawn_Location;
		FRotator Spawn_Rotation;
		Spawn_Around(Spawning_Radius, Spawn_Location, Spawn_Rotation);
		const FTransform SpawnLocAndRotation(Spawn_Rotation, Spawn_Location);

		ATarget_CPP* Target_CPP = World->SpawnActorDeferred<ATarget_CPP>(Target, SpawnLocAndRotation);
		if (Target_CPP)
		{
			Target_CPP->Set_Player(PPlayer);
			Target_CPP->FinishSpawning(SpawnLocAndRotation);
		}
	}
}

void ASpawner_CPP::Spawn_Around(float Spawning_Radius, FVector& Spawn_Location, FRotator& Spawn_Rotatation)
{
	//Normalize Vector
	Spawn_Location.Normalize();
	//Normalize Rotator
	Spawn_Rotatation.Normalize();


	static float Rotation_Angle = 0.f;		//determines rotate angle of vector to spawn object
	static float Rotation_Object = 180.f;	//determines angle of spawned object to rotate (to be facing to spawner)
	const float Spawn_Angle = static_cast<float>(Get_RandomInt(0, 360));	//determines what angle add to rotation angle and rotation object

	FVector New_Location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	const FVector Radius = FVector(Spawning_Radius, 0.f, 0.f);
	const FVector Rotate_Value = Radius.RotateAngleAxis(Rotation_Angle, FVector(0, 0, 1));

	New_Location.X += Rotate_Value.X;
	New_Location.Y += Rotate_Value.Y;
	New_Location.Z = static_cast<float>(Get_RandomInt(200, 600));	//random Z position

	Spawn_Location = New_Location;
	Spawn_Rotatation.Yaw = Rotation_Object;

	Rotation_Angle += Spawn_Angle;
	Rotation_Object += Spawn_Angle;
}