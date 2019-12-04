/* 
 * Knox Crichton
 * December 4 
 * Lab 11 - Redo of Lab 4
 * COSC 102 Section 2
 * Lecturer Josh Dunn
 * TA: Katherine Huckaby
 * Description: Calculates a fleets car and truck mpg
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	// Initial input
	string i;
	// Sentinel value for first loop
	bool sent = true;
	// secondary inputs
	double t1 = -1;
	double t2 = -1;
	// car miles, car gallons, truck miles, truck gallons, number of cars, number of trucks
	double cm=0, cg=0, tm=0, tg=0, nc=0,nt=0;
	while(sent){
		cout << "Enter command: \n";
		cin >> i;
		// Checks if valid input in else 
		if(i == "car"){
			// second sentinel value
			bool s2 = true;
			while(s2){
				cout << "Enter car's miles: \n";
				cin >> t1;
				// Loop does not break if input is invalid and runs until valid input is given
				if(t1 > 0){s2=false;}
			}
			nc+=1;
			cm+=t1;
			s2=true;
			while(s2){
				cout << "Enter car's gallons: \n";
				cin >> t2;
				// Loop does not break if input is invalid and runs until valid input is given
				if(t2 > 0){s2=false;}
			}
			cg+=t2;
		}else if(i == "truck"){
			bool s2 = true;
			while(s2){
				cout << "Enter truck's miles: \n";
		 		cin >> t1;
				// Loop does not break if input is invalid and runs until valid input is given
				if(t1 > 0){s2=false;}
			}
			// Adds one to number of trucks after validating input
			nt+=1;
			tm+=t1;
			s2=true;
			while(s2){
				cout << "Enter truck's gallons: \n";
				cin >> t2;
				// Loop does not break if input is invalid and runs until valid input is given
				if(t2 > 0){s2=false;}
			}
			tg+=t2;
		}else if(i == "done"){
			sent=false;
		}else{
			cout << "Unknown command";
		}
	}
	if(nt >0 && nc >0){
		//normal output for if there are multiple trucks and cars
		double ct = cm/cg;
		double tt = tm/tg;
		cout << "Average car MPG = " << ct << "\n";
		cout << "Average truck MPG = " << tt << "\n";
		return 0;
	}else if(nc >0){
		double ct = cm/cg;
		cout << "Average car MPG = " << ct << "\n";
		cout << "No Trucks in Fleet\n";
	}else if(nt >0){
		double tt = tm/tg;
		cout << "Average truck MPG = " << tt << "\n";
		cout << "No cars in Fleet\n";
	}else{
		cout << "No cars in Fleet\nNo Trucks in Fleet\n";
	}
}
