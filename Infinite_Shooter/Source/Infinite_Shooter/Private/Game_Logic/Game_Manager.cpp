
#include "Game_Logic/Game_Manager.h"
#include "Actors/Target_CPP.h"
#include "Infinite_Shooter/Infinite_ShooterCharacter.h"


#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"


AGame_Manager::AGame_Manager() :
	Timer_Game_Loop({}),
	Player(nullptr),
	Array_Target({})
{
	PrimaryActorTick.bCanEverTick = false;

}

void AGame_Manager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Timer_Game_Loop, this, &AGame_Manager::Game_Loop, 0.2f, true, 0.5f);
}

void AGame_Manager::Game_Loop()
{
	FVector Draw_Location = (Player->GetActorLocation() * (Player->GetActorForwardVector() * 2));
	Draw_Location.Z = 200.f;
	
	Delete_DestroyedTarget();
	if (Is_End())
	{
		DrawDebugString(GetWorld(), Draw_Location, FString::Printf(TEXT("GAME OVER!!!")), 0, FColor::Black, 0.2f, false, 3.f);
		GetWorldTimerManager().ClearTimer(Timer_Game_Loop);
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
	}
	else
	{
		DrawDebugString(GetWorld(), Draw_Location, FString::Printf(TEXT("Current Points %i"), Game_Points), 0, FColor::Black, 0.2f, false, 3.f);
	}

	//DrawDebugString(GetWorld(), FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 400.f), FString::Printf(TEXT("Current Points %i"), Game_Points), 0, FColor::Black, 0.2f, false, 3.f);

}

void AGame_Manager::Add_Target(ATarget_Base_CPP* const Target)
{
	Array_Target.AddUnique(Target);
}

void AGame_Manager::Delete_DestroyedTarget()
{
	for (ATarget_Base_CPP* const Target : Array_Target)
	{
		if (Target->Get_IsDestroyed())
		{
			Increase_Game_Points(1);		//increase points earned by Player
			Target->Destroy();	//remove target from World
			Array_Target.Remove(Target);	//remove Target from array
			break;
		}
	}
}

void AGame_Manager::Increase_Game_Points(int32 Increase_Value)
{
	Game_Points += Increase_Value;
}

bool AGame_Manager::Is_End()
{
	for (ATarget_Base_CPP* const Target : Array_Target)
	{
		const FVector Target_Location = Target->GetActorLocation();
		//ATarget_Base_CPP * Temp_Actor = nullptr;
		//Temp_Actor->SetActorLocation(FVector(Target_Location.X, Target_Location.Y, 100.f));
		if (Target->GetDistanceTo(Player) <= (Target_Location.Z/1.5f))
		{
			return true;
		}
	}
	return false;
}