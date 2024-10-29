#include <iostream>

#include "Gradebook.hpp"

int main() {
	Gradebook gradebook = Gradebook();

	// Students
	Student student1 = Student("Chris", "Plonski", 11111);
	Student student2 = Student("Bob", "Smith", 12345);
	Student student3 = Student("Emily", "Smith", 98765);

	// Assignments
	Assignment assignment1 = Assignment("Lab 1", 10);
	Assignment assignment2 = Assignment("Quiz 1", 50);

	gradebook.add_new_student(student1);
	gradebook.add_new_student(student2);
	gradebook.add_new_student(student3);

	gradebook.add_new_assignment(assignment1);
	gradebook.add_new_assignment(assignment2);

	gradebook.try_give_student_grade_for_assignment(student1, assignment1, 5);
	gradebook.try_give_student_grade_for_assignment(student2, assignment1, 10);
	gradebook.try_give_student_grade_for_assignment(student3, assignment1, 0);
	gradebook.try_give_student_grade_for_assignment(student1, assignment2, 43);
	gradebook.try_give_student_grade_for_assignment(student3, assignment2, 50);

	cout << "Gradebook Report: " << endl;
	cout << gradebook.get_report();
}