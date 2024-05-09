#pragma once
#include "student.h"

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = 0;
	for (int i = 0; i < dayICArray; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[], DegreeProgram degreeProgram)

{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < dayICArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

//Accessors
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getStudentAge() { return this->studentAge; };
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Mutators
void Student::setStudentID(string StudentID) { this->studentID = StudentID; }
void Student::setFirstName(string FirstName) { this->firstName = FirstName; }
void Student::setLastName(string LastName) { this->lastName = LastName; }
void Student::setEmailAddress(string EmailAddress) { this->emailAddress = EmailAddress; }
void Student::setStudentAge(int Age) { this->studentAge = Age; }
void Student::setDaysInCourse(int daysInCourse[])
{

	for (int i = 0; i < dayICArray; i++) this->daysInCourse[i] = daysInCourse[i];

}
void Student::setDegreeProgram(DegreeProgram degreeprogram) { this->degreeProgram = degreeprogram; }

void Student::printHeader()
{
	cout << "Student ID | First Name | Last Name | Email | Age | Days in Course | Degree Program |\n";
}

void Student::print()
{
	cout << studentID << '\t';
	cout << firstName << '\t';

	//Check if another tab is needed based on last name length.
	if ((lastName).size() <= 6) {
		cout << lastName << '\t' << '\t';
	}
	else {
		cout << lastName << '\t';
	}

	//Check if another tab is needed based on email length.
	if ((emailAddress).size() <= 15) {
		cout << emailAddress << '\t' << '\t';
	}
	else {
		cout << emailAddress << '\t';
	}

	cout << studentAge << '\t';
	cout << daysInCourse[0] << ',';
	cout << daysInCourse[1] << ',';
	cout << daysInCourse[2] << '\t';
	cout << degreeProgramStrings[degreeProgram] << '\n';
}