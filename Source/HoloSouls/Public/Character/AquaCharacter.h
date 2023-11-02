// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "Character/HoloCharacter.h"
#include "AquaCharacter.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class HOLOSOULS_API AAquaCharacter : public AHoloCharacter
{
	GENERATED_BODY()


public:
		AAquaCharacter();

protected:

	void BeginPlay() override;
	UFUNCTION()
	void OnDataDisplaySphereOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnDataDisplaySphereOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
protected:
		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		TObjectPtr<class USpringArmComponent> SpringArmComponent;
		
		/** Follow camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

		/** Sphere that highlights and give Info about the item*/
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> DataDisplaySphere;
};
