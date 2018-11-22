

#include "pch.h"
#include <iostream>
#include<ctime>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

void BubbleSort(int *A, int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j+1]);
			}
		}
	}
		
}
int main()
{
	srand(time(NULL));
	int *A, n, x; // A ia an Array of numbers, n is a size of it
	//cout << "Tell me a size of Array - ";
	//cin >> n;
	n = 30;
	A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 + 1;
		//cout << A[i] << endl;
	}

	BubbleSort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
}

