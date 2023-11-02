// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "HoloCharacter.generated.h"

UCLASS(Abstract)
class HOLOSOULS_API AHoloCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHoloCharacter();
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE class UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* WMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAttributeSet> AttributeSet;
};
