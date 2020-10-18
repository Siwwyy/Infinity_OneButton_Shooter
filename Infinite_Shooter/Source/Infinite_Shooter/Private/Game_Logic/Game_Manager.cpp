
#include "Game_Logic/Game_Manager.h"
#include "Actors/Target_CPP.h"
#include "Actors/Spawner_CPP.h"
#include "Infinite_Shooter/Infinite_ShooterCharacter.h"


#include "DrawDebugHelpers.h"


AGame_Manager::AGame_Manager() :
	Timer_Game_MainLoop({}),
	Timer_Game_SpawnLoop({}),
	Player(nullptr),
	Spawner(nullptr),
	Array_Target({})
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGame_Manager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Timer_Game_MainLoop, this, &AGame_Manager::Game_Loop, 0.1f, true, 0.5f);
	GetWorldTimerManager().SetTimer(Timer_Game_SpawnLoop, this, &AGame_Manager::Add_Target, 1.f, true, 1.f);
}

void AGame_Manager::Game_Loop()
{
	FVector Draw_Location = (Player->GetActorLocation() * (Player->GetActorForwardVector() * 2));
	Draw_Location.Z = 200.f;

	//Add_Target();
	Delete_DestroyedTarget();
	if (Is_End())
	{
		DrawDebugString(GetWorld(), Draw_Location, FString::Printf(TEXT("GAME OVER!!!")), 0, FColor::Black, 0.2f, false, 3.f);
		GetWorldTimerManager().ClearTimer(Timer_Game_MainLoop);
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
	}
}

void AGame_Manager::Add_Target()
{
	Array_Target.AddUnique(Spawner->Spawn());
}

void AGame_Manager::Delete_DestroyedTarget()
{
	for (ATarget_Base_CPP* const Target : Array_Target)
	{
		if (Target->Get_IsDestroyed())
		{
			Increase_Game_Points(1);
			Target->Destroy();	//remove target from World
			Array_Target.Remove(Target);	//remove Target from array
			break;
		}
	}
}

void AGame_Manager::Increase_Game_Points(int32 Increase_Value)
{
	Game_Points += Increase_Value;
	Player->Set_PlayerPoints(Game_Points);
}

bool AGame_Manager::Is_End()
{
	for (ATarget_Base_CPP* const Target : Array_Target)
	{
		const FVector Target_Location = Target->GetActorLocation();
		if (Target->GetDistanceTo(Player) <= (Target_Location.Z / 1.5f))
		{
			return true;
		}
	}
	return false;
}