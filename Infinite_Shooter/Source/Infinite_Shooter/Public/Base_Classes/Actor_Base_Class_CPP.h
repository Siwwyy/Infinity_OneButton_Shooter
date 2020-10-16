
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Base_Class_CPP.generated.h"

UCLASS()
class INFINITE_SHOOTER_API AActor_Base_Class_CPP : public AActor
{
	GENERATED_BODY()

#pragma region Class_Constructors_Protected
protected:

	AActor_Base_Class_CPP();

#pragma endregion
#pragma region Class_Components_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Components_Protected", meta = (AllowProtectedAccess = "true"))
		class UStaticMeshComponent* PStaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Components_Protected", meta = (AllowProtectedAccess = "true"))
		class UArrowComponent* PArrowComponent;

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

#pragma endregion
#pragma region Class_Getters_Public 
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UStaticMeshComponent* Get_PStaticMeshComponent() const
	{
		return PStaticMeshComponent;
	}

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UArrowComponent* Get_PArrowComponent() const
	{
		return PArrowComponent;
	}

#pragma endregion
};