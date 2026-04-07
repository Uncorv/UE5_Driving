#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CarGameMode.generated.h"

class ACarPawn;
class ACarPlayerController;

UCLASS()
class UE_DRIVING_API ACarGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACarGameMode();

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACarPawn> CarPawnClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACarPlayerController> CarPlayerControllerClass;
	
};
