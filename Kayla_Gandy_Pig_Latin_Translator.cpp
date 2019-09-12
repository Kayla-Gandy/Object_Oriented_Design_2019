#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Kayla Gandy
//U32864836
//Pig_Latin_Translator

int main()
{
	string sentence;
	char first;
	//declare a string to store the line to translate and a char to store the first letter of each word
	vector <string> words;
	vector <int> index;
	//create vectors to hold all words and the index of spaces
	int i, j, length, total = 0;
	//declare variables for counting characters and length of words

	cout << "Pig Latin Translator\n\nThis program translates a sentence and removes all punctuation from it.\n" << endl;
	while (true)
	{
		cout << "Enter a sentence: ";

		getline(cin, sentence);
		if (cin.good())
		{ break; }
		//if a good value is stored in sentence, break the loop to get input
		else if (cin.bad())
		{
			cout << "An error has occurred, terminating program." << endl;
			return 0;
		}//if there is an unrecoverable error print an error message and end program
	}
	index.push_back(-1);
	//add value to account for beginning of string
	for (i = 0; i <= static_cast <int> (sentence.size()); i++)
	{
		if (ispunct(sentence[i]) || isdigit(sentence[i]))
		{
			sentence.erase(i, 1);
			continue;
		}//check for and delete numbers and punctuation
		else if (isspace(sentence[i]))
		{
			index.push_back(i);
		}//if there character is a space, store the index of the space
		total++; //add to total number of characters
		sentence[i] = tolower(sentence[i]);
		//characters to lowercase
	}

	index.push_back(total);
	//store total at the very end of the index list

	for (i = 1; i < static_cast <int> (index.size()); i++)
	{
			first = sentence[index[i-1] + 1];
			//store the first letter of each word
			length = index[i] - index[i - 1] - 1;
			//calculate the length of each word
		if (length == 1)
		{
			words.push_back(sentence.substr(index[i - 1] + 1, 1) + "way ");
			continue;
		}//if the word is only one letter, store with "way" instead of "ay"
		if (i == 1)
		{
			sentence[1] = toupper(sentence[1]);
		}//if it is the first word, capitalize first letter
		words.push_back(sentence.substr(index[i-1]+2, length - 1) + first + "ay ");
	}//store all words without first letter
	cout << "\nTranslation: ";
	for(i = 0; i < static_cast <int> (words.size()); i++)
	{
		cout << words[i];
	}//print words
	cout << endl;

	return 0;
}