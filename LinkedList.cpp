//
// Created by Alexander Mallinckrodt on 02/05/2021.
//
#include <iostream>
#include <iomanip>
#include <utility>
#include "LinkedList.h"

using namespace std;


void LinkedList::add_node(CounterTop obj){
	CounterTop* temp = new CounterTop;
	temp->operator=(obj);
	temp->setnext(nullptr);

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{tail->setnext(temp++);
		tail = temp;}
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

		current->setnext(current);
		delete head;
		head->setnext(current);
	}

	cout << "All Data Cleared" << endl;

}

bool LinkedList::empty() const{

	if (head == nullptr) {
		cout << "List is Empty" << endl;
		return true;
	} else {
		return false;
	}
}


