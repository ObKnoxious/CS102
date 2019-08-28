/*
 * Knox Crichton
 * August 28
 * Lab 2
 * COSC102 - Section 2 - Fall 2019
 * Lecturer: Josh Dunn
 * TA: Katherine Huckaby
 * Description: Takes in address information and cost, repeats that as output and calculates mortgage
 */
#include <iostream>
#include <string>
using namespace std;
int main(){
	int addressNumber; // Number for stresst address
	string addressName; // Name of road property is on
	string roadType; // Street, Road, Drive, etc.
	int lMonth; // Last months rent
	int tMonth; // This months rent 
	cout << "Enter the property street number, name, and type: ";
	cin >> addressNumber >> addressName >> roadType;
	string fullAddress = to_string(addressNumber) + " " +  addressName + " "  + roadType;
	cout << "Last month's property value: $";
	cin >> lMonth;
	cout << "This month's property value: $";
	cin >> tMonth;
	cout << "This property is located at " << fullAddress << ".\nIts value changed by $" << tMonth - lMonth << " since last month.\nThe estimated monthly mortgage is $" << tMonth*0.045/12 << ".";
	return 0;
}
