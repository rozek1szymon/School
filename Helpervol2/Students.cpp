#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class Student
{
public:
	string wholeInformation, name, surname, fieldOfStudy;
	int semester, indexNumber;
	double avarageOfMarks;

	Student::Student(string _name, string _surname, string _fieldOfStudy, int _semester, double _averageOfMarks, int _indexNumber)
	{
		name = _name;
		surname = _surname;
		fieldOfStudy = _fieldOfStudy;
		semester = _semester;
		avarageOfMarks = _averageOfMarks;
		indexNumber = _indexNumber;
	}

};
