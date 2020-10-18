// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Infinite_ShooterHUD.generated.h"

UCLASS()
class AInfinite_ShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AInfinite_ShooterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};