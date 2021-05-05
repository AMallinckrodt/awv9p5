//
// Created by Alexander Mallinckrodt on 02/05/2021.
//
#include <iostream>
#include <iomanip>
#include <utility>
#include "LinkedList.h"
//#include "Node.h"

using namespace std;

/*void LinkedList::add_node(CounterTop value) {
	Node *tmp = new Node;
	if(head == nullptr){
		head = tmp;

	}

}
*/

void LinkedList::add_node(CounterTop value){
	Node *temp = new Node;
	temp->data = value;
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		cout << "head address: " << &head << endl;
		cout << "Tail address: " << &tail << endl;
		cout << "Temp address: " << &temp << endl;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	cout << "head address: " << &head << endl;
	cout << "Tail address: " << &tail << endl;
	cout << "Temp address: " << &temp << endl;}
	size++;
}



void LinkedList::printlist(){

	Node * current = head;

	while (current != nullptr) {
		current->data.Output();
		current = current->next;
	}
}

void LinkedList::clear() {
	Node *current = head;

	while (current != nullptr) {
		Node *next = current->next;
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

CounterTop LinkedList::Data(Node *ptr) {
	return ptr->data;
}

