//
// Created by Alexander Mallinckrodt on 02/05/2021.
//
#include <iostream>
#include <iomanip>
#include <utility>
#include "LinkedList.h"
//#include "Node.h"

using namespace std;


void LinkedList::add_node(CounterTop obj){
	CounterTop *temp = new CounterTop;
	temp->operator=(obj);
	temp->setnext(nullptr);

	if (head == nullptr)
	{
		head->setnext(temp);
		tail->setnext(temp);
		cout << "head address: " << &head << endl;
		cout << "Tail address: " << &tail << endl;
		cout << "Temp address: " << &temp << endl;
	}
	else
	{
		tail->setnext(temp);
		tail = temp;
	cout << "head address: " << &head << endl;
	cout << "Tail address: " << &tail << endl;
	cout << "Temp address: " << &temp << endl;}
	size++;
}



void LinkedList::printlist(){

	CounterTop * current = head;

	while (current != nullptr) {
		current->Output();
		current->setnext(current);
	}
}

void LinkedList::clear() {
	CounterTop *current = head;

	while (current != nullptr) {
		CounterTop *next = current;
		current->setnext(current);
		delete current;
		current = next;
	}
	head = nullptr;

	cout << "All Data Cleared" << endl;

}

bool LinkedList::empty() {

	if (head == nullptr) {
		cout << "List is Empty" << endl;
		return true;
	} else {
		return false;
	}
}


