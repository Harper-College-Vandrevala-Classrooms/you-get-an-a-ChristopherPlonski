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
/// Return statement currently not in use and uses throw() statements if invalid instead.
/// </summary>
/// <param name="student"></param>
/// <param name="assignment"></param>
/// <param name="grade"></param>
/// <returns></returns>
pair<bool, string> Gradebook::try_give_student_grade_for_assignment(Student& student, Assignment& assignment, int grade)
{
	if (!does_student_exist(student)) {
		throw("Student is not in student list.");
		return make_pair(false, "Student is not in student list.");
	}

	if (!does_assignment_exist(assignment)) {
		throw("Student is not in student list.");
		return make_pair(false, "Assignment is not in assignment list.");
	}

	if (grade < 0 || grade > assignment.get_max_points()) {
		throw("Student is not in student list.");
		return make_pair(false, "Grade is out of valid range.");
	}
	
	Grade* gradeForStudent = new Grade(assignment, student, grade);
	gradesVector->push_back(gradeForStudent);

	return make_pair(true, "Grade added successfully.");
}

string Gradebook::get_report()
{
	string reportString = "";

	reportString += "| Student (first name, last name, id) | Assignment (name, max points) | Student Score |\n";

	for (int i = 0; i < gradesVector->size(); i++) {
		Grade* grade = gradesVector->at(i);
		Student* studentOfGrade = grade->get_student();
		Assignment* assignmentOfGrade = grade->get_assignment();

		// Student
		reportString += "| " + studentOfGrade->get_first_name() + ", " + studentOfGrade->get_last_name() + ", "
			+ to_string(studentOfGrade->get_student_id());
		// Assignment
		reportString += " | " + assignmentOfGrade->get_name() + ", " + to_string(assignmentOfGrade->get_max_points());
		// Score
		reportString += " | " + to_string(grade->get_student_grade_on_assignment()) + " |";

		reportString += "\n";
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


