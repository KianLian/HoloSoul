// Code by Kian


#include "Character/AquaCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interfaces/HighlightInterface.h"

AAquaCharacter::AAquaCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetMesh());
	SpringArmComponent->TargetArmLength = 400.0f; 
	SpringArmComponent->bUsePawnControlRotation = true; 

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 550.f, 0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	DataDisplaySphere = CreateDefaultSubobject<USphereComponent>(("DataDisplaySphere"));
	DataDisplaySphere->SetupAttachment(GetMesh());
	DataDisplaySphere->SetSphereRadius(200.f);
	DataDisplaySphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	DataDisplaySphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}

void AAquaCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (DataDisplaySphere != nullptr && HasAuthority()) {
		DataDisplaySphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		DataDisplaySphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		DataDisplaySphere->IgnoreActorWhenMoving (this, true);
		// Bind the overlap event functions
		DataDisplaySphere->OnComponentBeginOverlap.AddDynamic(this, &AAquaCharacter::OnDataDisplaySphereOverlapBegin);
		DataDisplaySphere->OnComponentEndOverlap.AddDynamic(this, &AAquaCharacter::OnDataDisplaySphereOverlapEnd);
	}
}

void AAquaCharacter::OnDataDisplaySphereOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(auto ActorInSphere = Cast<IHighlightInterface>(OtherActor))
	{
		ActorInSphere->Highlight();
	}
	else
	{
				
	}
}

void AAquaCharacter::OnDataDisplaySphereOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (auto ActorInSphere = Cast<IHighlightInterface>(OtherActor))
	{
		ActorInSphere->UnHighlight();
	}
	
}

