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

	cout << "Input is not valid" << endl;

	return false;
}

void printArray(int **data, int userNum)
{
	cout << endl << "Raw data for array[" << userNum << "][" << userNum << "]" << endl;

	for (int left = 0; left < userNum; left++)
	{
		cout << "# " << left + 1;
		for (int right = 0; right < userNum; right++)
		{
			cout << " " << data[left][right];
		}

		cout << endl;
	}

	cout << endl;
}

void sumArray(int** data, int userNum)
{
	cout << endl << "Summing array[" << userNum << "][" << userNum << "]" << endl;

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

	cout << endl;
}

void multiplyArray(int** data, int userNum)
{
	cout << endl << "Multiplying array[" << userNum << "][" << userNum << "]" << endl;

	for (int left = 0; left < userNum; left++)
	{
		cout << " multiply line # " << left + 1;
		long multiple = 1;
		for (int right = 0; right < userNum; right++)
		{
			multiple = multiple * data[left][right];
		}

		cout << " = " << multiple << endl;
	}
	cout << endl;
}

int main()
{
	bool keepGoing = true;

	while (true == keepGoing)
	{
		int userInput = getUserNumber();
		if (0 < userInput)
		{			
			int **data = new int* [userInput];
			for (int i = 0; i < userInput; i++)
			{
				data[i] = new int[userInput];

				for (int j = 0; j < userInput; j++)
				{
					data[i][j] = rand() % 100 + 1;
				}
			}
			printArray(data, userInput);
			sumArray(data, userInput);
			multiplyArray(data, userInput);
		}
		keepGoing = askUserToContinue();
	}

	cout << "app is done";
}

