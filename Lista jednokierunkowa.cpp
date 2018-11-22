// Lista jednokierunkowa.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Element
{
private:
	int val;
	Element *next;
public:
	Element(int val);
	void setValue(int val);
	int getValue();
	void setNext(Element *next);
	Element *getNext();
};

class Lista
{
private:
	Element *head;
public:
	Lista() { head = nullptr; }
	bool isEmpty();
	void addFront(int val);
	//friend ostream & operator << (ostream & out, Lista & l);
	void print();
	~Lista();
};

int main()
{
	Lista lista;
	for (int i = 0; i < 5; i++) lista.addFront(i);
	lista.print();

	return 0;
}

Element::Element(int val)
{
	this->setValue(val);
	this->setNext(nullptr);
}

void Element::setValue(int val)
{
	this->val = val;
}

void Element::setNext(Element *next)
{
	this->next = next;
}

int Element::getValue()
{
	return this->val;
}

void Lista::addFront(int val)
{
	Element *nowy = new Element(val);
	nowy->setNext(head);
	head = nowy;
}

Element  *Element::getNext()
{
	return this->next;
}

void Lista::print()
{
	Element *x = head;
	while (x != nullptr)
	{
		cout << x->getValue() << endl;
		x = x->getNext();
	}
}

Lista::~Lista()
{

}