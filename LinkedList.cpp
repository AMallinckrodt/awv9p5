//
// Created by Alexander Mallinckrodt on 02/05/2021.
//
#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

//Adds another Value
void LinkedList::add_node(CounterTop v) {

	struct Node *tmp;
	tmp =(struct Node*)malloc(sizeof(struct Node));
	tmp->data = v;
	tmp->next = nullptr;

	if (head == nullptr) {
		head = tmp;
		tail = tmp;
	} else {
		tail = tmp;
		tail->next = tmp;
	}
	size++;
}

//Displays All Stored Values
CounterTop LinkedList::display(Node *head){

	while (head != nullptr) {
		head->data.Output();
		display(head->next);
		return head->data;
	}
}

 void LinkedList::disp(Node *head){
	if(head == nullptr)
	{
		cout << "NULL" << endl;
	}
	else
	{
		head->data.CounterTop::Output();
		disp(head->next);
	}
}

//Bool to check if List is Empty
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

