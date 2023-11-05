// Code by Kian


#include "Effectors/HoloEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Ability System/HoloAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AHoloEffectActor::AHoloEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetSphereRadius(50.f);
}

// Called when the game starts or when spawned
void AHoloEffectActor::BeginPlay()
{
	Super::BeginPlay();

	if (SphereComponent != nullptr && HasAuthority()) {
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		SphereComponent->IgnoreActorWhenMoving(this, true);
		// Bind the overlap event functions
		SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AHoloEffectActor::OnOverlapBegin);
		SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AHoloEffectActor::OnOverlapEnd);
	}
}

void AHoloEffectActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 if(auto ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	 {
	 	if(const auto AbilitySystemComponent = ASCInterface->GetAbilitySystemComponent())
	 	{
			auto HoloSet = Cast<UHoloAttributeSet>(AbilitySystemComponent->GetAttributeSet(UHoloAttributeSet::StaticClass()));
	 		if(HoloSet)
			{
				const_cast<UHoloAttributeSet*>(HoloSet)->SetHealth(HoloSet->GetHealth() + 25.f);
				//HoloSet->SetHealth(HoloSet->GetHealth() + 25.f);
				Destroy();
			}
	 	}
	 }
}

void AHoloEffectActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


