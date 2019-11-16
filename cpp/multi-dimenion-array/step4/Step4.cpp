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

void printArray(int data[10][10], int userNum)
{
	for (int left = 0; left < userNum; left++)
	{
		cout << "# " << left + 1;
		for (int right = 0; right < userNum; right++)
		{
			cout << " " << data[left][right];
		}

		cout << endl;
	}
}

void sumArray(int data[10][10], int userNum)
{
	for (int left = 0; left < userNum; left++)
	{
		cout << " sum line # " << left + 1;
		int sum = 0;
		for (int right = 0; right < userNum; right++)
		{
			sum += data[left][right];
		}

		cout << " = " << sum << endl;
	}
}

void multiplyArray(int data[10][10], int userNum)
{
	for (int left = 0; left < userNum; left++)
	{
		cout << " multiply line # " << left + 1;
		int multiple = 1;
		for (int right = 0; right < userNum; right++)
		{
			multiple = multiple * data[left][right];
		}

		cout << " = " << multiple << endl;
	}
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
			int data[10][10];
			for (int i = 0; i < userInput; i++)
			{
				for (int j = 0; j < userInput; j++)
				{
					data[i][j] = rand(); 
				}
			}
			printArray(data, userInput);
			cout << "3. Add the values the arrays and output result" << endl;
			sumArray(data, userInput);
			cout << "4. Multiply the values the arrays and output result" << endl;
			multiplyArray(data, userInput);
		}
		cout << "5. Ask the user if they want to try again" << endl;
		keepGoing = askUserToContinue();
	}

	cout << "app is done";
}

