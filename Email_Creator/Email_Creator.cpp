#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;

//Kayla Gandy
// U32864836
//Email_Creator

int main()
{
	ifstream file_Data;
	//declare file stream

	vector <string> first;
	vector <string> emails;
	//declare vectores to hold first names and emails
	int index[3];
	int i = 0, j = 0;
	//declare indexing integers

	string incoming[7], first_name, last_name, email_add;
	stringstream collection;
	//declare strings to hold data as well as a string stream
	file_Data.open("email_list.txt");
	//open file

	if (file_Data.fail())
	{
		cout << "Error Opening File." << endl;
		return 0;
	}//if error opening file, print error message
	
	while (getline(file_Data, incoming[0]))
	{
		collection.str(incoming[0]);
		collection.clear();
		//put scanned line into buffer and clear all error warnings

		collection >> first_name >> last_name >> email_add;
		//store in respective variables
		if (islower(first_name[0]))
		{ first_name[0] -= 32; }
		//if the first letter of the first name is lowercase, make it uppercase

		first.push_back(first_name);
		//store first name in vector
		for (i = 0; i < static_cast <int> (email_add.size()); i++)
		{ email_add[i] = tolower(email_add[i]); }
		//make all chars in email lowercase

		emails.push_back(email_add);
		collection.ignore(numeric_limits<streamsize>::max(), '\n');
		//store emails in vector and discard everything else in the stream
	}
	file_Data.close();
	//close file email_list.txt
	file_Data.open("email_template.txt");
	//open file
	incoming[0] = "";
	//be sure incoming lines are clear

	while (getline(file_Data, email_add))
	{
		index[i] = email_add.find('{');
		if (index[i] != -1)
		{//if '{' is found, store index and erase from { to }
			email_add.erase(index[i], email_add.find('}'));
			i++;
		}//increment i so index is stored properly
		incoming[j] = (email_add);
		j++;
		//increment j to move to next line
	}
	file_Data.close();
	//close file email_template.txt
	cout << "Email Creator" << endl;
	for (i = 0; i < static_cast <int> (emails.size()); i++)
	{
		cout << "========================================================" << endl;
		cout << incoming[0] << emails[i] << endl;
		cout << incoming[1] << "\n" << incoming[2] << "\n" << incoming[3] << endl;
		cout << incoming[4] << first[i] << "," << "\n" << incoming[5] << endl;
		cout << incoming[6] << endl;
	}//print all values, from template and email list
	return 0;
}