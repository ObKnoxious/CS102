// For Lab 2; accepts and repeats housing information
// Knox Crichton
// August 26
// Professor: Dr. Dunn

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
	int addressNumber;
	string addressName;
	string roadType;
	int lMonth;
	int tMonth;
	cout << "Please enter your street address.\n";
	cin >> addressNumber >> addressName >> roadType;
	string fullAddress = to_string(addressNumber) + " " +  addressName + " "  + roadType;
	cout << "What was your rent last month?\n";
	cin >> lMonth;
	cout << "What was your rent this month?\n";
	cin >> tMonth;
	cout << fullAddress << " was worth $" << lMonth << " last month and is worth $" << tMonth << " this month.\n";
	return 0;

}
