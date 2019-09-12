#include <iostream>

using namespace std;

int main()
{
	char answer = 'Y';
	int cents, quarter = 0, dime = 0, nickel = 0;
	// declare all variables, including varibale to continue loop
	cout << "Change Calculator" << endl;

	while (answer == 'Y')
	{ // repeat loop so long as the answer remains Y
		cout << "\nEnter number of cents(0 - 99) : ";
		cin >> cents;
		//ask for and store cents as integer
		if (cents != 0)
		{
			quarter = cents / 25;
			cents = cents % 25;
		} // calculates how many quarters are needed (avoids dividing by 0)
		if (cents != 0)
		{
			dime = cents / 10;
			cents = cents % 10;
		} // calculates how many dimes needed (avoids dividing by 0)
		if (cents != 0)
		{
			nickel = cents / 5;
			cents = cents % 5;
		} // calculates how many nickles needed (avoids dividing by 0)
		cout << "\nQuarters: " << quarter << "\nDimes: " << dime << "\nNickels: " << nickel << "\nPennies: " << cents << endl;
		cout << "Continue? (y/n): ";
		cin >> answer;
		answer = toupper(answer);
		//prints values, asks for confirmation of continuing loop, makes the answer uppercase to satisfy 'Y' requirement
	}
	return 0;
}