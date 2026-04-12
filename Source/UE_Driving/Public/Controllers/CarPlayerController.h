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

	UFUNCTION()
	void OnPawnDestroyed(AActor *Actor);

private:
	UPROPERTY()
	ACarPawn *CarPawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACarPawn> CarPawnClass;
	UPROPERTY()
	ACheckpointGate *Target;
	int CheckpointCounter = 0;
};
