#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student
{
public:

	const static int dayICArray = 3;

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysInCourse[dayICArray];
	DegreeProgram degreeProgram;

public:

	//Constructor
	Student();

	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeProgram);

	//Destructor
	~Student();

	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmailAddress(string EmailAddress);
	void setStudentAge(int Age);
	void setDaysInCourse(int Days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();
};