//Codebreaker part 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	//Program running to keep playing
	bool isProgramRunning = true;
	//User name
	string userName = "";

	cout << "Input your name rookie: " << endl;
	cin >> userName;
	cout << "Thank you, " << userName << " for entering the simulation." << endl;

	cout << "Welcome to Codebreaker simultion 2. Good luck " << userName << "!!!\n";
	cout << "Codebreaker simulation 2 wants you to guess a key word without getting to many wrong guesses." << endl;
	cout << "You will be asked to input your guess, all you have to do is type in a letter and hit the enter key." << endl;
	while (isProgramRunning == true) {
		//setup
		//Maximum number of wrong guesses allowed
		const int maxWrong = 8;
		//Collection of words to guess from
		vector<string> words;
		//Adding the words to the collection
		words.push_back("SPY");
		words.push_back("WEAPON");
		words.push_back("MISSION");
		words.push_back("MARTINI");
		words.push_back("AGENT");
		words.push_back("CLASSIFIED");
		words.push_back("TERRORISTS");
		words.push_back("INTEL");
		words.push_back("INTERROGATION");
		words.push_back("ARREST");

		//Picking a random word
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		//Word to guess
		const string theWord = words[0];
		//Numnber of wrong guesses
		int wrong = 0;
		//Word guessed so far
		string soFar(theWord.size(), '-');
		//Letters already guessed
		string used = "";

		//Main loop
		while ((wrong < maxWrong) && (soFar != theWord))
		{
			cout << userName << " has " << (maxWrong - wrong);
			cout << " incorrect guesses remaining.\n";
			cout << userName << " used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is: \n" << soFar << endl;

			//Getting the player's guess
			char guess;
			cout << "\n\n Enter your guess: ";
			cin >> guess;
			//Making the guess upper case to match the secret words
			guess = toupper(guess);

			//Used to check if a player has already guess a certain letter
			while (used.find(guess) != string::npos)
			{
				cout << userName << " already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			used += guess;
			if (theWord.find(guess) != string::npos)
			{
				cout << "That's right! " << guess << " is in the word.\n";
				//updating soFar
				for (int i = 0; i < theWord.length(); i++)
				{
					if (theWord[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}//Ending the game
		if (wrong == maxWrong)
		{
			cout << userName << " has been exposed!" << endl;
		}
		else
		{
			cout << "\nMission accomplished " << userName << " !";
		}
		cout << "\nThe word was " << theWord << endl;

		//Continue or quit
		cout << "\nContinue the simulation?" << endl;
		string choice;
		cin >> choice;
		if (choice == "YES" || choice == "yes" || choice == "Yes") 
		{
			wrong = 0;
			continue;
		}
		else 
		{
			cout << "\nThank you for partaking in the simulation " << userName << " !" << endl;
			isProgramRunning = false;
		}


		system("pause");
		return 0;
	}
}
	