
#pragma once


#include "CoreMinimal.h"

#include "Actor_Base_Class_CPP.h"

#include "Target_Base_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API ATarget_Base_CPP : public AActor_Base_Class_CPP
{
	GENERATED_BODY()

#pragma region Class_Constructors_Public
public:

	ATarget_Base_CPP();

#pragma endregion
#pragma region Class_Variables_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Variables_Protected", meta = (AllowProtectedAccess = "true"))
		float fHealth;

#pragma endregion
#pragma region Class_Pointers_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Pointers_Protected", meta = (AllowProtectedAccess = "true"))
		class AInfinite_ShooterCharacter* PPlayer;

#pragma endregion
#pragma region Class_Components_Protected
protected:


#pragma endregion
#pragma region Class_Materials_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Materials_Protected", meta = (AllowProtectedAccess = "true"))
		class UMaterialInstanceDynamic* PDynamicMaterial;

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

#pragma endregion
#pragma region Class_Setters_Public
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		void Set_Player(class AInfinite_ShooterCharacter* Player);

#pragma endregion
#pragma region Class_Getters_Public 
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE float Get_fHealth() const
	{
		return fHealth;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class AInfinite_ShooterCharacter* Get_PPlayer() const
	{
		return PPlayer;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UMaterialInstanceDynamic* Get_PDynamicMaterial() const
	{
		return PDynamicMaterial;
	}

#pragma endregion
};