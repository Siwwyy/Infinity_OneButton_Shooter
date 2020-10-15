

#pragma once

#include "CoreMinimal.h"

#include "Base_Classes/Actor_Base_Class_CPP.h"

#include "Spawner_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API ASpawner_CPP : public AActor_Base_Class_CPP
{
	GENERATED_BODY()

#pragma region Class_Constructors_Public
public:

	ASpawner_CPP();

#pragma endregion
#pragma region Class_Variables_Protected
protected:

	struct FTimerHandle SpawnTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Variables_Protected", meta = (AllowProtectedAccess = "true"))
		TSubclassOf<class ATarget_CPP> Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Variables_Protected", meta = (AllowProtectedAccess = "true"))
		class AInfinite_ShooterCharacter* PPlayer;

#pragma endregion
#pragma region Class_Components_Protected
protected:



#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Class_Functions_Public")
		void Spawn();

#pragma endregion
#pragma region Class_Getters_Protected
protected:

	UFUNCTION(BlueprintCallable, Category = "Class_Functions_Protected")
		FORCEINLINE int32 Get_RandomInt(int32 begin, int32 end) const
	{
		return FMath::RandRange(begin, end);
	}

#pragma endregion
};