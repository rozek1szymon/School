// Sortowanie Szybkie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Sortuj_szybko(int *d,int lewy, int prawy)
{
	int i, j, piwot;

	i = (lewy + prawy) / 2;
	piwot = d[i];
	d[i] = d[prawy];
	for (j = i = lewy; i < prawy; i++)
	{
		if (d[i] < piwot)
		{
			swap(d[i], d[j]);
			j++;
		}
	}
		
	d[prawy] = d[j]; 
	d[j] = piwot;
	if (lewy < j - 1)
	{
		Sortuj_szybko(d,lewy, j - 1);
	}
		
	if (j + 1 < prawy)
	{
		Sortuj_szybko(d, j + 1, prawy);
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
	Sortuj_szybko(A,0, n-1);
	for (int i = 0; i < n; i++)
	{
		//A[i] = rand() % 1000 + 1;
		cout << A[i] << endl;
	}
	//cout << "Koniec losowej generacji" << endl;
	delete [] A;
}

