#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CarGameMode.generated.h"

class ACarPawn;
class ACarPlayerController;
class ACheckpointGate;

UCLASS()
class UE_DRIVING_API ACarGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACarGameMode();

	virtual void BeginPlay() override;

	ACheckpointGate *GetStartGate() const;
	TArray<AActor *> GetAllCheckpointGates() const;
	int GetGatesNumber() const;

private:
	UPROPERTY()
	ACheckpointGate *StartGate;
	UPROPERTY()
	TArray<AActor *> CheckpointGates;
};
