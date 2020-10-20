
#pragma once

#include "CoreMinimal.h"


#include "Base_Classes/Target_Base_CPP.h"
#include "Target_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API ATarget_CPP : public ATarget_Base_CPP
{
	GENERATED_BODY()

#pragma region Class_Constructors_Public
public:

	ATarget_CPP();

#pragma endregion
#pragma region Class_Variables_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		float Velocity;

#pragma endregion
#pragma region Class_Components_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		class UParticleSystemComponent* PPatricle_System;

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

	void MoveForward(float Value);

#pragma endregion
#pragma region Class_Functions_Protected
protected:

	virtual void Tick(float DeltaSeconds) override;

#pragma endregion
#pragma region Class_Setters_Public
public:

	void Set_Velocity(float Value);

#pragma endregion
#pragma region Class_Getters_Public
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE float Get_Velocity() const
	{
		return Velocity;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UParticleSystemComponent* Get_Patricle_System() const
	{
		return PPatricle_System;
	}

#pragma endregion
};