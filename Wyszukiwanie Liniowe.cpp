// Wyszukiwanie Liniowe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

void linearSearching(int *A, int n, int x)
{

	int *T, number = 0, p=0;
	for (int i = 0; i < n; i++)
	{

		if (A[i] == x)
		{
			number++;
			p = i + 1;
			cout << p << endl;
		}
		else if(A[i]!=x && i>n)
		{
			cout << "There are no your number in the set";
		}

		
	}
	cout << "you have " << number << " in this set"<<endl;
}



int main()
{
	srand(time(NULL));
	int *A, n, x; // A ia an Array of numbers, n is a size of it
	//cout << "Tell me a size of Array - ";
	//cin >> n;
	 n = 100000;
	A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 10 + 10;
	}
	 /*for (int i = 0; i < n; i++)
	{
		 cout << A[i]<<endl;
	}*/
	cout << "Which number are you will be looking for" << endl;
	cin >> x;
	linearSearching(A, n, x);

	delete[] A;
	system("pause");
    
}









// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
