#include "UI/CarHUD.h"
#include "Controllers/CarPlayerController.h"
#include "Engine/Canvas.h"
#include "GameModes/CarGameMode.h"

void ACarHUD::BeginPlay()
{
	Super::BeginPlay();

	Font = GEngine->GetMediumFont();
}

void ACarHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawCheckpointsCounter();
	DrawFinishMessage();
}

void ACarHUD::DrawCheckpointsCounter()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	ACarGameMode *GM = Cast<ACarGameMode>(GetWorld()->GetAuthGameMode());
	if (PC && GM)
	{
		FString CheckpointText = FString::Printf(TEXT("Checkpoints: %i/%i"), PC->GetCheckpointCounter(), GM->GetGatesNumber());
		FLinearColor TextColor = FLinearColor::Red;
		float TextWidth, TextHeight;
		Canvas->StrLen(Font, CheckpointText, TextWidth, TextHeight);
		float TextX = (Canvas->SizeX - TextWidth) / 2;
		float TextY = Canvas->SizeY - 40.f;
		DrawText(CheckpointText, TextColor, TextX, TextY, Font, 2.f);
	}
}

void ACarHUD::DrawFinishMessage()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	ACarGameMode *GM = Cast<ACarGameMode>(GetWorld()->GetAuthGameMode());
	if (PC && GM)
	{
		if (PC->GetCheckpointCounter() >= GM->GetGatesNumber())
		{
			FString FinishText = FString::Printf(TEXT("Driving is Finished!"));
			FLinearColor TextColor = FLinearColor::Yellow;
			float TextWidth, TextHeight;
			Canvas->StrLen(Font, FinishText, TextWidth, TextHeight);
			float TextX = (Canvas->SizeX - TextWidth) / 2;
			float TextY = Canvas->SizeY / 4;
			DrawText(FinishText, TextColor, TextX, TextY, Font, 2.f);
		}
	}
}