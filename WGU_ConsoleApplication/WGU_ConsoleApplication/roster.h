#pragma once
#include "student.h"

class Roster
{
public:
	//Initialize # of students
	const static int numStu = 5;
	Student* classRosterArray[numStu];
	int lastIndex = -1;

public:
	//Constructor
	Roster();

	//Destructor
	~Roster();
	void parse(string row);
	void add(string StudentID, string FirstName, string LastName, string Email, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeprogram);
	void printAll();
	void printAverageDaysInCourse(string StudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void remove(string StudentID);
};