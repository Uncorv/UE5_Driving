#include "Controllers/CarPlayerController.h"
#include "Actors/CheckpointGate.h"
#include "GameFramework/PlayerStart.h"
#include "GameModes/CarGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/CarPawn.h"

void ACarPlayerController::OnPossess(APawn *InPawn)
{
	Super::OnPossess(InPawn);

	CarPawn = Cast<ACarPawn>(InPawn);
	CarPawn->OnDestroyed.AddDynamic(this, &ACarPlayerController::OnPawnDestroyed);
}

void ACarPlayerController::BeginPlay()
{
	Super::BeginPlay();

	StartCheckpointsDriving();
}

void ACarPlayerController::StartCheckpointsDriving()
{
	if (ACarGameMode *GM = Cast<ACarGameMode>(GetWorld()->GetAuthGameMode()))
	{
		SetTarget(GM->GetStartGate());
	}
}

void ACarPlayerController::FinishCheckpointsDriving()
{
		SetTarget(nullptr);
}

bool ACarPlayerController::IsAllGatesPassed() const
{
	if (ACarGameMode *GM = Cast<ACarGameMode>(GetWorld()->GetAuthGameMode()))
	{
		return (CheckpointCounter >= GM->GetAllCheckpointGates().Num());
	}
	return false;
}

int ACarPlayerController::GetCheckpointCounter() const
{
	return CheckpointCounter;
}

void ACarPlayerController::OnPawnDestroyed(AActor *Actor)
{
	TArray<AActor *> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), Actors);
	if (!Actors.IsEmpty())
	{
		APlayerStart *PS = Cast<APlayerStart>(Actors[0]);
		if (PS)
		{
			FTransform PSTransform = PS->GetActorTransform();
			ACarPawn *Car = GetWorld()->SpawnActor<ACarPawn>(CarPawnClass, PSTransform);
			if (Car)
			{
				Possess(Car);
			}
		}
	}
}

void ACarPlayerController::IncrementCounter()
{
	++CheckpointCounter;

	if (IsAllGatesPassed())
	{
		FinishCheckpointsDriving();
	}
}

void ACarPlayerController::SetTarget(ACheckpointGate *Gate)
{
	Target = Gate;
}

ACheckpointGate *ACarPlayerController::GetTarget() const
{
	return Target;
}