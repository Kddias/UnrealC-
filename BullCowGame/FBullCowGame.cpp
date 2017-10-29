#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 6;
	constexpr int32 CURRENT_TRY = 1;
	//the right method would be to random a word from a list.
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = CURRENT_TRY;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

FBullCowGame::FBullCowGame()
{
	this->Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidaty(FString guess) const
{
	if (guess.length() != MyHiddenWord.length())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
	
}


//receives a valid guess, incriments turns, and return cows and bulls count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 size = MyHiddenWord.length();
	
	for (int32 i = 0; i < size; i++)
	{ 
		for (int32 j = 0; j < size; j++)
		{ 
			if (Guess[j] == MyHiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.Bulls ++;
				}
				else
				{
					BullCowCount.Cows ++;
				}
			}  
		}
	}
	
	if (BullCowCount.Bulls == MyHiddenWord.length()) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}
