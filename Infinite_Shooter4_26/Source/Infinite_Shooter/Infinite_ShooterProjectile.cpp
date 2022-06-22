// Copyright Epic Games, Inc. All Rights Reserved.

#include "Infinite_ShooterProjectile.h"

#include "Base_Classes/Target_Base_CPP.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


AInfinite_ShooterProjectile::AInfinite_ShooterProjectile()
{
	CollisionComp->OnComponentHit.AddDynamic(this, &AInfinite_ShooterProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Die after 3 seconds by default
	InitialLifeSpan = 2.0f;
}

void AInfinite_ShooterProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AInfinite_ShooterProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		constexpr float fDamage = 50.f;

		if (ATarget_Base_CPP* Target = Cast<ATarget_Base_CPP>(OtherActor))
		{
			Target->TakeDamage(fDamage, FPointDamageEvent(), GetInstigatorController(), this);
		}
	}
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, FTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint));
	Destroy();	//destroy the gun "bullet"
}