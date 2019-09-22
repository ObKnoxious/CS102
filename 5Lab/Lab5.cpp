/*
 * Knox Crichton
 * September 25
 * Lab 5
 * COSC 102 Josh Dunn
 * TA: Katherine Huckaby
 * Description: Simulates a slot machine
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
	cout << fixed << setprecision(2);
	double b = 1000;
	bool sent = true;
	double s;
	cout << "Input a seed: \n";
	cin >> s;
	srand(s);
	double e;
	vector<double> wi;
	vector<double> wa;
	int r0[7];
	int r1[7];
	int r2[7];
	for(int i=0;i<=5;i++){
		r0[i]=i+2;
	}
	for(int i=0;i<=5;i++){
		r1[i]=i+2;
	}
	for(int i=0;i<=5;i++){
		r2[i]=i+2;
	}
	int t0;
	int t1;
	int t2;
	int m =1;
	while(sent){
		cout << "Your money: $" << b <<"\n" << "Place a bet: $";
		cin >> e;
		if(e > 0 && e <= b && b>0){
			b-=e;
			wa.push_back(e);
			t0 = r0[rand() % 5];
			t1 = r1[rand() % 5];
			t2 = r2[rand() % 5];
			if(t0 == t1 && t1 == t2 && t1 == 7){
				m =10;
			}else if(t0 == t1 && t1 == t2){
				m=5;
			}else if(t0 == t1 || t1 == t2 || t2 == t0){
				m=2;
			}else{
				m=0;
			}
			wi.push_back(e*m);
			cout << "\n " << t0 << " " << t1 << " " << t2 << " \n";
			b += e*m;
			if((e*m) > 0){
				cout << "You won $" << e*m << "!\n";
			} else {
				cout << "You didn't win.\n";
				if(b<=0){
				sent=false;
				}
			}

		}else if(e==0){
			sent=false;
		}
				
	}
	double miwa=1001;
	double miwi=1001;
	double mwa=0;
	double mwi=0;
	for(int i=0;i<wa.size();i++){
		cout << "You wagered $" << wa[i] << " and won $" <<wi[i] <<".\n";
		if(wa[i]>mwa){
			mwa=wa[i];
		}
		if(wa[i]<miwa){
			miwa=wa[i];
		}
		if(wi[i]>mwi){
			mwi=wi[i];
		}
		if(wi[i]<miwi){
			miwi=wi[i];
		}
	}
	cout << "Your smallest wager was $" << miwa << ".\nYour largerst wager was $" << mwa << ".\nYour smallets winnings was $" << miwi << ".\nYour largest winnings was $" << mwi << ".\n";

	return 0;
}


