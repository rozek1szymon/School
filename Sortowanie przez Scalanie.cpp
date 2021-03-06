// Sortowanie przez Scalanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

void MergeSort( int i_p, int i_k,  int n, int*d, int *p )
{

	
	int  i_s, i1, i2, i;

	i_s = (i_p + i_k + 1) / 2;
	if (i_s - i_p > 1)
	{
		MergeSort(i_p, i_s - 1, n, d, p);
	}
		
	if (i_k - i_s > 0)
	{
		MergeSort(i_s, i_k, n, d, p);
	}
		
	i1 = i_p; i2 = i_s;
	for (i = i_p; i <= i_k; i++)
	{
		p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
	}
		
	for (i = i_p; i <= i_k; i++)
	{
		d[i] = p[i];
	}
		
	
}



int main()
{
	srand(time(NULL));
	int  n,*d,*p; // A ia an Array of numbers, n is a size of it
	//cout << "Tell me a size of Array - ";
	//cin >> n;
	n = 100;
	
	d= new int[n];
	p = new int[n];
	for (int i = 0; i < n; i++)
	{
		d[i] = rand() % 1000 + 1;
		//cout << A[i] << endl;
	}
	//cout << "Koniec losowej generacji" << endl;
	MergeSort( 0, n - 1,n,d,p);

	for (int i = 0; i < n; i++)
	{
		//A[i] = rand() % 1000 + 1;
		cout << d[i] << endl;
	}
	delete [] d;
	delete [] p;
}


