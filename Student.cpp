#include "Student.hpp"

Student::Student(string firstName, string lastName, int studentID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->studentID = studentID;
}

string Student::get_first_name()
{
	return this->firstName;
}

string Student::get_last_name()
{
	return this->lastName;
}

int Student::get_student_id()
{
	return this->studentID;
}
