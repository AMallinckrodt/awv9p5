//
// Created by Alexander Mallinckrodt on 02/05/2021.
//

#ifndef AWV9P5_LINKEDLIST_H
#define AWV9P5_LINKEDLIST_H

#include "CounterTop.h"
#include <iostream>
#include <iomanip>

struct Node{
	CounterTop data;
	Node *next;
};

class LinkedList{

private:
	Node *head,*tail;
	int size = 0;

public:

	LinkedList() {head = nullptr; tail = nullptr;}
	~LinkedList(){clear();};

	Node* gethead()
	{return head;}//Inline function to return the header

	int getsize(){
		return size;} //Returns the Size of the Linked list

	bool empty(); //Bool to check if List is Empty
	void add_node(CounterTop&); //Adds another Value
	void clear(); //Function to Clear the List
	CounterTop display(Node *head); // Displays all Values in List
	static CounterTop Data(Node *ptr);


};



#endif //AWV9P5_LINKEDLIST_H
