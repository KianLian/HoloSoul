// Code by Kian

#pragma once

#include "CoreMinimal.h"
#include "HighlightInterface.h"
#include "Character/HoloCharacter.h"
#include "HoloEnemy.generated.h"

/**
 * 
 */
UCLASS()
class HOLOSOULS_API AHoloEnemy : public AHoloCharacter, public IHighlightInterface
{
	GENERATED_BODY()

public:
	AHoloEnemy();
	virtual void Highlight() override;
	virtual void UnHighlight() override;
};
