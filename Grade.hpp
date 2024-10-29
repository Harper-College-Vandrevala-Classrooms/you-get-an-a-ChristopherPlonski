#ifndef GRADE_HPP
#define GRADE_HPP

#include "Assignment.hpp"
#include "Student.hpp"

class Grade {

public:
	Grade(Assignment &assignment, Student &student, int studentGradeOnAssignment);
	Assignment* get_assignment();
	Student* get_student();
	int get_student_grade_on_assignment();

private:
	Assignment *assignment;
	Student *student;
	int studentGradeOnAssignment;

};

#endif // !GRADE_HPP
