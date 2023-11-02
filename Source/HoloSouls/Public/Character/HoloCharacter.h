// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HoloCharacter.generated.h"

UCLASS(Abstract)
class HOLOSOULS_API AHoloCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHoloCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* WMeshComponent;
};
