

#include "pch.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
#include <utility>   
#include <vector>
using namespace std;
void SelectionSort(int*A, int n)
{

	int i, j, min;
	for ( i = 0; i < n; i++)
	{
		min = i;
		for ( j = i + 1; j < n; j++)
		{
			if (A[j] < A[min])
			{
				min = j;
			}
			
		}
		
		swap(A[i], A[min]);
	}
	
}




int main()
{
  srand(time(NULL));
	int *A, n; // A ia an Array of numbers, n is a size of it
	//cout << "Tell me a size of Array - ";
	//cin >> n;
	n = 100;
	A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 1000 + 1;
		//cout << A[i] << endl;
	}
	//cout << "Koniec losowej generacji" << endl;
	SelectionSort(A, n);
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
	delete[]A;
}
