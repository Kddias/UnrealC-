/* This is the console executable, that makes use of the BullCow class
this acts like the view in a MVC pattern, and is responsable for all 
user interaction for game logic see the FBUllCowGame class
*/

#include <iostream> //iostream trata entrada e saida de dados
#include <string> //string trata manipulacao de strings
#include "FBullCowGame.h" // incluido nossa headerfile

//
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
FText PrintGuess(FText guess,FBullCowCount BullCowCount);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGAME;

int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PlayGame()
{
	
	BCGAME.Reset();

	//TODO change from for to While loop once we are valid
	int32 MaxTries = BCGAME.GetMaxTries(); 
	
	while (!BCGAME.IsGameWon() && BCGAME.GetCurrentTry() <= MaxTries)
	{

		FText Guess = "";
		Guess = GetValidGuess(); // TODO make loop check only validade guesses
		// Submite valid guess to the game and receive count
		FBullCowCount BullCowCount = BCGAME.SubmitValidGuess(Guess);
		// Print Number of bull and cows
		PrintGuess(Guess,BullCowCount);

	}

	PrintGameSummary();
	return;
}

void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << BCGAME.GetHiddenWordLength() << " letter isogram I`m thinking of? \n";
	return;
}

//Loop continualy until a valid guess is inputed.
FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus status = EGuessStatus::Invalid;

	do
	{

	
	std::cout << "Try " << BCGAME.GetCurrentTry() << " ";
	std::cout << "Enter a guess: ";
	std::getline(std::cin, Guess);

	status = BCGAME.CheckGuessValidaty(Guess);

	switch (status)
	{
	case EGuessStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGAME.GetHiddenWordLength() << " letters word. \n";
		break;
	case EGuessStatus::Not_Isogram:
		std::cout << "Please enter a Isogram. \n";
		break;
	case EGuessStatus::Not_LowerCase:
		std::cout << "Please enter a the word in all lowercase. \n";
		break;
	default:
		//asummes the guess is valid
		break;
	}

	std::cout << std::endl;
	} while (status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
	
}

FText PrintGuess(FText Guess,FBullCowCount BullCowCount) {
	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << ". Cows = " << BullCowCount.Cows;
	std::cout << " ";
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you wanna play again with the same hidden word? (y/n)";
	FText response = "";
	bool rrp;
	std::getline(std::cin, response);
	if ((response[0] == 'y') || (response[0] == 'Y'))
	{
		rrp = true;
	}
	else {
		rrp = false;
	}
	return rrp; 
}

void PrintGameSummary()
{
	if (BCGAME.IsGameWon()) {
		std::cout << "Well Done you Win! \n";
	}
	else
	{
		std::cout << "Better Luck Next Time \n";
	}
}
