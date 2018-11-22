// Lista Stuktura.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
class Node
{
public:
	Node* next;
	int data;
};

using namespace std;

class LinkedList
{
public:
	int length;
	Node* head;

	LinkedList();
	~LinkedList();
	void add(int data);
	void print();
	void deleteElement();
	void isEmpty();

};
int main()
{
	LinkedList* list = new LinkedList(); //we are creating a new list
	for (int i = 0; i < 100; ++i)
	{
		list->add(rand() % 100);
	}
	list->print();
	cout << "List Length: " << list->length << endl;
	delete list;
	return 0;
}

LinkedList::LinkedList()
{
	this->length = 0; // It means that to variable "length" we assign 0 so our list have length of 0
	this->head = NULL; // It means taht to variable "head" we assign a variable "NULL" because we do not have a length

}

LinkedList::~LinkedList() 
{
	std::cout << "LIST DELETED";
}

 void LinkedList::add(int data)
{
	 Node* node = new Node(); // we are creating a new mode inside a list
	 node->data = data; 
	 node->next = this->head; // head is always node which was created before so it creates a connection yo it
	 this->head = node; //and new node is a head of list
	 this->length++;// number of list is increasing

}
 void LinkedList::print() 
 {
	 Node* head = this->head;
	 int i = 1;
	 while (head) {
		 std::cout << i << ": " << head->data << std::endl;
		 head = head->next;
		 i++;
	 }
 }

 void LinkedList::deleteElement()
 {
 }
