#include "Actors/CheckpointGate.h"
#include "Components/BoxComponent.h"
#include "Controllers/CarPlayerController.h"

ACheckpointGate::ACheckpointGate()
{
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(Box);

	Box->SetBoxExtent(FVector(1000.f));
	Box->SetLineThickness(32.0f);
	Box->SetCollisionProfileName(FName("OverlapAllDynamic"));
	Box->SetGenerateOverlapEvents(true);
	Box->bHiddenInGame = false;
}

void ACheckpointGate::NotifyActorBeginOverlap(AActor *Actor)
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(Actor->GetInstigator());
	if (PC->GetTarget() == this)
	{
		PC->SetTarget(NextGate);
		PC->IncrementCounter();
	}
}

ACheckpointGate *ACheckpointGate::GetNextGate() const
{
	return NextGate;
}
