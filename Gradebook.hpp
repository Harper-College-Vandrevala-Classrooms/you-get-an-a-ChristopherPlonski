#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <vector>

#include "Student.hpp"
#include "Assignment.hpp"
#include "Grade.hpp"

using namespace std;

class Gradebook {

public:
	Gradebook();
	~Gradebook();
	void add_new_student(Student &newStudent);
	void add_new_assignment(Assignment &newAssigment);
	pair<bool, string> try_give_student_grade_for_assignment(Student &student, Assignment &assignment, int grade);
	string get_report();

private:
	vector<Student*> *studentsVector;
	vector<Assignment*> *assignmentsVector;
	vector<Grade*>* gradesVector;
	bool does_student_exist(Student &studentToCheck);
	bool does_assignment_exist(Assignment &assignmentToCheck);
};

#endif // !1
