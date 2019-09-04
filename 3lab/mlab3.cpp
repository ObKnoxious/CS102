// For Lab 3; determines if interger is even or odd
// Knox Crichton
// September #rd
// Professor: Dr. Dunn

#include <iostream>
#include <string>
using namespace std;

int main(){
	int i;
	cout << "Enter an interger to determine if even or odd:";
	cin >> i;
	if(i % 2){
		cout << "This number is odd.\n";
	} else {
		cout << "This number is even.\n";
	}
}
