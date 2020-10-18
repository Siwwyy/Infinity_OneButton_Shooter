

#include "Infinite_Shooter/Public/Widgets/PlayerPoints_CPP.h"

#include "Runtime/UMG/Public/Components/TextBlock.h"


void UPlayerPoints_CPP::NativeConstruct()
{
	
}

void UPlayerPoints_CPP::Set_Text(int32 Value)
{
	FNumberFormattingOptions Options;	//set formatting option
	Options.SetMaximumFractionalDigits(0);	//set fractional digits 0 means the number 0.1 -> will be 0
	Text_Block->SetText(FText::AsNumber(Value, &Options));
}