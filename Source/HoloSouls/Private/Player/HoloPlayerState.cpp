// Code by Kian


#include "Player/HoloPlayerState.h"

#include "Ability System/HoloAbilitySystemComponent.h"
#include "Ability System/HoloAttributeSet.h"

AHoloPlayerState::AHoloPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UHoloAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHoloAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AHoloPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
