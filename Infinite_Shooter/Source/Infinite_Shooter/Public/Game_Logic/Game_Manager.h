// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game_Manager.generated.h"

UCLASS()
class INFINITE_SHOOTER_API AGame_Manager : public AActor
{
	GENERATED_BODY()


#pragma region Class_Constructors_Public
public:

	AGame_Manager();

#pragma endregion
#pragma region Class_Functions_Public
public:

	virtual void BeginPlay() override;

#pragma endregion
#pragma region Class_Getters_Public 
public:


#pragma endregion
};