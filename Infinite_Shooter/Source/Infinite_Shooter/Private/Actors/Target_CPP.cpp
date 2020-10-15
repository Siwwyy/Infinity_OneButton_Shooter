

#include "Infinite_Shooter/Public/Actors/Target_CPP.h"




ATarget_CPP::ATarget_CPP()
{
	PrimaryActorTick.bCanEverTick = false;

	PStaticMeshComponent->SetSimulatePhysics(true);
}

void ATarget_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}