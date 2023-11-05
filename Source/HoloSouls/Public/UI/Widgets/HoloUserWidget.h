// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HoloUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOLOSOULS_API UHoloUserWidget : public UUserWidget
{
	GENERATED_BODY()



public:
	UFUNCTION(BlueprintCallable, Category = "HoloUI")
	void SetWidgetController(UObject* Controller);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HoloUI")
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "HoloUI")
	void WidgetConstructSet();
};
