// Copyright Epic Games, Inc. All Rights Reserved.

#include "Infinite_ShooterProjectile.h"

#include "DrawDebugHelpers.h"
#include "Base_Classes/Target_Base_CPP.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Components/SphereComponent.h"


AInfinite_ShooterProjectile::AInfinite_ShooterProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AInfinite_ShooterProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;
	CollisionComp->SetWorldScale3D(FVector(5.f,5.f,5.f));
	
	//PStaticMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("PStaticMesh"));
	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AInfinite_ShooterProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		constexpr float fDamage = 50.f;


		//OtherActor->Destroy();	//destroy hit object
		if(ATarget_Base_CPP * Target = Cast<ATarget_Base_CPP>(OtherActor))
		{
			DrawDebugString(GetWorld(), OtherActor->GetActorLocation(), FString::Printf(TEXT("Hit object name: %s"), *OtherActor->GetName()), 0, FColor::Orange, 2.f, false, 3.f);
			
			Target->TakeDamage(fDamage, FPointDamageEvent(), GetInstigatorController(), this);
		}
		
	}
	Destroy();	//destroy the gun "bullet"
}