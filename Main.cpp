#include <iostream>

#include "Gradebook.hpp"

int main() {
	Gradebook gradebook = Gradebook();

	// Students
	Student student1 = Student("Chris", "Plonski", 11111);
	Student student2 = Student("Bob", "Smith", 01234);
	Student student3 = Student("Emily", "Smith", 98765);

	// Assignments
	Assignment assignment1 = Assignment("Hello World Lab", 10);

	gradebook.add_new_student(student1);
	gradebook.add_new_student(student2);

	gradebook.add_new_assignment(assignment1);

	gradebook.try_give_student_grade_for_assignment(student1, assignment1, 5);

	cout << "Report: " << endl;
	cout << gradebook.get_report();

	// TODO: Make gradebook output match criteria
}