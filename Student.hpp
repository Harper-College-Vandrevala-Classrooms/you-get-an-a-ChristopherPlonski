#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

using namespace std;

class Student {

public:
	Student(string firstName, string lastName, int studentID);
	string get_first_name();
	string get_last_name();
	int get_student_id();

private:
	string firstName, lastName;
	int studentID;

};

#endif // !STUDENT_HPP
