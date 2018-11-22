// Wyszukiwanie binarne.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void BinarySearching(int *Array, int x,int l,int r)
{
	
	int sr;
	bool find = false;
	while (l <= r )
	{
		 sr = (l + r )/ 2;
		//cout << sr<<endl;
		if (Array[sr] == x)
		{
			find = true;
			cout<<"your number is on the" <<sr<<"position"<<endl;
			break;
		}
		else if (x < Array[sr])
		{
			r = sr - 1;
		}
		else
		{
			l = sr + 1;
		}
		
	}
	
	if (find == false) 
	{
		cout << "Your number is not a part of a set" << endl;
	}
	
}

int main()
{
	srand(time(NULL));
	int *ArrayOfNumbers, x,n; //x is a number which we are looking for n is a siye of array

	cout << "Tell me size of array in which we ll be looking for a picked number" << endl;
	cin >> n;
    int right = n;
	
	
		
	ArrayOfNumbers = new int[n];
	ArrayOfNumbers[0] = rand() % 5; //We have to initialize array to get right number in the loop which is under
	
	for (int i = 1; i <=n; i++)
	{
		
		ArrayOfNumbers[i] = ArrayOfNumbers[i-1] + (rand() % 10); //using this ,we are sure that random number will be increasing gradually
		cout << ArrayOfNumbers[i] << endl;
	}
	cout << "Which number are u looking for ?" << endl;
	cin >> x;
	BinarySearching(ArrayOfNumbers,x,1,right);
	system("pause");
}

