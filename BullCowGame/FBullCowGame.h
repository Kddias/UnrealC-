#pragma once
#include <string>

class FBullCowGame {
public:

	int GetMaxTries() const; //Return the Maximum amount of tries.
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); //TODO make a more rich return value.
	bool CheckGuessValidaty(std::string);



//Please try and ignore this private stuff for now
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;	
};