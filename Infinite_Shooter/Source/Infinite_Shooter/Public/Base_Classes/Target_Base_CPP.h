
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Variables_Protected", meta = (AllowProtectedAccess = "true"))
		bool IsDestroyed;

#pragma endregion
#pragma region Class_Components_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Components_Protected", meta = (AllowProtectedAccess = "true"))
		class UWidgetComponent* PWidgetComponent;

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
#pragma region Class_Getters_Public 
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE float Get_fHealth() const
	{
		return fHealth;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE bool Get_IsDestroyed() const
	{
		return IsDestroyed;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UWidgetComponent* Get_PWidgetComponent() const
	{
		return PWidgetComponent;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UMaterialInstanceDynamic* Get_PDynamicMaterial() const
	{
		return PDynamicMaterial;
	}

#pragma endregion
};