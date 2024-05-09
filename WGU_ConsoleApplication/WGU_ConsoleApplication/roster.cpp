#pragma once
#include "roster.h"

Roster::Roster(){}

Roster::~Roster()
{
	cout << "Destructor Called" << std::endl << std::endl;
	for (int i = 0; i < numStu; i++)
	{
		cout << "Destroying Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};

void Roster::parse(string studentData)
{
	DegreeProgram degreeProgram = SECURITY;
	if (studentData.back() == 'K') 
	{
		degreeProgram = NETWORK;
	}
	else if (studentData.back() == 'E') 
	{
		degreeProgram = SOFTWARE;
	}

	int rhs = studentData.find(",");
	string StudentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EmailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysIC1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysIC2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysIC3 = stoi(studentData.substr(lhs, rhs - lhs));

	add(StudentID, FirstName, LastName, EmailAddress, Age, daysIC1, daysIC2, daysIC3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int Days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, Days, degreeProgram);
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStu - 1)
			{
				for (int x = i; x < lastIndex; x++) 
				{
					classRosterArray[x] = classRosterArray[x + 1];
				}
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student ID: " << "'" << studentID << "'" << " has been removed from roster." << endl << std::endl;
	}
	else {
		cout << "Student ID: " << "'" << studentID << "'" << " was not found." << endl << std::endl;
	}
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string StudentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			cout << "Student ID: ";
			cout << StudentID;
			cout << ",";
			cout << " averages ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << " days in a course.";
		}

	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string EmailAddress = (classRosterArray[i]->getEmailAddress());
		if (EmailAddress.find("@") == string::npos || (EmailAddress.find('.') == string::npos) || (EmailAddress.find(' ') != string::npos))
		{
			any = true;
			cout << classRosterArray[i]->getEmailAddress() << std::endl;
		}
	}
	if (!any) {
		cout << "NONE" << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}