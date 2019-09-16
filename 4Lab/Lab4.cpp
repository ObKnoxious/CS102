/* 
 * Knox Crichton
 * September 18
 * Lab 4
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
	string i;
	bool sent = true;
	map<string, int> mi;
	mi.insert(pair<string, int>("car", 1));
	mi.insert(pair<string, int>("truck", 2));
	mi.insert(pair<string, int>("done", 3));
	double t1;
	double t2;
	vector<double>cmpg;
	vector<double>tmpg;
	double ct;
	double tt;
	while(sent){
		cout << "Enter command: \n";
		cin >> i;
		switch(mi[i]){
			case 1:
				cout << "Enter car's miles: \n";
		 		cin >> t1;
			 	cout << "Enter car's gallons: \n";
				cin >> t2;
				cmpg.push_back(t1/t2);
				break;
			case 2:
				cout << "Enter truck's miles: \n";
				cin >> t1;
				cout << "Enter truck's miles: \n";
				cin >> t2;
				tmpg.push_back(t1/t2);
				break;
			case 3:
				sent = false;
				break;
			defulat:
				cout << "Not valid input \n";
				break;
		}
	}
	for(double i : cmpg){
		ct+=i;
	}
	ct= ct/cmpg.size();
	for(double i : tmpg){
		tt+=i;
	}
	tt= tt/tmpg.size();
	cout << "Average car MPG = " << ct << "\n";
	cout << "Average truck MPG = " << tt << "\n";
	return 0;
}
