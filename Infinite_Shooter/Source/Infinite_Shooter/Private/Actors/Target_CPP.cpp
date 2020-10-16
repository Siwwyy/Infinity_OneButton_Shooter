

#include "Infinite_Shooter/Public/Actors/Target_CPP.h"

#include "Infinite_Shooter/Infinite_ShooterCharacter.h"


ATarget_CPP::ATarget_CPP() :
	ATarget_Base_CPP(),
	Velocity(100.f)
{
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/EngineMeshes/Sphere.Sphere'"));

	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/MyMaterial.MyMaterial'"));
	//if (MeshAsset.Succeeded() && MaterialAsset.Succeeded())
	//{
	//	PStaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	//	PStaticMeshComponent->SetMaterial(0, MaterialAsset.Object);
	//	PStaticMeshComponent->SetWorldScale3D(FVector(0.3f));
	//}
	//PStaticMeshComponent->SetMobility(EComponentMobility::Movable);

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

	float blend = 0.5f + static_cast<float>(FMath::Cos(GetWorld()->TimeSeconds) / 2);
	PDynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);

	MoveForward(DeltaSeconds);	//move forward this
}