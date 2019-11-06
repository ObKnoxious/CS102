/*
 * Knox Crichton
 * October 6
 * Lab 8
 * COSC 102 Josh Dunn
 * TA: Katherine Huckaby
 * Description: Plays Blackjack
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <sstream>
using namespace std;
// Started this by copying all of Lab 7 into this file 
int GetRandom(int mi, int ma){
	//srand(time(0));
	int d = ma - mi;
	int r = (rand() % d);
       	//cout << r << "\t";	
	return r;
}	
string DealCard(string (&deck)[52]){
	int n;
	bool s=true;
	while(s){
		n=GetRandom(0,52);
		//Checks if random value has an asterisk, meaning it's been used
		if(deck[n].back() != '*'){
			//If it didn't have an asterisk it is good to go, and one is added so it isn't re-used
			deck[n]+='*';
			s=false;
			//If this if doesn't run, it just pulls a different card
		}
	}
	return(deck[n]);
}
int ScoreHand(string deck[], vector<string> hand){
	//As far as I can tell the deck is useless for this
	//Uses only the first char in each string for score since suit is meaningless
	//string s1 = hand[0].resize(1);
	//string s2 = hand[1].resize(1);
	int sc;	
	for(int i=0;i<2;i++){
		char s1 = hand[i].at(0);
		//cout << hand[i] << "  ";
		if(s1 == 'A'){
			sc+=1;
		} else if(s1 == 'J' || s1 == 'Q' || s1 == 'K'){
			sc+=10;
		} else {
			stringstream v;
			v << s1;
			int x;
			v >>  x;
			//cout << x;
			sc+=x;
		} 
	}
	return sc;	
}
// Custom class for cards
class Card{
	public:
		Card(int c, char s);
		Card(int c, char s, int p);
		// Getters for each var, explained in private
		int getScore();
		int getValue();
		char getSuit();
		string getPrint();
		int getPlayer();
		// Setters for each var explained in private
		void setValue(int);
		void setSuit(char);
		void setPlayer(int);
	private:
		// Value, # of card
		int value;
		// Score value of card
		int score;
		// Suit of each card
		char suit;
		// Human readable string of each card
		string print;
		// What player this card is being held by 
		int player;

};
// Do I have to declare this outside of my class like this? I feel like this hurts organization
void Card::setValue(int v){
	     this->value = v;
}
void Card::setSuit(char c){
	     this->suit = c;
}
void Card::setPlayer(int p){
	     this->player = p;
}
Card::Card(int v, char s){
	setValue(v);
	setSuit(s);
}
Card::Card(int v, char s, int p){
	setValue(v);
	setSuit(s);
	setPlayer(p);
}
string Card::getPrint(){
 	t = getValue();
	
	if(t == 11){	
int main(){
	//Creating Deck
	//string deck[52] = {};
	//Based on mLab7 solution on canvas
	//string dv[]={"2","3","4","5","6","7","8","9","10","J","Q","K","A",};
	//string sv[]={"H","D","S","C"};
	//for(int i=0;i<52;i++){
	//	int x = i % 13;
	//	int y = i %4;
	//	string o = dv[x] + sv[y];
	//	deck[i]=o;
	//	cout << deck[i] << "  ";
	//}
	Card deck[52] = {}
	for(int i=0; i<52;i++){

	int  p;
	bool s = true;
	while(s){
		cout << "How many players? \n";
		cin >> p;
		if(p <= 26){
			s=false;
		} else {
			cout << "No more than 26 players";
		}
	// 2D vector of players, 1st dimmension is number of players
	// Second is 2 because that is tthe number of cards in each players hand
	//vector<vector<string> > players(p);
	//for(int i =0; i<p;i++){
	//	players[i].resize(2);
	//}
	//for(int i=0; i<p;i++){
	//	for(int j=0; j<2;j++){
	//		players[i][j]=DealCard(deck);
	//		}
//		int o2=ScoreHand(deck,players[i]);
//		//Final output
//		cout << "Player " << i+1 << " has cards: ";
//		string of = players[i][0].substr(0, players[i][0].size()-1) + " " + players[i][1].substr(0, players[i][0].size()-1);
//		// I need o2 as a string for output and i know there is a better way to do this but i've spen too long on this and just doing what i know works
//		stringstream oy;
//		oy << o2;
//		string ox = "(" + oy.str() + ")";
//		cout << left << setw(20) << of << setw(4) << right << ox << "\n";
//		}
	}
}

