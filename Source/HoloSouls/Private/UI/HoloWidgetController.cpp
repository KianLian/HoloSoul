// Code by Kian


#include "UI/HoloWidgetController.h"

void UHoloWidgetController::SetWidgetControllerParameters(FHoloWidgetControllerParameters InParameters)
{
	if(!InParameters.StructPlayerController || !InParameters.StructPlayerState
		|| !InParameters.StructAbilitySystemComponent || !InParameters.StructAttributeSet)
	{
		UE_LOG(LogTemp, Error, TEXT("One or more parameters are null!"));
		return;
	}

	PlayerController = InParameters.StructPlayerController;
	PlayerState = InParameters.StructPlayerState;
	AbilitySystemComponent = InParameters.StructAbilitySystemComponent;
	AttributeSet = InParameters.StructAttributeSet;
}
