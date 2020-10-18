
#include "Base_Classes/Target_Base_CPP.h"
#include "Infinite_Shooter/Infinite_ShooterCharacter.h"
#include "Infinite_Shooter/Public/Widgets/HealthBar_CPP.h"

#include "Materials/MaterialInstanceDynamic.h"

#include "Blueprint/UserWidget.h"

#include "Components/WidgetComponent.h"
#include "UObject/ConstructorHelpers.h"


ATarget_Base_CPP::ATarget_Base_CPP() :
	AActor_Base_Class_CPP(),
	fHealth(100.f),
	IsDestroyed(false),
	PWidgetComponent(nullptr),
	PDynamicMaterial(nullptr)
{
	//PStaticMeshComponent->SetSimulatePhysics(true);		//set this static mesh component to be able to receive OnHit event from projectile component
	PrimaryActorTick.bCanEverTick = true;

	PWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("PWidgetComponent"));
	PWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	PWidgetComponent->SetRelativeLocation(PStaticMeshComponent->GetRelativeLocation());
	PWidgetComponent->SetupAttachment(PStaticMeshComponent);

	static ConstructorHelpers::FClassFinder<UUserWidget> Widget_Class(TEXT("WidgetBlueprint'/Game/BP_Classes/Widgets/HealthBar_BP.HealthBar_BP_C'"));

	if (Widget_Class.Succeeded())
	{
		PWidgetComponent->SetWidgetClass(Widget_Class.Class);
	}
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
		IsDestroyed = true;
		PStaticMeshComponent->SetVisibility(false);
	}

	return ActualDamage;
}