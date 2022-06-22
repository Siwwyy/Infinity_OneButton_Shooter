

#include "Infinite_Shooter/Public/Widgets/HealthBar_CPP.h"


#include "Runtime/UMG/Public/Components/ProgressBar.h"

void UHealthBar_CPP::NativeConstruct()
{

}

void UHealthBar_CPP::Set_Bar_Value_Percent(float Value)
{
	health_value->SetPercent(Value);
}