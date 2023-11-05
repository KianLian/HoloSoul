// Code by Kian


#include "Ability System/HoloAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UHoloAttributeSet::UHoloAttributeSet()
{
	InitHealth(150.0f);
	InitMaxHealth(150.0f);
	InitMana(100.0f);
	InitMaxMana(100.0f);
}

void UHoloAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UHoloAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHoloAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHoloAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UHoloAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UHoloAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHoloAttributeSet, Health, OldHealth);
}

void UHoloAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHoloAttributeSet, MaxHealth, OldMaxHealth);
}

void UHoloAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHoloAttributeSet, Mana, OldMana);
}


void UHoloAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UHoloAttributeSet, MaxMana, OldMaxMana);	
}
