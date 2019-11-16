/*
Creates two square Matrices
then calls functions to add, subtract, then multiply them
*/
#include<iostream>
using namespace std;
#include <iostream>

int getUserNumber()
{
	cout << "Please enter a number between 2 and 10" << endl;
	int userInput = 0;
	cin >> userInput;

	if (userInput >= 2 && userInput <= 10)
		return userInput;

	return 0;
}

bool askUserToContinue()
{
	cout << "Would you like to continue? y/n" << endl;
	char userInput = 'n';
	cin >> userInput;

	if (userInput == 'y' || userInput == 'Y')
		return true;

	return false;
}


int main()
{
	bool keepGoing = true;

	while (true == keepGoing)
	{
		cout << "1. Ask the user how many elements in an array to use" << endl;
		int userInput = getUserNumber();
		if (0 < userInput)
		{

			cout << "2. Randomly assign values into the arrays" << endl;
			cout << "3. Add the values the arrays and output result" << endl;
			cout << "4. Multiply the values the arrays and output result" << endl;
		}
		cout << "5. Ask the user if they want to try again" << endl;
		keepGoing = askUserToContinue();
	}

	cout << "app is done";
}

