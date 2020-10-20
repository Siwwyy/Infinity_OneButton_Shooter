
#include "Actors/Spawner_CPP.h"

#include "Actors/Target_CPP.h"


ASpawner_CPP::ASpawner_CPP() :
	Target({})
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawner_CPP::BeginPlay()
{
	Super::BeginPlay();

}

ATarget_CPP* const ASpawner_CPP::Spawn()
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
			Target_CPP->FinishSpawning(SpawnLocAndRotation);
			return Target_CPP;
		}
	}
	return nullptr;
}

void ASpawner_CPP::Spawn_Around(float Spawning_Radius, FVector& Spawn_Location, FRotator& Spawn_Rotatation) const
{
	//Normalize Vector
	Spawn_Location.Normalize();
	//Normalize Rotator
	Spawn_Rotatation.Normalize();


	static float Rotation_Angle = 0.f;		//determines rotate angle of vector to spawn object
	constexpr float Rotation_Object_Angle = 180.f;	//determines angle of spawned object to rotate (to be facing to spawner)
	const float Spawn_Angle = static_cast<float>(Get_RandomInt(0, 360));	//determines what angle add to rotation angle and rotation object

	FVector New_Location = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	const FVector Radius = FVector(Spawning_Radius, 0.f, 0.f);
	const FVector Rotate_Value = Radius.RotateAngleAxis(Rotation_Angle, FVector(0, 0, 1));

	New_Location.X += Rotate_Value.X;
	New_Location.Y += Rotate_Value.Y;
	New_Location.Z = static_cast<float>(Get_RandomInt(200, 600));	//random Z position

	Spawn_Location = New_Location;
	Spawn_Rotatation.Roll = 0.f;
	Spawn_Rotatation.Yaw = Rotation_Object_Angle + Rotation_Angle;
	Spawn_Rotatation.Pitch = 0.f;

	Rotation_Angle += Spawn_Angle;
	if (Rotation_Angle >= 360.f)
	{
		Rotation_Angle -= 360.f;
	}
}