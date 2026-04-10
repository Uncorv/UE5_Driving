#include "GameModes/CarGameMode.h"
#include "Actors/CheckpointGate.h"
#include "Controllers/CarPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/CarPawn.h"

ACarGameMode::ACarGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_CarPawn"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = ACarPlayerController::StaticClass();
}

void ACarGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor *> Checkpoints;
	UGameplayStatics::GetAllActorsOfClass(this, ACheckpointGate::StaticClass(), Checkpoints);
	StartGate = Cast<ACheckpointGate>(Checkpoints[0]);
}

ACheckpointGate *ACarGameMode::GetStartGate() const
{
	return StartGate;
}