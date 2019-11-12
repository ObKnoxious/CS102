/*
 * For Lab 7 Check if date is in range
 * Knox Crichton
 * September 25
 * Professor: Dr. Dunn
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;
int main(){
	int cards[52] = {};
	for(int i = 0; i < 52; i++){
		if(i <= 8){
			cards[i] = i +2;
		} else if(i >= 13 && i <= 21){
			cards[i] = i -11;
		} else if(i >= 26 && i <= 34){
			cards[i] = i - 24;
		} else if(i >= 39 && i <= 47){
			cards[i] = i - 37;
		}	
	}
	cards[9] = 74;cards[10]=81;cards[11]=75;cards[12]=65; 
	cards[22] = 74;cards[23]=81;cards[24]=75;cards[25]=65; 
	cards[35] = 74;cards[36]=81;cards[37]=75;cards[38]=65; 
	cards[48] = 74;cards[49]=81;cards[50]=75;cards[51]=65; 
	char o;
	int in;
	cout << "Enter a card index: ";
	cin >> in;
	string t = "That's the ";
	string h = " of Hearts";
	string d = " of Diamonds";
	string s = " of Spades";
	string c = " of Clubs";
	if(in <=8){
		cout << t << cards[in] << h;
	} else if(in >=9 && in <=12){
		o = cards[in];
		cout << t << o << h;
	} else if(in >=13 && in <= 21){
		cout << t << cards[in] << d;
	} else if(in >=22 && in<=25){
		o = cards[in];
		cout << t << o << d;
	} else if(in >=26 && in<=34){
		cout << t << cards[in] << s;
	} else if(in >= 35 && in <=38){
		o = cards[in];
		cout << t << o << s;
	} else if(in >=39 && in<= 47){
		cout << t << cards[in] << c;
	} else if(in >-48 && in<= 51){
		o = cards[in];
		cout << t << o << c;
	}
	return 0;

	
}

