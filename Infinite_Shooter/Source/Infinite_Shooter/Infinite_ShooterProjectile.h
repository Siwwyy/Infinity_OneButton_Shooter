
#pragma once

#include "CoreMinimal.h"
#include "Base_Classes/Projectile_Base_CPP.h"

#include "Infinite_ShooterProjectile.generated.h"

UCLASS(config = Game)
class AInfinite_ShooterProjectile : public AProjectile_Base_CPP
{
	GENERATED_BODY()

#pragma region Class_Constructors_protected
public:

	AInfinite_ShooterProjectile();

#pragma endregion
#pragma region Class_Components_Protected
protected:

	/** Projectile at bullet's impact */
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

	/** Returns Projectile **/
	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UParticleSystem* Get_ImpactParticles() const
	{
		return ImpactParticles;
	}

#pragma endregion 
};