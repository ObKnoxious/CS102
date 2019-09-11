/*
 * Knox Crichotn
 * Sepetember 4
 * Lab 3
 * COSC 102 Section 2
 * Lecturer: Josh Dunn
 * TA: Katherine Huckaby
 * Description: Determines if interstate is real, and what direction it is heading
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	int i;
	cout << "Enter an interstate number: ";
	cin >> i;
	string o = "I-" + to_string(i);
	if( i > 0 && i < 999 && i % 100 != 0){
		if(i > 100){
			int t = i % 100;
			o += " is an auxillary highway, serving I-" + to_string(t) + ",";
		} else {
			o += " is a primary interstate,";
		}
		if(i % 2 != 0){
			o += " going north/south.\n";
		} else {
			o += " going east/west.\n";
		}	
	} else {
		o = to_string(i) + " is not a valid interstate number.\n";
	}
	cout << o;
	return 0;
}
