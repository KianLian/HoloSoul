// Code by Kian


#include "UI/HoloHUD.h"

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerState.h"
#include "UI/WidgetController/ScreenUIWidgetController.h"
#include "UI/Widgets/HoloUserWidget.h"

UScreenUIWidgetController* AHoloHUD::GetScreenUIWidgetController(
	const FHoloWidgetControllerParameters& WidgetControllerParameters)
{
	if(!ScreenUIWidgetController)
	{
		ScreenUIWidgetController = NewObject<UScreenUIWidgetController>(this, ScreenUIWidgetControllerClass);
		ScreenUIWidgetController->SetWidgetControllerParameters(WidgetControllerParameters);
	}

	return ScreenUIWidgetController;
}

void AHoloHUD::InitScreenUI(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{

	checkf(ScreenUIWidgetClass, TEXT("No screen widget class, pls go to HUD bumb bro."));
	checkf(ScreenUIWidgetControllerClass, TEXT("No screen widget controller, pls go to HUD bumb bro."));

	if (ScreenUIWidgetClass)
	{
		ScreenUIWidget = CreateWidget<UHoloUserWidget>(GetWorld(), ScreenUIWidgetClass);
	
		const FHoloWidgetControllerParameters WidgetControllerParameters(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);

		UScreenUIWidgetController* WidgetController = GetScreenUIWidgetController(WidgetControllerParameters);
		ScreenUIWidget->SetWidgetController(WidgetController);
		ScreenUIWidget->AddToViewport();
	}
}

void AHoloHUD::BeginPlay()
{
	Super::BeginPlay();

	
}
