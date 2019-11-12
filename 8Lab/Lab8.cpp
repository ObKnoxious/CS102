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
/*
 * I gutted most of my Lab 7 code before this. My TA grader told me my code didn't solve the problem in the most efficient way
 * I wanted to write a custom class for lab 7 (actually the last several labs) and finally got to do it here since we covered them in class
 * (Get it class in class, sorry for bad pun)
 */
// Prototype for random
int GetRandom(int mi, int ma);
// Declaration for random
int GetRandom(int mi, int ma){
	//srand(time(0));
	int d = ma - mi;
	int r = (rand() % d);
       	//cout << r << "\t";	
	return r;
}	
/*string DealCard(string (&deck)[52]){
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
}*/
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
		Card(int c, int s);
		Card(int c, int s, int p);
		// Getters for each var, explained in private
		int getScore();
		int getValue();
		char getSuit();
		string toString();
		int getPlayer();
		// Setters for each var explained in private
		void setValue(int);
		void setSuit(int);
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
// Do I have to declare this outside of my class like this? I feel like this hurts organizationi but this is how this was done in the slides so I'm using that style
// I don't think we explicity covered this-> in class but I was raised on Java and it's baked into me to write classes with this-> in mutator functions
// It would be bad to have all data publicly accessible for this as it would be easy to change stuff accidentally, so in order to keep variables private I need this->
void Card::setValue(int v){
	this->value = v;
}
void Card::setSuit(int c){
	// gets int from loop and assigns suit to a char based on modulo of 52
	if(c == 0){
		this->suit = 'H';
	} else if(c == 1){
		this->suit = 'D';
	} else if(c == 2){
		this->suit = 'C';
	} else if(c == 3){
		this->suit = 'S';
	} else{
		// Assigns invalid options to e to signify error 
		this->suit= 'E';
	}
}
void Card::setPlayer(int p){
	     this->player = p;
}
Card::Card(int v, int s){
	setValue(v);
	setSuit(s);
	setPlayer(-1);
}
Card::Card(int v, int s, int p){
	setValue(v);
	setSuit(s);
	setPlayer(p);
}
string Card::toString(){
 	int t = getValue();
	stringstream f;
	// Determining jack, queen, king, and ace
	if(t == 11){
		f << 'J' << this->getSuit();
	} else if(t == 12){
		f << 'Q' << this->getSuit();
	} else if(t == 13){
		f << 'K' << this->getSuit();
	} else if(t == 14){
		f << 'A' << this->getSuit();
	} else {
		f << t << this->getSuit();
	}

	return f.str();
}
int Card::getValue(){
	return this->value;
}
char Card::getSuit(){
	return this->suit;
}
int Card::getPlayer(){
	return this->player;
}
// Prototype for deck creation function
//makeDeck(Card *deck[52]);
// actual declaration of function
// YES I know there is a pointer here, I explain more on that later
//void makeDeck(Card *deck[52]){
//	for(int i=0; i<52;i++){
//		deck[i] = new Card(i%13+2,i%4);
//		//cout << deck[i]->toString() << "\t";		
//	}
//}
//Protoytpe for deck funtion
void makeDeck(vector<Card> &deck);
//Declaration for deck funtion
void makeDeck(vector<Card> &deck){
//	for(int i=0; i<52;i++){
//		deck[i] = Card(i%13+2,i%4);
//		cout << deck[i].toString() << "\t";		
//	}
}
// Prototype for deal card
// This is void, since we are just assigning the object value player for who has the cardi
// The above line is no longer true
int deal(vector<Card> &deck, int p);
// Declaration for deal card
int deal(vector<Card> &deck, int p){
	bool s = true;
	int k;
	while(s){
		k = GetRandom(0,52);
		if(deck[k].getPlayer() == -1){
			deck[k].setPlayer(p);
			s = false;
		}
	
	}
	//Also returning number drawn to avoid chaos
	return k;

}
// Finds cards assigned to a certain player
// It is at this point I recognize my player system is kinda dumb but I'm commited to it now
/*vector<int> findCard(Card deck[52], int p){
	vector<int> r;
	for(int i =0; i< 52; i++){
		if(deck[i].getPlayer() = p){
			r.push_back(i);
		}
	}
}
*/

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
	// So yes, I used a pointer in this lab when we haven't mentioned them at all
	// I know this is *kinda* against the rules but I didn't want the pain of solving this entire thing with a maze of varriables
	// So a class was needed, I wanted to use a vector here, but in the lab restrictions I was told to pass an array into a function
	// I was choosing to break the rules on vectors or pointers, and I went with pointers
	//Card *deck[52];
	//makeDeck(deck);
	vector<Card> deck;
	makeDeck(deck);
	// 0 is dealer, 1 is player
	vector<int> dealer = {deal(deck, 0),deal(deck, 0)};
	vector<int> player = {deal(deck, 1),deal(deck, 1)};
	int t = deal(deck, 0);
	bool playing = true;
	while(playing){
		string o1;
		string o2;
//		for(int i =0; i< dealer.size(); i++){
//			o1 += deck[i].toString() + " ";
//		}
		cout << "Dealer has cards: " << o1 << "\n";
//		for(int i =0; i< player.size(); i++){
//			o2 += deck[i].toString() + " ";
//		}
		cout << "Player has cards: " << o2 << "\n";
		cout << "Hit or stand ?";
		string ui;
		cin >> ui;
		if(ui == "stand"){
			playing = 0;
		}
	}
}

