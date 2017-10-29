#include "FBullCowGame.h"
#include <map>
#define TMap std::map

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
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
	if (!IsIsogram(guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(!IsLowerCase(guess))
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (guess.length() != MyHiddenWord.length())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
	
}

//support function to check if the guess is really a isogram
bool FBullCowGame::IsIsogram(FString guess) const
{
	if (guess.length() <= 1)
	{
		return true;
	}

	//declaring a map to hold if a letter from the guess word has been seen
	TMap <char, bool> LetterSeen;
	for (auto letter : guess) 
	{
		letter = tolower(letter);
		if (LetterSeen[letter])
		{
			return false;
		}
		else
		{
			LetterSeen[letter] = true;
		}
	}
	

	return true;
}

bool FBullCowGame::IsLowerCase(FString guess) const
{
	for (auto letter : guess) 
	{
		if (!islower(letter))
		{
		return false;
		}
	}

	return true;
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
