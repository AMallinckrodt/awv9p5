/*
* awv9p5.cpp
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

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
#include "CounterTop.h"
#include "LinkedList.h"


using namespace std;


// Global Constants

const float markup = 1.26;
const float HL = 0.58;
const float HU = 0.8;
const int maxv = 25;
const int minv = 5;
const float PM = 92.99;
const float PG = 78.99;
const float PQ = 56.99;

// Program Functions

char displayMenu();

string get_file_path();

void uploadfile(string, bool, LinkedList &);

void alldetails(LinkedList &);

void orderdetails(LinkedList &);

void summaryregion(LinkedList &);

void summarystone(LinkedList &);

bool clearallvectors(LinkedList &);

int main() {

	bool validation = false;
	LinkedList *Data = nullptr;

// Introduction Message

	cout << endl << "Welcome to Claude's Custom Counters Inc.\n"
	                "This application calculates cost and fabrication data based on "
	                "sales data input files";


// Calling Loop:

	char choice = '?';
	bool cleared;

	while (choice != 'q' && choice != 'Q') {

		choice = displayMenu();
		string filename;

		switch (choice) {

			case 'U':
			case 'u':
				filename = get_file_path();
				uploadfile(filename, validation, *Data);
				break;

			case 'A':
			case 'a':
				alldetails(*Data);
				break;

			case 'O':
			case 'o':
				orderdetails(*Data);
				break;

			case 'R':
			case 'r':
				summaryregion(*Data);
				break;

			case 'S':
			case 's':
				summarystone(*Data);
				break;

			case 'C':
			case 'c':
				cleared = clearallvectors(*Data);
				if (!cleared) {
					cout << "Vectors are already Empty.\n";
				}
				break;

			case 'q':
			case 'Q':
				cout << endl << "Exiting Program. Goodbye." << endl;
				break;

		}
	}


	return 0;
}

string get_file_path() {

	string filename;

	cout << "Please input the name and path of the File you wish to open:\n";

	cin >> filename;

	return filename;
}

char displayMenu() {

	string choice;
	char returning;
	bool error = true;

	while (error) {

		error = false;
		cout << setw(40) << endl << "MENU" << endl << endl <<
		     setw(40) << "Upload a regional sales data file" << setw(6) << "U" << endl <<
		     setw(40) << "Display details (All loaded data)" << setw(6) << "A" << endl <<
		     setw(40) << "List details for specific Order number" << setw(6) << "O" << endl <<
		     setw(40) << "Display Summary by Region" << setw(6) << "R" << endl <<
		     setw(40) << "Display Summary by Stone code" << setw(6) << "S" << endl <<
		     setw(40) << "Clear all vectors" << setw(6) << "C" << endl <<
		     setw(40) << "Quit" << setw(6) << "Q" << endl;

		cout << "Please enter your choice:\t";
		cin >> choice;

		switch (choice[0]) {

			case 'U':
			case 'u':
				break;

			case 'A':
			case 'a':
				break;

			case 'O':
			case 'o':
				break;

			case 'R':
			case 'r':
				break;

			case 'S':
			case 's':
				break;

			case 'C':
			case 'c':
				break;

			case 'q':
			case 'Q':
				break;

			default:
				cout << endl << "ERROR: Invalid Choice";
				error = true;
				break;
		}
		returning = choice[0];
	}
	return returning;
}

void uploadfile(string filename, bool validation, LinkedList &Data) {

// Variables:
	string line, OC, NA, STC, REG;
	int od, om, oy, dd, dm, dy, LE, DE, count, count2, correct, change;
	int errorcount = 0, totalcount = 0, C = 0;
	char slash, SC;
	double P, L, D, H, area, Cost, edgecost;

// File Validation
	ifstream inFile;
	inFile.open(filename.c_str());

	if (!inFile) {
		cout << "Unable to open file" << endl;
	} else {
		cout << "Ok! Opening File..." << endl;

		while (!validation) {
			getline(inFile, line);
			while (inFile >> oy >> slash >> om >> slash >> od >> dy >> slash >> dm >> slash >>
			              dd >> SC >> L >> D >> H >> LE >> DE >> OC >>
			              REG && getline(inFile, NA)) {

				totalcount++; // Counts total inputs (doesn't remove errors)

				// While Variables
				bool error = false;
				string material;
				char regcode;

				// Processing Table Output

				cout << setw(4) << oy << slash
				     << setw(2) << setfill('0') << om << slash
				     << setw(2) << od << "\t" << setfill(' ')
				     << setw(4) << dy << slash
				     << setw(2) << setfill('0') << dm << slash
				     << setw(2) << dd << "\t" << setfill(' ')
				     << setw(2) << SC
				     << setw(8) << L
				     << setw(8) << D
				     << setw(8) << H
				     << setw(3) << LE << setw(5)
				     << setw(3) << DE << setw(5)
				     << setw(7) << REG;

				// Add validation here to check if Order is already uploaded

				// Stonecode Validation & Price Value

				switch (SC) {

					case 'm':
					case 'M':
						P = PM;
						break;

					case 'g':
					case 'G':
						P = PG;
						break;

					case 'q':
					case 'Q':
						P = PQ;
						break;

					default:
						error = true;
						cout << endl << "\tERROR: Invalid Stonecode";
						break;
				}

				// Validate Correct Region

				regcode = REG[0];
				switch (regcode) {

					case 'n':
					case 'N':
						break;

					case 's':
					case 'S':
						break;

					case 'e':
					case 'E':
						break;

					case 'w':
					case 'W':
						break;

					case 'o':
					case 'O':
						break;

					default:
						error = true;
						cout << endl << "\tERROR: Invalid Region";
						break;

				}

				// Delivery & Order Date Validation
				if (dy > (oy + 1)) {
					error = true;
					cout << endl << "\tERROR: delivery date is too far from order date.";
				}

				if (dy == oy && (dm - om) > 4) {
					error = true;
					cout << endl << "\tERROR: delivery date is too far from order date.";
				}

				if ((dy - oy) == 1 && (om - dm < 8)) {
					error = true;
					cout << endl << "\tERROR: delivery date is too far from order date.";
				}

				if (oy == dy && om == dm && od == dd) {
					error = true;
					cout << endl << "\tERROR: order date and delivery date are equal.";
				}

				if (oy == dy && om == dm && od > dd) {
					error = true;
					cout << endl << "\tERROR: order day is after delivery day.";
				}

				// Validate length, depth, height

				if (L < minv || L > maxv) {
					error = true;
					cout << endl << "\tERROR: invalid length.";
				}

				if (D < minv || D > maxv || D > L) {
					error = true;
					cout << endl << "\tERROR: invalid depth.";
				}

				if (H < (D * HL) || H > (D * HU)) {
					error = true;
					cout << endl << "\tERROR: invalid height.";
				}

				// Polished Edges Validation

				if (LE > 2) {
					error = true;
					cout << endl << "\tERROR: invalid number of length edges to finish.";
				}

				if (DE > 2) {
					error = true;
					cout << endl << "\tERROR: invalid number of depth edges to finish.";
				}

				if (!error) {

					count = Data.getsize();

					//Price and Area Calculations

					area = H * L;
					area = ceil(area *= markup);

					Cost = area * P;
					edgecost = ((DE * D) + (LE * L)) * 4.99;
					Cost = Cost += edgecost;

					// Output Area & Price in Processing Table

					cout << fixed << showpoint << setprecision(2) <<
					     setw(10) << area <<
					     setw(10) << Cost << endl;

					// Create Class and Upload to Vector

					CounterTop Counter;

					Counter.setReg(REG);
					Counter.setOC(OC);
					Counter.setH(H);
					Counter.setL(L);
					Counter.setD(D);
					Counter.setA(area);
					Counter.setP(Cost);
					Counter.setLE(LE);
					Counter.setDE(DE);
					Counter.setSC(SC);

					Data.add_node(Counter);

				} else {
					cout << endl << endl;
					errorcount++;
				}
			}

			// Error Output

			correct = (totalcount - errorcount);

			// Test for Uploading to List

			count2 = Data.getsize();
			change = count2 - count;

			if (change > correct) {
				validation = false;
				cout << "Incorrect Output. Trying Again." << endl;
			} else {
				validation = true;
				cout << "Data successfully transferred." << endl;

				cout << endl << "Counts: " << endl
				     << "\tTotal Records: " << totalcount << endl
				     << "\tRecords with Errors: " << errorcount << endl
				     << "\tRecords without Errors: " << correct << endl;

				inFile.close();
				return;
			}
		}
	}
}

void alldetails(LinkedList &Data) {

	bool vectors = Data.empty();
	int count = 0;
	double tarea = 0, tcost = 0;
	double area, Price;
	Node *head = Data.gethead();
	CounterTop Counter;

	if (vectors) {
		for (int I = 0; I < Data.getsize(); I++) {
			count++;

			Counter = Data.display(head);

			area = Counter.getA();
			Price = Counter.getP();

			tarea += area;
			tcost += Price;
		}


		cout << endl << "\t" << setw(10) << "TOTALS" << endl;
		cout << "-------------------------------------" << endl;
		cout << setw(15) << "Records:" << setw(15) << count << endl
		     << setw(15) << "Material Used:" << setw(15) << tarea << endl
		     << setw(15) << "Cost ($):" << setw(15) << tcost << endl;
		cout << "-------------------------------------" << endl;
	} else {
		cout << "No Data in List.\n";
	}
}

void orderdetails(LinkedList &Data) {
	bool vectors = Data.empty();
	bool valid = false;
	int attempts = 0;


	if (vectors) {

		while (!valid) {
			attempts++;
			string search;

			cout << endl << "Please Input the Order Number:  ";
			cin >> search;

			int i = 0;
			int n = Data.getsize();

			Node* tmp = Data.gethead();

			while (tmp != nullptr) {
				if (tmp->data.Comparator(search))  //If element is present in the list
				{
					tmp->data.OrderOutput();
					valid = true;
				} else {
					i++;
					tmp = tmp->next;}
			}

			if (i == n)
			{
				cout << endl << "Invalid Order Number" << endl;
				valid = true;
			}

			if (attempts >= 3) {
				char input;

				cout << endl <<
				     "You have entered three incorrect Order Numbers.\n"
				     "Would you like to return to the menu? [Y/N]: "
				     << endl;
				cin >> input;

				switch (input) {

					case 'Y':
					case 'y':
						cout << "Exiting to Menu" << endl;
						return;
						break;

					default:
						attempts = 0;
						break;
				}
			}
		}
	} else {
		cout << "No Data in List.\n";
	}
}

void summaryregion(LinkedList &Data) {
	bool vectors = Data.empty();

	double costN = 0, costS = 0, costE = 0, costW = 0, costO = 0;
	double areaN = 0, areaS = 0, areaE = 0, areaW = 0, areaO = 0;
	int countN = 0, countS = 0, countE = 0, countW = 0, countO = 0;
	int countA, areaA;
	double costA;
	double area, P, Price, edgecost;



	if (vectors) {

		for (int I = 0; I < Data.getsize(); I++) {

			Node* tmp;
			tmp = Data.gethead();


			while (tmp != nullptr) {

				CounterTop iter = Data.Data(tmp);

				const string r = iter.getR();

				switch (r[0]) {

					case 'N':
					case 'n':

						area = iter.getA();
						Price = iter.getP();

						countN++;
						costN += Price;
						areaN += area;
						break;

					case 'S':
					case 's':

						area = iter.getA();
						Price = iter.getP();

						countS++;
						costS += Price;
						areaS += area;
						break;

					case 'E':
					case 'e':

						area = iter.getA();
						Price = iter.getP();

						countE++;
						costE += Price;
						areaE += area;
						break;

					case 'W':
					case 'w':

						area = iter.getA();
						Price = iter.getP();

						countW++;
						costW += Price;
						areaW += area;
						break;

					case 'O':
					case 'o':

						area = iter.getA();
						Price = iter.getP();

						countO++;
						costO += Price;
						areaO += area;
						break;
				}
				*tmp->next;
			}

			// Final Table Output
			cout << "\n\t" << "TOTALS (Summary by Region)" << endl;
			cout << setw(7) << "Region"
			     << setw(15) << "Total Orders"
			     << setw(15) << "Total Area"
			     << setw(18) << "Total Cost ($)"
			     << endl;
			cout << "-------------------------------------------------------------------" << endl;

			cout << setw(7) << "North" <<
			     setw(15) << countN <<
			     setw(15) << areaN <<
			     setw(18) << costN <<
			     endl;

			cout << setw(7) << "South" <<
			     setw(15) << countS <<
			     setw(15) << areaS <<
			     setw(18) << costS <<
			     endl;

			cout << setw(7) << "East" <<
			     setw(15) << countE <<
			     setw(15) << areaE <<
			     setw(18) << costE <<
			     endl;

			cout << setw(7) << "West" <<
			     setw(15) << countW <<
			     setw(15) << areaW <<
			     setw(18) << costW <<
			     endl;

			cout << setw(7) << "Other" <<
			     setw(15) << countO <<
			     setw(15) << areaO <<
			     setw(18) << costO <<
			     endl;

			cout << "-------------------------------------------------------------------" << endl;

			countA = countN += countS += countW += countE += countO;
			areaA = areaN += areaS += areaW += countE += countO;
			costA = costN += costS += costW += costE += costO;

			cout << setw(7) << "Total" <<
			     setw(15) << countA <<
			     setw(15) << areaA <<
			     setw(18) << costA <<
			     endl;

		}
	}
	else {
		cout << "No Data in List.\n";
	}
}

void summarystone(LinkedList &Data) {

	bool Valid = Data.empty();

	double costq = 0, costg = 0, costm = 0;
	int areaq = 0, areag = 0, aream = 0;
	int countq = 0, countg = 0, countm = 0;
	double area, Price;

	if (Valid) {

		for (int I = 0; I < Data.getsize(); I++) {

			Node* tmp;
			tmp = Data.gethead();

				CounterTop iter = Data.Data(tmp);


			switch (iter.getSC()) {

				case 'm':
				case 'M':

					area = iter.getA();
					Price = iter.getP();

					countm++;
					aream += area;
					costm += Price;
					break;

				case 'g':
				case 'G':

					area = iter.getA();
					Price = iter.getP();

					countg++;
					areag += area;
					costg += Price;
					break;

				case 'q':
				case 'Q':

					area = iter.getA();
					Price = iter.getP();

					countq++;
					areaq += area;
					costq += Price;
					break;
			}
			*tmp->next;
		}
		// Stone Summary Table
		cout << "\n\tTOTALS (Summary by Stone)" << endl;
		cout << setw(10) << "Stone"
		     << setw(9) << "Count"
		     << setw(15) << "Square Feet"
		     << setw(18) << "Cost ($)"
		     << endl;
		cout << "--------------------------------------------------------" << endl;

		cout << setw(10) << "Marble" <<
		     setw(9) << countm <<
		     setw(15) << aream <<
		     setw(18) << costm <<
		     endl;

		cout << setw(10) << "Granite" <<
		     setw(9) << countg <<
		     setw(15) << areag <<
		     setw(18) << costg <<
		     endl;

		cout << setw(10) << "Quartz" <<
		     setw(9) << countq <<
		     setw(15) << areaq <<
		     setw(18) << costq <<
		     endl;

		cout << "--------------------------------------------------------" << endl;
	} else {
		cout << "No Data in List.\n";
	}
}

bool clearallvectors(LinkedList &Data) {
	bool valid = Data.empty();

	if (!valid) {
		cout << "Lists already cleared." << endl;
		return true;
	} else {
		bool loop = false;
		char V;

		while (!loop) {
			cout << "Would you Like to clear Data? [Y/N]" << endl;
			cin >> V;

			switch (V) {
				case 'Y':
				case 'y':
					cout << "Clearing Vectors..." << endl;

					Data.~LinkedList();

					if (Data.empty()) {
						loop = true;
						return true;
					}
					return true;
					break;

				case 'N':
				case 'n':
					cout << "Returning to Menu" << endl;
					loop = true;
					return true;
					break;

				default:
					cout << "Invalid input, try again" << endl;
					loop = false;
					break;
			}
		}
	}
	return true;
}
