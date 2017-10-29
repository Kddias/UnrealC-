#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase,
	Contain_Symbols,
	Contain_Numbers,
};

class FBullCowGame {
public:

	FBullCowGame();

	int32 GetMaxTries() const; //Return the Maximum amount of tries.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidaty(FString guess) const;
	

	void Reset(); //TODO make a more rich return value.
	
	//provide a method for counting bulls and cows and increment tries.
	FBullCowCount SubmitValidGuess(FString guess);


//Please try and ignore this private stuff for now
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};