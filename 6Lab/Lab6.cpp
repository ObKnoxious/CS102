/*
 * Knox Crichton
 * October 9
 * Lab 6
 * COSC 102 Josh Dunn
 * TA: Katherine Huckaby
 * Description: Caclulates fee of speeding ticket
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
	int m1, d1, y1, m2, y2, d2; // Months days and years for range
	vector<string> tnum; //Vector of ticket numbers
	vector<int> m; //Vector of months from input file
	vector<int> d; //Vector of days from input file
	vector<int> y; //Vector of years from input file
	vector<int> cs; //Vector of clocked speed from input file
	vector<int> sl; //Vector of speed limits from input file
	vector<char> rt; //Vector of road types from input file
	// All vectors should be the same length at all times
	ifstream infile;
	string fname;
	cout << "Enter a ticket file: ";
	cin >> fname;
	infile.open(fname);
	if(!infile.is_open()){
		cout << "File not open";
	}
	string fileline;
	vector<string> fline;
	while(getline(infile, fileline)){//Get's every file line of the file and stores into vector
		fline.push_back(fileline);
	}
	string tt; char trt; //temp values for ticket and road
	int tm, td, ty, tcs, tsl; //temp values for date and speeds
	for(string i : fline){ // This loop takes the values of each line in the input file and converts it to stringstreams
		// Then takes those ss and breaks them into temp values which are added to individual arrays
		// Wow I wish there was some way to have one object that could hold multiple related data types defined by me...
		stringstream si(i);
		si>>tt;si>>tm;si>>td;si>>ty;si>>tcs;si>>tsl;si>>trt;
		//The above line shouldn't have to be broken like that. It should work as si >> tt >> tm >> td...
		//It kept throwing errors for me so I broke it up
		tnum.push_back(tt);
		m.push_back(tm);
		d.push_back(td);
		y.push_back(ty);
		cs.push_back(tcs);
		sl.push_back(tsl);
		rt.push_back(trt);
	}
	infile.close();
	// Fine Vector
	vector<double> f;
	double tf;
	doublt tv;
	for(i =0; i < fline.size(); i++){
		tv = cs.at(i) - sl.at(i);
		switch(rt.at(i)){
			case i:
				tf = tv * 5.2252;
				f.push_back(tf);
				break;
			case h:
				tf = tv * 9.4412;
				f.push_back(tf);
				break;
			case r:
				ft = tv * 17.1525;
				f.push_back(tf);
				break;
			default: 
				ft = tv * 12.152;
				f.push_back(tf);
		}
	}
	ofstream ofile;
	string fto;
	cout << "Enter a report file: ";
	cin >> fto;
	ofile.open(fto);
	string marr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	for(int i = 0; i < fline.size(); i++){
			ofile << setfill('0') << setw(2)
			       	<< d.at(i) << "-" << marr[m.at(i)-1] << 
				"-" << y.at(i) << " " << 
				setfill(' ') << setw(10) << left << tnum.at(i) << "$" <<
				; 
	}
	
	/*vector<string> oline; //All output lines regardless of date
	stringstream oo;
	int oday;
	for(i = 0; i < fline.size(); i++){
		oday = d.at(i);
	}
	
	string rf;
	cout << "\nEnter a report file: ;
	cin >> rf;
	cout << "Enter report start date (mm dd yyyy): ";
	cin >> d1; cin >> m1; cin >> y1;
	*/
	return 0;
}
/*
 * So I started writing a custom class for ticket because that is an objectively faster way to solve the problem
 * Then I got told I can't use stuff I didn't learn outside of lecture
 * Then I used that stuff anyway and now my grade sucks
 * So I'm not using this anymore, but I left it in as a comment because "It might be useful later" according to Katherine 
class Ticket{
	public:
	string citationNumber;
	int month;
	int day;
	int year;
	int speed;
	int limit;
	char road;
	
	Ticket(string c, int m, int d, int y, int s, int l, char r){
		citationNumber =c;
		month =m;
		day =d;
		year =y;
		speed =s;
		limit =l;
		road =r;
	}
}

*/
