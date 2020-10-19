// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor_Base_Class_CPP.h"

#include "Projectile_Base_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API AProjectile_Base_CPP : public AActor_Base_Class_CPP
{
	GENERATED_BODY()
	
#pragma region Class_Constructors_Protected
protected:

	AProjectile_Base_CPP();

#pragma endregion
#pragma region Class_Components_Protected
protected:


#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

#pragma endregion
#pragma region Class_Getters_Public 
public:


#pragma endregion
};