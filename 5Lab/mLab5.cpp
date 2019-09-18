/*
 * For Lab 5; Random Number array
 * Knox Crichton
 * September 18
 * Professor: Dr. Dunn
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int main(){
	int i;
	cout << "Enter a seed: \n";
	cin >> i;
	vector<int> r;
	srand(i);
	for(int k=0;k<25;k++){
		r.push_back(rand()%21 -10);
	}
	int t=0;
	for(int l : r){
		t+=l;
	}
	cout << "Sum of array = " << t << ".\n";	
	return 0;

}
