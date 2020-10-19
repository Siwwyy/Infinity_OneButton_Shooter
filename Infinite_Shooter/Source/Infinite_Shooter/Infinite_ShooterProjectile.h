// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Infinite_ShooterProjectile.generated.h"

UCLASS(config = Game)
class AInfinite_ShooterProjectile : public AActor
{
	GENERATED_BODY()

#pragma region Class_Constructors_protected
public:

	AInfinite_ShooterProjectile();

#pragma endregion
#pragma region Class_Components_Protected
protected:

	/** Sphere collision component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
		class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement, meta = (AllowProtectedAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;

	/** Seconds to wait between shoots */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UParticleSystem* ImpactParticles;

#pragma endregion 
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

	/** called when projectile hits something */
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

#pragma endregion 
#pragma region Class_Getters_Public 
public:

	/** Returns CollisionComp subobject **/
	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class USphereComponent* GetCollisionComp() const
	{
		return CollisionComp;
	}

	/** Returns ProjectileMovement subobject **/
	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const
	{
		return ProjectileMovement;
	}
	
#pragma endregion 
};