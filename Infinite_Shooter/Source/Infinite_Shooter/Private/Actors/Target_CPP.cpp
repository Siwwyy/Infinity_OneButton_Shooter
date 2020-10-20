

#include "Infinite_Shooter/Public/Actors/Target_CPP.h"

#include "Infinite_Shooter/Infinite_ShooterCharacter.h"
#include "Widgets/HealthBar_CPP.h"

#include "Components/WidgetComponent.h"
#include "Particles/ParticleSystemComponent.h"


ATarget_CPP::ATarget_CPP() :
	ATarget_Base_CPP(),
	Velocity(100.f)
{
	PrimaryActorTick.bCanEverTick = true;

	PPatricle_System = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PPatricle_System"));
	PPatricle_System->SetupAttachment(RootComponent);
}


void ATarget_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void ATarget_CPP::MoveForward(float Value)
{
	FVector Location = GetActorLocation();

	Location += GetActorForwardVector() * Velocity * Value;

	SetActorLocation(Location);
}

void ATarget_CPP::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	MoveForward(DeltaSeconds);	//move forward this

	/*float blend = 0.5f + static_cast<float>(FMath::Cos(GetWorld()->TimeSeconds) / 2);
	PDynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);*/

	const auto User_Widget = Cast<UHealthBar_CPP>(Get_PWidgetComponent()->GetUserWidgetObject());

	if (User_Widget)
	{
		User_Widget->Set_Bar_Value_Percent(Get_fHealth() / 100.f);	//100 is a max health
	}
}

void ATarget_CPP::Set_Velocity(float Value)
{
	Velocity = Value;
}