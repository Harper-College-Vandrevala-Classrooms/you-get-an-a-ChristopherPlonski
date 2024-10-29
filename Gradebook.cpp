#include <stdexcept>

#include "Gradebook.hpp"

Gradebook::Gradebook()
{
	studentsVector = new vector<Student*>();
	assignmentsVector = new vector<Assignment*>();
	gradesVector = new vector<Grade*>();
}

Gradebook::~Gradebook()
{
	// Causes memory access error?
	//for (Student* student : *studentsVector) {
	//	delete student;
	//}

	//for (Assignment* assignment : *assignmentsVector) {
	//	delete assignment;
	//}

	delete studentsVector;
	delete assignmentsVector;
	delete gradesVector;
}

void Gradebook::add_new_student(Student &newStudent)
{
	studentsVector->push_back(&newStudent);
}

void Gradebook::add_new_assignment(Assignment &newAssigment)
{
	assignmentsVector->push_back(&newAssigment);
}

/// <summary>
/// Returns a pair<bool, string>. Bool represents whether or not the process was successful. String represents the error/success message.
/// </summary>
/// <param name="student"></param>
/// <param name="assignment"></param>
/// <param name="grade"></param>
/// <returns></returns>
pair<bool, string> Gradebook::try_give_student_grade_for_assignment(Student& student, Assignment& assignment, int grade)
{
	if (!does_student_exist(student)) {
		return make_pair(false, "Student is not in student list.");
	}

	if (!does_assignment_exist(assignment)) {
		return make_pair(false, "Assignment is not in assignment list.");
	}

	if (grade < 0 || grade > assignment.get_max_points()) {
		return make_pair(false, "Grade is out of valid range.");
	}

	Grade* gradeForStudent = new Grade(assignment, student, grade);
	gradesVector->push_back(gradeForStudent);

	return make_pair(true, "Grade added successfully.");
}

string Gradebook::get_report()
{
	string reportString = "";

	reportString += "| Student: first + last name, id | ";
	for (int i = 0; i < assignmentsVector->size(); i++) {
		Assignment* assignment = assignmentsVector->at(i);

		reportString += assignment->get_name() + ", #/" + to_string(assignment->get_max_points()) + " | ";
	}

	reportString += "\n";

	// VERY not efficient code. Nested for-loop x 3 not great, but is fine for homework.
	for (int i = 0; i < studentsVector->size(); i++) {
		Student* student = studentsVector->at(i);

		// Student
		reportString += "| " + student->get_first_name() + " " + student->get_last_name() + ", "
			+ to_string(student->get_student_id());

		for (int j = 0; j < assignmentsVector->size(); j++) {
			Assignment* assignment = assignmentsVector->at(j);
			reportString += " | " + try_get_assignment_grade_of_student(*assignment, *student);
		}

		reportString += " |\n";
	}

	return reportString;
}

bool Gradebook::does_student_exist(Student &studentToCheck)
{
	for (int i = 0; i < studentsVector->size(); i++) {
		Student *student = studentsVector->at(i);

		if (&studentToCheck == student) {
			return true;
		}
	}

	return false;
}

bool Gradebook::does_assignment_exist(Assignment& assignmentToCheck)
{
	for (int i = 0; i < assignmentsVector->size(); i++) {
		Assignment *assignment = assignmentsVector->at(i);

		if (&assignmentToCheck == assignment) {
			return true;
		}

	}

	return false;
}

string Gradebook::try_get_assignment_grade_of_student(Assignment& assignment, Student& student)
{
	for (Grade* grade : *gradesVector) {
		if (grade->get_assignment() == &assignment && grade->get_student() == &student) {
			string studentGradeString = to_string(grade->get_student_grade_on_assignment());
			string assignmentMaxPointsString = to_string(assignment.get_max_points());
			return studentGradeString + "/" + assignmentMaxPointsString;
		}
	}

	return "none";
}


