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
	DrawBestTime();
	DrawCurrentTime();
	DrawCurrentLap();
}

void ACarHUD::DrawCheckpointsCounter()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	ACarGameMode *GM = Cast<ACarGameMode>(GetWorld()->GetAuthGameMode());
	if (PC && GM)
	{
		FString CheckpointText = FString::Printf(TEXT("Checkpoints: %i/%i"), PC->GetCheckpointCounter(), GM->GetGatesNumber());
		FLinearColor TextColor = FLinearColor::Blue;
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

void ACarHUD::DrawBestTime()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	if (PC)
	{
		FString BestTimeText = FString::Printf(TEXT("Best Time: %.3f"), PC->GetBestTime());
		FLinearColor BestTimeColor = FLinearColor::Green;
		float TextWidth, TextHeight;
		Canvas->StrLen(Font, BestTimeText, TextWidth, TextHeight);
		float TextX = 20.f;
		float TextY = Canvas->SizeY / 4;
		DrawText(BestTimeText, BestTimeColor, TextX, TextY, Font, 2.f);
	}
}

void ACarHUD::DrawCurrentTime()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	if (PC)
	{
		FString CurrentTimeText = FString::Printf(TEXT("Current Time: %.3f"), PC->GetCurrentTime());
		FLinearColor TextColor = FLinearColor::Red;
		float TextWidth, TextHeight;
		Canvas->StrLen(Font, CurrentTimeText, TextWidth, TextHeight);
		float TextX = 20.f;
		float TextY = (Canvas->SizeY / 4) + 40.f;
		DrawText(CurrentTimeText, TextColor, TextX, TextY, Font, 2.f);
	}
}

void ACarHUD::DrawCurrentLap()
{
	ACarPlayerController *PC = Cast<ACarPlayerController>(GetOwningPlayerController());
	if (PC)
	{
		FString CurrentLapText = FString::Printf(TEXT("Lap: %i"), PC->GetCurrentLap() + 1); //lap counter starts with 0
		FLinearColor TextColor = FLinearColor::Blue;
		float TextWidth, TextHeight;
		Canvas->StrLen(Font, CurrentLapText, TextWidth, TextHeight);
		float TextX = (Canvas->SizeX - TextWidth) / 2;
		float TextY = Canvas->SizeY - 70.f;
		DrawText(CurrentLapText, TextColor, TextX, TextY, Font, 2.f);
	}
}