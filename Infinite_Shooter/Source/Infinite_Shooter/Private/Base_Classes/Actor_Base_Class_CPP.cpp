

#include "Base_Classes/Actor_Base_Class_CPP.h"

#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"


AActor_Base_Class_CPP::AActor_Base_Class_CPP() :
	PStaticMeshComponent(nullptr),
	PArrowComponent(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;

	PStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PStaticMeshComponent"));
	PStaticMeshComponent->bCastShadowAsTwoSided = false;
	RootComponent = PStaticMeshComponent;

	PArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("PArrowComponent"));
	PArrowComponent->SetVisibility(false);
	PArrowComponent->SetHiddenInGame(true);
	PArrowComponent->ArrowSize = 5.f;
	PArrowComponent->SetupAttachment(PStaticMeshComponent);
}

void AActor_Base_Class_CPP::BeginPlay()
{
	Super::BeginPlay();

}