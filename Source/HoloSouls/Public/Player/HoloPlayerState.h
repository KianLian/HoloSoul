// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "HoloPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class HOLOSOULS_API AHoloPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHoloPlayerState();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE class UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAttributeSet> AttributeSet;
};
