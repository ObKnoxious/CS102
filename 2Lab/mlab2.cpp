// For Lab 2; accepts and repeats housing information
// Knox Crichton
// August 26
// Professor: Dr. Dunn

#include <iostream>
using namespace std;

vector <string> addParse(string fA){
	vector <string> tokens;
	stringstream check1(fA);
	string mid;
	while(getline(check1, mid, ' ')){
		tokens.push_back(mid);
	}
	return tokens;
}

int main(){
	int addressNumber;
	string addressName;
	string roadType;
	int lMonth;
	int tMonth;
	int arrayAdd;
	string fullAddress;
	cin >> fullAddress;
	arrayAdd = addParse(fullAddress);
	for(int i = 0; < arrayAdd.size(); i++)
		cout << arrayAdd[i] << '\n';
	return 0;

}
