
#include "Base_Classes/Target_Base_CPP.h"

#include "Materials/MaterialInstanceDynamic.h"


ATarget_Base_CPP::ATarget_Base_CPP() :
	AActor_Base_Class_CPP(),
	fHealth(100.f),
	PDynamicMaterial(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	//PStaticMeshComponent->SetSimulatePhysics(true);		//set this static mesh component to be able to receive OnHit event from projectile component
}


void ATarget_Base_CPP::BeginPlay()
{
	Super::BeginPlay();

	PDynamicMaterial = UMaterialInstanceDynamic::Create(PStaticMeshComponent->GetMaterial(0), nullptr);
	if (PDynamicMaterial)
	{
		PStaticMeshComponent->SetMaterial(0, PDynamicMaterial);
	}
}

float ATarget_Base_CPP::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	fHealth -= ActualDamage;

	if (fHealth <= 0.f)
	{
		Destroy();
	}

	return ActualDamage;
}