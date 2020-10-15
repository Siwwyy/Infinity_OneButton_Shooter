

#include "Base_Classes/Actor_Base_Class_CPP.h"



#include "Components/StaticMeshComponent.h"

AActor_Base_Class_CPP::AActor_Base_Class_CPP()
{
	PrimaryActorTick.bCanEverTick = false;

		
	PStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PStaticMeshComponent"));
	PStaticMeshComponent->SetupAttachment(RootComponent);
}

void AActor_Base_Class_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}
