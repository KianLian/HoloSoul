// Code by Kian


#include "Character/HoloEnemy.h"

AHoloEnemy::AHoloEnemy()
{
}

void AHoloEnemy::Highlight()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
}

void AHoloEnemy::UnHighlight()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
}
