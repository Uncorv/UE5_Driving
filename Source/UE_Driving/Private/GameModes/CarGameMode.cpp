#include "GameModes/CarGameMode.h"
#include "Controllers/CarPlayerController.h"
#include "Pawns/CarPawn.h"

ACarGameMode::ACarGameMode()
{
	DefaultPawnClass = CarPawnClass;
	PlayerControllerClass = CarPlayerControllerClass;
}