//
// Created by Alexander Mallinckrodt on 02/05/2021.
//

#ifndef AWV9P5_LINKEDLIST_H
#define AWV9P5_LINKEDLIST_H

#include "CounterTop.h"
#include <iostream>
#include <iomanip>


class LinkedList{

private:
	CounterTop* head;
	CounterTop* tail;
	int size = 0;

public:
	LinkedList(): head(nullptr), tail(nullptr){}

	~LinkedList() {clear();}; //Destructor

	void add_node(CounterTop); //Adds another Value

	int getsize(){return size;} //Returns the Size of the Linked list

	bool empty() const; //Bool to check if List is Empty

	void clear(); //Function to Clear the List

	void printlist();// Prints All Values in List

	CounterTop *gethead(){return head;}//Inline function to return the header

	CounterTop* gettail(){return tail;}

};


#endif //AWV9P5_LINKEDLIST_H
