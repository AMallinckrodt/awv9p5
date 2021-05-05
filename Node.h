//
// Created by Alexander Mallinckrodt on 27/04/2021.
//

#ifndef LAB4_LISTNODE_H
#define LAB4_LISTNODE_H
#include <utility>

#include "CounterTop.h"


class Node {
private:
Node *next;
CounterTop data;

public:
// Constructor
	Node()
		{next = nullptr;
		 data = CounterTop();}

		 Node(CounterTop obj){
		next = nullptr;
		data = std::move(obj);}

Node* getnext(){return next;}
void setnext(Node* N){
	next = N;
}

};



#endif //LAB4_LISTNODE_H
