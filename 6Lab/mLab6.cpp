/*
 * For Lab 6; Check if date is in range
 * Knox Crichton
 * September 25
 * Professor: Dr. Dunn
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;
int tx(int y, int m, int d){
	struct tm t;
	time_t tx;
	t.tm_year=y-1900;
	t.tm_mon=m-1;
	t.tm_mday=d;
	t.tm_hour=0;
	t.tm_min=0;
	t.tm_sec=0;
	t.tm_isdst=-1;
	tx = mktime(&t);
	long int tt = static_cast<long int>(tx);
	return tt;
}

int main(){
	
	int m1, d1, y1, m2, d2, y2, m3, d3, y3;
	cout << "Enter start date: ";
	cin >> y1; cin >> m1; cin >> d1;
	cout <<"\nEnter end date: ";
	cin >> y2; cin >> m2; cin >> d2;
	cout <<"\nEnter date ";
	cin >> y3; cin >> m3; cin >> d3;
	int t1 = tx(y1, m1, d1);
	int t2 = tx(y2, m2, d2);
	int t3 = tx(y3, m3, d3);
	if(t3 < t2 && t3 > t1){
		cout << "\nIN RANGE\n";
	} else {
		cout << "\nOUT OF RANGE\n";
	return 0;
	}
}
	
