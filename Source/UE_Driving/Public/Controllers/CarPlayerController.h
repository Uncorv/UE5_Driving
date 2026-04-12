#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CarPlayerController.generated.h"

class ACarPawn;
class ACheckpointGate;

UCLASS()
class UE_DRIVING_API ACarPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn *InPawn) override;
	virtual void BeginPlay() override;

	void StartCheckpointsDriving();
	void FinishCheckpointsDriving();
	bool IsAllGatesPassed() const;
	void IncrementCounter();
	void SetTarget(ACheckpointGate *Gate);
	ACheckpointGate *GetTarget() const;
	int GetCheckpointCounter() const;
	int GetCurrentLap() const;
	float GetBestTime() const;
	float GetCurrentTime() const;


	UFUNCTION()
	void OnPawnDestroyed(AActor *Actor);

private:
	void UpdateTimer();

	UPROPERTY()
	ACarPawn *CarPawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACarPawn> CarPawnClass;
	UPROPERTY()
	ACheckpointGate *Target;

	int CheckpointCounter = 0;
	int LapCounter = 0;
	float StartTime = 0.f;
	float CurrentTime = 0.f;
	float BestTime = 0.f;
	FTimerHandle Timer;
};
