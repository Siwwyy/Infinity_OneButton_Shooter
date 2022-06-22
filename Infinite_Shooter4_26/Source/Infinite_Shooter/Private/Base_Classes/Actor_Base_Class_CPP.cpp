

#include "Base_Classes/Actor_Base_Class_CPP.h"

#include "Components/ArrowComponent.h"


AActor_Base_Class_CPP::AActor_Base_Class_CPP() :
	PArrowComponent(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;


	PArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("PArrowComponent"));
	//PArrowComponent->SetVisibility(true);
	//PArrowComponent->SetHiddenInGame(false);
	PArrowComponent->ArrowSize = 5.f;
	//PArrowComponent->SetupAttachment(RootComponent);
}

void AActor_Base_Class_CPP::BeginPlay()
{
	Super::BeginPlay();

}