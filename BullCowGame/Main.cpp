#include <iostream> //iostream trata entrada e saida de dados
#include <string> //string trata manipulacao de strings

using namespace std;


void PrintIntro(int WORD_LENGTH);
string GetGuessAndPrintBack();

int main() {

	//Define variables
	constexpr int WORLD_LENGTH = 9;
	constexpr int TRIES = 5;
	string Guess;
	
	//Introduce the game 
	PrintIntro(WORLD_LENGTH);

	//Get Guess from playeR //on a loop
	for (int i = 0; i < TRIES; i++)
	{
	     GetGuessAndPrintBack();
	}
	
	//finish application
	return 0;
}


//functions

void PrintIntro(int WORLD_LENGHT) {
	cout << "Welcome to Bulls and Cows, a fun word game. \n";
	cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I`m thinking of? \n";
	return;
}

string GetGuessAndPrintBack() {
	string Guess = "";
	cout << "Enter a guess: ";
	getline(cin, Guess);
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return Guess;
}