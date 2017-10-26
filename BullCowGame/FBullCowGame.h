#pragma once
#include <string>

class FBullCowGame {
public:

	FBullCowGame();

	int GetMaxTries() const; //Return the Maximum amount of tries.
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool CheckGuessValidaty(std::string);
	//provide a method for counting bulls and cows and increment tries.


//Please try and ignore this private stuff for now
private:
	int MyCurrentTry;
	int MyMaxTries;	
};