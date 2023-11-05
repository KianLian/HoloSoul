// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HoloWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UHoloAttributeSet;

USTRUCT(BlueprintType)
struct FHoloWidgetControllerParameters
{
	GENERATED_BODY()

	FHoloWidgetControllerParameters() {}
	FHoloWidgetControllerParameters(class APlayerController* InPlayerController,
		class APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComponent,
		UAttributeSet* InAttributeSet) :
		StructPlayerController (InPlayerController),
		StructPlayerState (InPlayerState),
		StructAbilitySystemComponent(InAbilitySystemComponent),
		StructAttributeSet(InAttributeSet)
	{}

	TObjectPtr<class APlayerController>	StructPlayerController = nullptr;
	TObjectPtr<class APlayerState> 	StructPlayerState = nullptr;
	TObjectPtr<class UAbilitySystemComponent> StructAbilitySystemComponent = nullptr;
	TObjectPtr<class UAttributeSet> StructAttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class HOLOSOULS_API UHoloWidgetController : public UObject
{
	GENERATED_BODY()

public:
//	UHoloWidgetController();

	UFUNCTION(BlueprintCallable, Category = "HoloUI")
	void SetWidgetControllerParameters(FHoloWidgetControllerParameters InParameters);
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HoloUI")
	TObjectPtr<class APlayerController>	PlayerController;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HoloUI")
	TObjectPtr<class APlayerState> 	PlayerState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HoloUI")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HoloUI")
	TObjectPtr<UAttributeSet> AttributeSet;
};
