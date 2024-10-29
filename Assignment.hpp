#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <string>

using namespace std;

class Assignment {
	
public:
	Assignment(string name, int maxPoints);
	string get_name();
	int get_max_points();

private:
	string name;
	int maxPoints;

};

#endif // !ASSIGNMENT_HPP
