// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HoloHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
struct FHoloWidgetControllerParameters;
class UScreenUIWidgetController;
class UHoloUserWidget;


/**
 * 
 */
UCLASS()
class HOLOSOULS_API AHoloHUD : public AHUD
{
	GENERATED_BODY()


public:
	UScreenUIWidgetController* GetScreenUIWidgetController(const FHoloWidgetControllerParameters& WidgetControllerParameters);

	void InitScreenUI(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet);
protected:
	virtual void  BeginPlay() override;
public:
	UPROPERTY(VisibleAnywhere, Category = "UI | Screen")
	TObjectPtr<UHoloUserWidget> ScreenUIWidget;

protected:
	UPROPERTY(EditAnywhere, Category = "UI | Screen")
	TSubclassOf<UUserWidget> ScreenUIWidgetClass;

	UPROPERTY(VisibleAnywhere, Category = "UI | Screen")
	TObjectPtr<UScreenUIWidgetController> ScreenUIWidgetController;

	UPROPERTY(EditAnywhere, Category = "UI | Screen")
	TSubclassOf<UScreenUIWidgetController> ScreenUIWidgetControllerClass;
};
