/*
 * For Lab 4; bank account simulation
 * Knox Crichton
 * September 11
 * Professor: Dr. Dunn
 */
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	float bal =0;
	float n=0;
	string i;
	bool s=true;
	cout << "Enter your initial account amount: \n";
	cin >> bal;
	map<string, int> mi;
	mi.insert(pair<string, int>("deposit", 1));
	mi.insert(pair<string, int>("withdrawl", 2));
	mi.insert(pair<string, int>("balance", 3));
	mi.insert(pair<string, int>("quit", 4));

	while(s){
		cout << "What do you want to do? \n";
		cin >> i;
		switch(mi[i]){
			case 1:
				cout << "How much?\n";
				cin >> n;
				bal += n;
				cout << "You have $" + to_string(bal) +"\n";
				break;
			case 2:
				cout << "How much?\n";
				cin >> n;
				bal -= n;
				cout << "You have $" + to_string(bal) +"\n";
				break;
			case 3:
				cout << "You have $" + to_string(bal) +"\n";
				break;
			case 4:
				s = false;
				break;
			default:
				cout << "Not valid option\n";
				break;
		}
	}


	return 0;
}

