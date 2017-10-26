#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	constexpr int CURRENT_TRY = 1;

	MyCurrentTry = 1;
	MyMaxTries = CURRENT_TRY;
	return;
}

FBullCowGame::FBullCowGame()
{
	this->Reset();
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidaty(std::string)
{
	return false;
}
