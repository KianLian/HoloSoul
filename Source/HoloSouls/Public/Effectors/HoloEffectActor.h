// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HoloEffectActor.generated.h"

class USphereComponent;

UCLASS()
class HOLOSOULS_API AHoloEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHoloEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	TObjectPtr<USphereComponent> SphereComponent;

};
