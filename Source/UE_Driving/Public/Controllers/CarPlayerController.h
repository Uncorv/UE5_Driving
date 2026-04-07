#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CarPlayerController.generated.h"

class ACarPawn;

UCLASS()
class UE_DRIVING_API ACarPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn *InPawn) override;

	UFUNCTION()
	void OnPawnDestroyed(AActor *Actor);

private:
	UPROPERTY()
	ACarPawn *CarPawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACarPawn> CarPawnClass;
};
