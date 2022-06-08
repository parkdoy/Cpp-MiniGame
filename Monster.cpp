#include "Monster.h"
#include "Engine.h"
#include <time.h>
#include"World.h"
#include "Player.h"

AMonster::AMonster()
	:AActor()
{
	R = 255;
	G = 255;
	B = 0;
	LoadBMP("Data/Slime.bmp");
}

AMonster::~AMonster()
{
	
}

AMonster::AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	:AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	srand(time(nullptr));
	R = 255;
	G = 255;
	B = 0;

	LoadBMP("Data/Slime.bmp");
}

void AMonster::Tick()
{
	ElapsedTimeMon += GEngine->GetWorldDeltaSeconds();
	if (ElapsedTimeMon >= ProcessTimeMon)
	{
		int MonsterMove = rand() % 4;
		switch (MonsterMove)
		{
		case 0:
			Y = (PredictCollision(X, Y - 1) == false) ? Y - 1 : Y;
			break;
		case 1:
			Y = (PredictCollision(X, Y + 1) == false) ? Y + 1 : Y;
			break;
		case 2:
			X = (PredictCollision(X - 1, Y) == false) ? X - 1 : X;
			break;
		case 3:
			X = (PredictCollision(X + 1, Y) == false) ? X + 1 : X;
			break;
		}

		ElapsedTimeMon = 0;
	}

	if (IsPlayer())
	{
		SDL_Log("Game Over");
		GEngine->QuitGame();
	}
}

bool AMonster::IsPlayer()
{
	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		if (Actor->X == X && Actor->Y == Y)
		{
			APlayer* Player = dynamic_cast<APlayer*>(Actor);
			if (Player != nullptr)
			{
				return true;
			}
		}
	}

	return false;
}