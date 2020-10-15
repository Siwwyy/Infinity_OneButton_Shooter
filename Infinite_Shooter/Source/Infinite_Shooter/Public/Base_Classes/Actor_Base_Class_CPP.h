// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_Base_Class_CPP.generated.h"

UCLASS()
class INFINITE_SHOOTER_API AActor_Base_Class_CPP : public AActor
{
	GENERATED_BODY()

#pragma region Class_Constructors_Public
public:

	AActor_Base_Class_CPP();

#pragma endregion
#pragma region Class_Constructors_Protected
protected:



#pragma endregion
#pragma region Class_Variables_Public
public:



#pragma endregion 
#pragma region Class_Variables_Protected
protected:



#pragma endregion
#pragma region Class_Components_Public
public:



#pragma endregion
#pragma region Class_Components_Protected
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class_Components_Protected", meta = (AllowProtectedAccess = "true"))
		class UStaticMeshComponent* PStaticMeshComponent;

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

#pragma endregion
#pragma region Class_Functions_Protected
protected:



#pragma endregion
#pragma region Class_Delegates_Public
public:



#pragma endregion
#pragma region Class_Delegates_Protected
protected:



#pragma endregion
#pragma region Class_Setters_Public
public:



#pragma endregion
#pragma region Class_Setters_Protected
protected:



#pragma endregion 
#pragma region Class_Getters_Public 
public:

	UFUNCTION(BlueprintCallable, Category = "Class_Getters_Public")
		FORCEINLINE class UStaticMeshComponent* Get_PStaticMeshComponent() const
	{
		return PStaticMeshComponent;
	}

#pragma endregion
#pragma region Class_Getters_Protected
protected:



#pragma endregion
};