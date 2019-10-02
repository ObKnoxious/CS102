/*
 * Knox Crichton
 * October 9
 * Lab 6
 * COSC 102 Josh Dunn
 * TA: Katherine Huckaby
 * Description: Caclulates fee of speeding ticket
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
int main(){
	int tf, rf, m1, d1, y1, m2, y2, d2,;
	cout << "Enter a ticket file: ";
	cin >> tf;
	cout << "\nEnter a report file: ;
	cin >> rf;
	cout << "Enter report start date (mm dd yyyy): ";
	cin >> d1; cin >> m1; cin >> y1;
	ifstream i;
	i.open("input");
	if(!i){
		cerr << "File not found";
		exit(1);
	}


	i.close();
	return 0;
}

class Ticket{
	public:
	string citationNumber;
	int month;
	int day;
	int year;
	int speed;
	int limit;
	char road;
	
	Ticket(string c, int m, int d, int y, int s, int l, char r){
		citationNumber =c;
		month =m;
		day =d;
		year =y;
		speed =s;
		limit =l;
		road =r;
	}
}
