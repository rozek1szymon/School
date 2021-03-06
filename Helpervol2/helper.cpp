#include "pch.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <conio.h>
#include "Students.h"

int get_int(vector<Student>Students, string line, int nr);
vector<Student>  get_string(vector<Student>Students, string line, int nr, string field, int semes, int x);
void Find_Students(vector<Student>Students, int nr, string line, string field, int semes);
void Find_best_avarage(vector<Student>Students, int nr, string line);
int open(string line);
void Students_over_average(vector<Student>Students, int nr, string line);

int main()
{
	int numberOfStudents; //number of students
	string line;
	fstream file;
	string field;
	int x;
	int semes = 0;
	numberOfStudents = open(line);
	vector <Student> Students(numberOfStudents);
	cout << Students[4].name;
	cout << " :D We have two fields of study in our University AiR And Mechatronika, if you want to check students and their semester click 1 if you want to check only field click 3" << endl;
	cout << "You can check who is the best of students by marks avarage then click clicking 2 on keyboard" << endl;

	//cout << "if you want to specify click 1, if no click anything else" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "tell us the field of their study;" << endl;
		cin >> field;
		cout << "Tell us a semester" << endl;
		cin >> semes;
		get_string(Students, line, numberOfStudents, field, semes, x);
		break;

	case 2:
		get_string(Students, line, numberOfStudents, field, semes, x);
		break;
	case 3:
		cout << "tell us the field of their study;" << endl;
		cin >> field;
		get_string(Students, line, numberOfStudents, field, semes, x);
		break;

	}

}



void Find_Students(vector<Student>Students, int nr, string line, string field, int semes)
{

	int number = 0;
	int i;
	for (i = 0; i < nr; i++)
	{
		if (semes == 0)
		{

			if (Students[i].fieldOfStudy == field)
			{
				cout << Students[i].name << endl;
				number++;
			}
		}
		else
		{
			if (Students[i].fieldOfStudy == field && Students[i].semester == semes)
			{
				cout << Students[i].name << endl;
				number++;
			}

		}


	}

	//Find_best_avarage(Students,  nr,  line);

	if (number == 0)
		cout << "We do not have students which you are looking for" << endl;


}
int open(string line)
{
	fstream file;

	file.open("Students.txt", ios::in);
	int numberOfStudents = 0;

	if (file.good() == true)
	{

		while (!file.eof())
		{

			getline(file, line);
			numberOfStudents++;


		}
		file.close();
	}

	return numberOfStudents = numberOfStudents - 1;

}
void Students_over_average(vector<Student> Students, int nr, string line)
{
	double need_value;
	cin >> need_value;
	vector<string> tab;
	for (int i = 0; i < nr; i++)
	{
		//cout << Students[i].avarageOfMarks<<endl;


		if (Students[i].avarageOfMarks > need_value)
		{
			tab.push_back(Students[i].name);

		}

	}
	cout << "Students whoch have avarage higher than " << need_value << " consist of group of " << tab.size() << endl;
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << endl;
	}
	system("pause");

}
vector<Student>  get_string(vector<Student>Students, string line, int nr, string field, int semes, int x)
{
	fstream file;

	file.open("Students.txt", ios::in);
	int i = 0;


	if (file.good() == true)
	{

		while (!file.eof() && i < nr)
		{

			getline(file, line);
			stringstream ss(line);

			ss >> Students[i].name >> Students[i].surname >> Students[i].fieldOfStudy >> Students[i].avarageOfMarks >> Students[i].semester >> Students[i].indexNumber;

			//cout << Students[i].name<<" " << Students[i].surname <<" "<< Students[i].fieldOfStudy <<" "<< Students[i].avarageOfMarks<<" "<< Students[i].semester<<" "<< Students[i].indexNumber <<endl;

			//cout << Students[0].name;
			//return Students[i].name;
			++i;

		}
	}
	//cout << Students[0].name;
	switch (x)
	{
	case 2:
		Find_best_avarage(Students, nr, line);

		break;
	case 1:
		Find_Students(Students, nr, line, field, semes);
		break;
	case 3:
		Find_Students(Students, nr, line, field, semes);
		break;
	case 4:
		Students_over_average(Students, nr, line);
		cout << "gowno";
		break;
	default:
		cout << "there are no number like this";
		break;

	}

	file.close();

	for (i; i > 0; i--)
	{
		//return Students[i].name;
		//Students[i].surname;
	}

	return Students;

}
int get_int(vector<Student>Students, string line, int nr)
{
	fstream file;

	file.open("Students.txt", ios::in);
	int i = 0;


	if (file.good() == true)
	{

		while (!file.eof() && i < nr)
		{

			getline(file, line);
			stringstream ss(line);

			ss >> Students[i].name >> Students[i].surname >> Students[i].fieldOfStudy >> Students[i].avarageOfMarks >> Students[i].semester >> Students[i].indexNumber;

			//cout << Students[i].name<<" " << Students[i].surname <<" "<< Students[i].fieldOfStudy <<" "<< Students[i].avarageOfMarks<<" "<< Students[i].semester<<" "<< Students[i].indexNumber <<endl;

			return Students[i].avarageOfMarks;
			return Students[i].semester;
			return Students[i].indexNumber;

			++i;

		}
	}
	file.close();

	for (i; i > 0; i--)
	{
		//return Students[i].name;
		//Students[i].surname;
	}
	//return Lines[2];


}
void Find_best_avarage(vector<Student>Students, int nr, string line)
{
	double highest_value;
	vector<string> tab;
	highest_value = Students[0].avarageOfMarks;

	for (int i = 0; i < nr; i++)
	{
		//cout << Students[i].avarageOfMarks<<endl;


		if (Students[i].avarageOfMarks > highest_value)
		{
			highest_value = Students[i].avarageOfMarks;

		}

	}

	for (int i = 0; i < nr; i++)
	{
		if (Students[i].avarageOfMarks == highest_value)
		{
			tab.push_back(Students[i].name);

		}

	}
	cout << "Highest average of marks is a " << highest_value << " and " << tab.size() << " have it: " << endl;
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << endl;
	}
	system("pause");

}
