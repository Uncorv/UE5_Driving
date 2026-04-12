#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CarHUD.generated.h"

UCLASS()
class UE_DRIVING_API ACarHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void DrawHUD() override;

	void DrawCheckpointsCounter();
	void DrawFinishMessage();
	void DrawBestTime();
	void DrawCurrentTime();
	void DrawCurrentLap();

private:
	UPROPERTY()
	UFont *Font;
};
