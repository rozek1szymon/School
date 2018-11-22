// Stos.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

const int MAXINT = -2147483647;

class stack
{
private:
	int n;      
	int sptr;   
	int * S;    

public:
	stack(int x); 
	~stack();     
	bool empty(void);
	int  top(void);
	void push(int v);
	void pop(void);
};



stack::stack(int x)
{
	n = x;
	S = new int[x];
	sptr = 0;
}


stack::~stack()
{
	delete[] S;
}



bool stack::empty(void)
{
	return !sptr;
}


int stack::top(void)
{
	if (sptr) return S[sptr - 1];
	return -MAXINT;
}



void stack::push(int v)
{
	if (sptr < n) S[sptr++] = v;
}


void stack::pop(void)
{
	if (sptr) sptr--;
}




int main()
{
	stack S(10); 
	int i;

	for (i = 1; i <= 10; i++) S.push(i);

	while (!S.empty())
	{
		cout << S.top() << endl;
		S.pop();
	}
}
