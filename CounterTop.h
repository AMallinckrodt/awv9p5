/*
* CounterTop.h
*
* COSC 051
* Project #5
*
* Author: Alexander von Mallinckrodt
*
* In accordance with the class policies and Georgetown's
* Honor Code, I certify that, with the exception of the
* class resources and those items noted below, I have neither
* given nor received any assistance on this project.
*
* References not otherwise commented within the program source code. * Note that you should not mention any help from the TAs, the professor, * or any code taken from the class textbooks.
*/

#ifndef AWV9P4_COUNTERTOP_H
#define AWV9P4_COUNTERTOP_H


#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CounterTop {
private:
	CounterTop* next;
	string region;
	string ordercode;
	double height;
	double length;
	double depth;
	double price;
	int area;
	int lened;
	int deped;
	char stonecode;

public:
	CounterTop();

	void setData(string, string, double, double, double, double, int, int, int, char);

	double getP() const {
		return price;
	}

	double getA() const {
		return area;
	}

	string getR() const {
		return region;
	}

	char getSC() const {
		return stonecode;
	}

	void Output();

	void OrderOutput() const;

	bool Comparator(string) const;

	// Operator & Listing Functions

	CounterTop& operator= (CounterTop &obj) = default;

	void setnext(CounterTop* N){next = N;}

	CounterTop* getnext(){return next;}

};


#endif //AWV9P4_COUNTERTOP_H
