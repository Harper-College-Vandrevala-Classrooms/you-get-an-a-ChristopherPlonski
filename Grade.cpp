#include "Grade.hpp"

Grade::Grade(Assignment& assignment, Student& student, int studentGradeOnAssignment)
{
	this->assignment = &assignment;
	this->student = &student;
	this->studentGradeOnAssignment = studentGradeOnAssignment;
}

Assignment* Grade::get_assignment()
{
	return this->assignment;
}

Student* Grade::get_student()
{
	return this->student;
}

int Grade::get_student_grade_on_assignment()
{
	return this->studentGradeOnAssignment;
}


