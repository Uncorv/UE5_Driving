#include "GameModes/CarGameMode.h"
#include "Actors/CheckpointGate.h"
#include "Controllers/CarPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/CarPawn.h"
#include "UI/CarHUD.h"

ACarGameMode::ACarGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_CarPawn"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = ACarPlayerController::StaticClass();
	HUDClass = ACarHUD::StaticClass();
}

void ACarGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(this, ACheckpointGate::StaticClass(), CheckpointGates);
	StartGate = Cast<ACheckpointGate>(CheckpointGates[0]);
}

ACheckpointGate *ACarGameMode::GetStartGate() const
{
	return StartGate;
}

TArray<AActor *> ACarGameMode::GetAllCheckpointGates() const
{
	return CheckpointGates;
}

int ACarGameMode::GetGatesNumber() const
{
	return CheckpointGates.Num();
}