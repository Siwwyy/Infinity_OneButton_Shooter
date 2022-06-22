
#pragma once

#include "CoreMinimal.h"

#include "Base_Classes/Actor_Base_Class_CPP.h"

#include "Game_Manager.generated.h"



#pragma region Enums

UENUM(BlueprintType, Category = "Enums")
enum class Game_Difficultness : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Easy = 10 UMETA(DisplayName = "Easy"),
	Medium = 25 UMETA(DisplayName = "Medium"),
	Hard = 50 UMETA(DisplayName = "Hard")
};

#pragma endregion


UCLASS()
class INFINITE_SHOOTER_API AGame_Manager : public AActor_Base_Class_CPP
{
	GENERATED_BODY()


#pragma region Class_Constructors_Public
public:

	AGame_Manager();

#pragma endregion
#pragma region Class_Variables_Protected
protected:

	FTimerHandle Timer_Game_MainLoop;
	FTimerHandle Timer_Game_SpawnLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))

	Game_Difficultness Difficultness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		int32 Game_Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		class AInfinite_ShooterCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		class ASpawner_CPP* Spawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Class_Variables_Protected, meta = (AllowProtectedAccess = "true"))
		TArray<class ATarget_Base_CPP*> Array_Target;

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

	void Game_Loop();

	void Add_Target();

#pragma endregion
#pragma region Class_Functions_Private
private:

	void Delete_DestroyedTarget();

	void Increase_Game_Points(int32 Increase_Value);

	void Change_Game_Difficultness();

	bool Is_End();

#pragma endregion
#pragma region Class_Getters_Public 
public:

	FORCEINLINE class ATarget_Base_CPP* Get_Array_Target(const std::size_t index) const
	{
		return Array_Target[index];	//currently returns nothing
	}

#pragma endregion
};