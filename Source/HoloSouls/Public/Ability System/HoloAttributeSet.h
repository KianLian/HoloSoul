// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "HoloAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

//ATTRIBUTE_ACCESSORS(UMyHealthSet, Health)

/**
 * 
 */
UCLASS()
class HOLOSOULS_API UHoloAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UHoloAttributeSet();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData &OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	ATTRIBUTE_ACCESSORS(UHoloAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UHoloAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UHoloAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UHoloAttributeSet, MaxMana)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Health", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes | Mana", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
};
