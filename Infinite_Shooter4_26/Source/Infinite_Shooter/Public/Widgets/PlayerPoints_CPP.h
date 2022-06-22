
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerPoints_CPP.generated.h"


UCLASS()
class INFINITE_SHOOTER_API UPlayerPoints_CPP : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	void Set_Text(int32 Value);

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* Text_Block = nullptr;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* Game_Points = nullptr;
};