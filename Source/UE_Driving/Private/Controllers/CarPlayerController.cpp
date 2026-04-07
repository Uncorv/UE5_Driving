#include "Controllers/CarPlayerController.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/CarPawn.h"

void ACarPlayerController::OnPossess(APawn *InPawn)
{
	Super::OnPossess(InPawn);

	CarPawn = Cast<ACarPawn>(InPawn);
	CarPawn->OnDestroyed.AddDynamic(this, &ACarPlayerController::OnPawnDestroyed);
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