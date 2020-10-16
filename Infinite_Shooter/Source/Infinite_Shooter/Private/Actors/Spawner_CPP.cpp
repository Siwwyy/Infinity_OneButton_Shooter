
#include "Actors/Spawner_CPP.h"


#include "DrawDebugHelpers.h"
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
		//const int32 Random_X_Position{ static_cast<int32>(GetActorLocation().X - 50.f) };
		//const int32 Random_Y_Position{ Get_RandomInt(GetActorLocation().Y - 700.f, GetActorLocation().Y + 700.f) };
		//const int32 Random_Z_Position{ Get_RandomInt(GetActorLocation().Z, GetActorLocation().Z + 300.f) };

		//const FVector SpawnLocation(FVector(static_cast<float>(Random_X_Position), static_cast<float>(Random_Y_Position), static_cast<float>(Random_Z_Position)));
		//const FRotator SpawnRotation(RootComponent->GetComponentRotation());
		//
		//const FTransform SpawnLocAndRotation(SpawnRotation, SpawnLocation);

		//FVector Forward_Vector(300.f,0.f,0.f); //= PStaticMeshComponent->GetForwardVector();
		//const float Rotation_Angle = static_cast<float>(Get_RandomInt(-45, 45));
		//
		//FVector Forward_Vector = PStaticMeshComponent->GetForwardVector();
		//Forward_Vector.X += 700.f;
		//FRotator Rotator = PStaticMeshComponent->GetComponentRotation();

		////rotate vector around the spawner position
		//Rotator.Yaw = 90.f;
		//
		//FVector Result_Vector = Rotator.RotateVector(Forward_Vector); //+ (PStaticMeshComponent->GetRelativeLocation()*2);
		////Result_Vector *= 300.f;
		//Result_Vector.Z = 300.f;
		//
		//const int32 Random_X_Position{  };
		//const int32 Random_Y_Position{  };
		//const int32 Random_Z_Position{ Get_RandomInt(GetActorLocation().Z, GetActorLocation().Z + 300.f) };
		
		//Rotator = PStaticMeshComponent->GetComponentRotation();
		//Rotator.Yaw = (360.f - Rotation_Angle);

		FVector New_Location = PStaticMeshComponent->GetRelativeLocation();

		FVector Radius = FVector(600.f,0.f,0.f);

		//const float Rotation_Angle = static_cast<float>(Get_RandomInt(0,360));
		static float Rotation_Angle = 0.f;

		FVector Rotate_Value = Radius.RotateAngleAxis(Rotation_Angle, FVector(0,0,1));

		New_Location.X += Rotate_Value.X;
		New_Location.Y += Rotate_Value.Y;
		New_Location.Z = 400.f;
		
		
		const FVector SpawnLocation(New_Location);
		const FRotator SpawnRotation(PStaticMeshComponent->GetComponentRotation());

		const FTransform SpawnLocAndRotation(SpawnRotation, SpawnLocation);


		ATarget_CPP* Target_CPP = World->SpawnActorDeferred<ATarget_CPP>(Target, SpawnLocAndRotation);
		if (Target_CPP)
		{
			Target_CPP->Set_Player(PPlayer);
			Target_CPP->FinishSpawning(SpawnLocAndRotation);
		}
		//DrawDebugString(GetWorld(), SpawnLocation, FString::Printf(TEXT("Spawned an object")), 0, FColor::Red, 2.f, false, 3.f);

		Rotation_Angle += 30.f;
	}
}


/*
 *const int32 Rotation_Angle = Get_RandomInt(0, 360);

		
		FVector Forward_Vector = PStaticMeshComponent->GetForwardVector();
		Forward_Vector.X += 500.f;
		Forward_Vector.Z += 300.f;

		
		FRotator Rotator = PStaticMeshComponent->GetComponentRotation();
		Rotator.Yaw -= static_cast<float>(Rotation_Angle);
		
		const FVector Result_Vector = Rotator.RotateVector(Forward_Vector);

		
		Rotator.Yaw += static_cast<float>(Rotation_Angle);
		
		
		const FVector SpawnLocation(Result_Vector);
		const FRotator SpawnRotation(Rotator);

		const FTransform SpawnLocAndRotation(SpawnRotation, SpawnLocation);
		
*/