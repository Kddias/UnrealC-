#include <iostream> //iostream trata entrada e saida de dados
#include <string> //string trata manipulacao de strings
#include "FBullCowGame.h" // incluido nossa headerfile


void PrintIntro();
void PlayGame();
std::string GetGuess();
std::string PrintGuess(std::string guess);
bool AskToPlayAgain();

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
	int MaxTries = BCGAME.GetMaxTries(); 
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = "";
		Guess = GetGuess(); // TODO make loop check only validade guesses

		// Submite valid guess to the game
		// Print Number of bull and cows
		PrintGuess(Guess);
	}

	//TODO	summarise game

}

void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I`m thinking of? \n";
	return;
}

std::string GetGuess() {
	std::string Guess = "";
	std::cout << "Try " << BCGAME.GetCurrentTry() << " ";
	std::cout << "Enter a guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

std::string PrintGuess(std::string Guess) {
	std::cout << "Your guess was: " << Guess << std::endl;
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you wanna play again? (y/n)";
	std::string response = "";
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
