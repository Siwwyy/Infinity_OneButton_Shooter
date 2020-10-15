

#include "Infinite_Shooter/Public/Actors/Target_CPP.h"


ATarget_CPP::ATarget_CPP() :
	ATarget_Base_CPP()
{
	PrimaryActorTick.bCanEverTick = true;


}

void ATarget_CPP::BeginPlay()
{
	Super::BeginPlay();

}

void ATarget_CPP::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float blend = 0.5f + static_cast<float>(FMath::Cos(GetWorld()->TimeSeconds) / 2);
	PDynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);
}
