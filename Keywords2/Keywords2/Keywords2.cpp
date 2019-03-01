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
	//setup
	//Maximum number of wrong guesses allowed
	const int maxWrong = 8; 
	//Collection of words to guess from
	vector<string> words;
	words.push_back("Guess");
	words.push_back("Hangman");
	words.push_back("Difficult");

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

	cout << "Welcome to Codebreaker simultion 2. Good luck rookie!!!\n";

	//Main loop
	while ((wrong < maxWrong) && (soFar != theWord)) 
	{
		cout << "\n\nYou have " << (maxWrong - wrong);
		cout << " incorrect guesses remaining.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;
		cout << "\nSo far, the word is: \n" << soFar << endl;

	}

}