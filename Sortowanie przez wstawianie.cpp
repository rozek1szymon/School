

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void InsertSort(int *A, int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = A[i];
		j = i - 1;
		while (j >= 0 && x < A[j])
		{
			A[j+1] = A[j];
			j = j - 1;
		}
		 A[j + 1] = x ;
	}
}

int main()
{
	srand(time(NULL));
	int *A, n, x; // A ia an Array of numbers, n is a size of it
	//cout << "Tell me a size of Array - ";
	//cin >> n;
	n = 10;
	A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 + 1;
	}
	InsertSort(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
}

