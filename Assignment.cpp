#include "Assignment.hpp"

Assignment::Assignment(string name, int maxPoints)
{
	this->name = name;
	this->maxPoints = maxPoints;
}

string Assignment::get_name()
{
	return this->name;
}

int Assignment::get_max_points()
{
	return this->maxPoints;
}
