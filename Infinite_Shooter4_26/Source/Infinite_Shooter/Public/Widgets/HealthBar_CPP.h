
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "HealthBar_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API UHealthBar_CPP : public UUserWidget
{
	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;
	void Set_Bar_Value_Percent(float Value);

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* health_value = nullptr;
};