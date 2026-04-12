#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckpointGate.generated.h"

class UBoxComponent;


UCLASS()
class UE_DRIVING_API ACheckpointGate : public AActor
{
	GENERATED_BODY()
	
public:	
	ACheckpointGate();

	virtual void NotifyActorBeginOverlap(AActor *Actor) override;
	ACheckpointGate *GetNextGate() const;

private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent *Box;
	UPROPERTY(EditAnywhere)
	ACheckpointGate *NextGate;
};
