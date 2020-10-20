
#include "Game_Logic/Game_Manager.h"
#include "Actors/Target_CPP.h"
#include "Base_Classes/Target_Base_CPP.h"
#include "Actors/Spawner_CPP.h"
#include "Infinite_Shooter/Infinite_ShooterCharacter.h"


#include "DrawDebugHelpers.h"
#include "Components/WidgetComponent.h"


AGame_Manager::AGame_Manager() :
	Timer_Game_MainLoop({}),
	Timer_Game_SpawnLoop({}),
	Difficultness(Game_Difficultness::Easy),
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

	Delete_DestroyedTarget();
	Change_Game_Difficultness();
	if (Is_End())
	{
		DrawDebugString(GetWorld(), Draw_Location, FString::Printf(TEXT("GAME OVER!!!")), 0, FColor::Black, 0.2f, false, 3.f);
		GetWorldTimerManager().ClearTimer(Timer_Game_MainLoop);
		GetWorldTimerManager().ClearTimer(Timer_Game_SpawnLoop);
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
			Increase_Game_Points(1);	//increase points by 1
			Target->Get_PWidgetComponent()->DestroyComponent();
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

void AGame_Manager::Change_Game_Difficultness()
{
	if (Game_Points % 50 == 0 && Game_Points != 0)	//increase speed of Targets every 25 points
	{
		for (ATarget_Base_CPP* const Target : Array_Target)
		{
			if(Target->Get_IsDestroyed() == false)
			{
				if(ATarget_CPP * Target_CPP = Cast<ATarget_CPP>(Target))
				{
					Target_CPP->Set_Velocity(Target_CPP->Get_Velocity() + static_cast<float>(Difficultness));	//increase target velocity (increases difficultness of game too)
				}
			}
		}
	}
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
