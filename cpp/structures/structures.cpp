// structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct StudentType
{
	string firstName;
	int count = 0;
};

ostream& operator<<(ostream& os, const StudentType& t)
{
	os << "\nName: " << t.firstName << " edits: " << t.count;
	return os;
}

list<StudentType> students;

int Ask()
{
	cout << "\n\nMenu" 
		 << "\n1 to create student" 
		 << "\n2 to edit student" 
		 << "\n3 randomly edit student" 
		 << "\n4 list students" 
		 << "\n...anything else exits                  => ";
	char in = -1;
	cin >> in;
	switch (in)
	{
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		default: break;
	}
	return -1;
}

void PrintStudents()
{
	list <StudentType> ::iterator it;
	cout << "\nListing all students:\n";
	for (it = students.begin(); it != students.end(); it++)
	{
		cout << *it;
	}

	cout << "\n\n";
}

void EditStudent()
{
	list <StudentType> ::iterator it;
	string name;
	cout << "\Enter first name of student to edit\n";
	cin >> name;
	for (it = students.begin(); it != students.end(); it++)
	{
		if (it->firstName == name) 
		{
			cout << *it;
			it->count++;
			return;
		}
	}

	cout << "\nStudent " << name << " was not found";
}

void AddStudent()
{
	cout << "\nCreating a student\n  enter First Name: ";
	string data;
	cin >> data;

	StudentType student;
	student.firstName = data;
	student.count = 0;
	students.push_back(student);
}

void RandomlyEdit()
{
	list <StudentType> ::iterator it;
	// std::advance(it, 2);
}

int main()
{
	StudentType matt;
	StudentType bob;

	matt.firstName = "matt";
	matt.count = 0;
	students.push_back(matt);

	bob.firstName = "bob";
	bob.count = 0;
	students.push_back(bob);

	PrintStudents();

	int doWhat = 0;
	while (doWhat != -1)
	{
		doWhat = Ask();
		switch (doWhat)
		{
		case 1:
			AddStudent();
			break;
		case 2: 
			EditStudent();
			break;
		case 3:
			cout << "randomly edits not enabled";
			break;
		case 4: 
			PrintStudents();
			break;
		}

	}
}



