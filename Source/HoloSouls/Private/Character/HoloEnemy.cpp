// Code by Kian


#include "Character/HoloEnemy.h"

#include "Ability System/HoloAbilitySystemComponent.h"
#include "Ability System/HoloAttributeSet.h"

AHoloEnemy::AHoloEnemy()
{
	AbilitySystemComponent = CreateDefaultSubobject<UHoloAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UHoloAttributeSet>(TEXT("AttributeSet"));
}

void AHoloEnemy::Highlight()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
}

void AHoloEnemy::UnHighlight()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
}

void AHoloEnemy::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
