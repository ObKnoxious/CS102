/*
 * Knox Crichton
 * Novmber 12
 * Lab 9
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
// https://www.tutorialspoint.com/Why-should-we-avoid-using-global-variables-in-C-Cplusplus
// This is unnecessary and goes against everything I've been taught 
const int GLOBAL_I_M = 5.2252;
const int GLOBAL_H_M = 9.4412;
const int GLOBAL_R_M = 17.1525;
const int GLOBAL_O_M = 12.152;
struct Date{
	int day;
	int month;
	int year;
}; 
struct Ticket{
	string cNum;
	Date d;
	int clocked;
	int limit;
	char road;
};
class Database{
	public:
		void add_ticket(const Ticket t){
			data.push_back(t);
		};
		vector<Ticket> gen_report(Date s, Date e);
	private:
		vector<Ticket> data;
};
bool Read(Database &d, istream &in){
	return false;
}	
bool Write(const vector<Ticket> &tickets, ostream &out){
	return false;
}
int Encode(const Date &d){
	string da = to_string(d.day);
	string mo = to_string(d.month);
	string yr = to_string(d.year);
	string fs = da + mo + yr;
	return stoi(fs);
}
int main(int argc, char *argv[]){
	if(argc != 5){
		cout << "Invalid arguments \n";
		return 0;
	} else {
		cout << "Valid arguments \n";
		// for debug
		for(int i =0; i	< argc; i++){
			cout << "  Argv at " << i << " " << argv[i];
		}
		cout << "\n";
		ifstream infile;
		infile.open(argv[1]);
		if(!infile.is_open()){
			cout << "File not found\n";
			return 1;
		}
		// Breaks file down word by word
		// This is a 2d vector, 1st dimmension is each line, nested (2nd) is word from each file
		vector<vector<string>> fd;
		string fline;
		while(getline(infile, fline)){
//			cout << fline << "\n";
			vector<string> tfline;
			istringstream ss(fline);
			do {
				string w;
				ss >> w;
				cout << w;
				tfline.push_back(w);
			} while(ss);
			fd.push_back(tfline);
		}
		cout << fd.size() << "\n";
		for(int i =0; i < fd.size(); i++){
			cout << "Line " << i+1 << "\n";
			for(int j =0; j < fd[i].size(); i++){
				cout << fd[i].size() << "\n";
				cout << "  " << fd[i][j];
			}
			cout << "\n";
		}
		return 0;
	}
}
	/*int m1, d1, y1, m2, y2, d2; // Months days and years for range
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
	*/
	// Fine Vector
	/*
	vector<double> f;
	double tf;
	double tv;
	// Checks for multiplier and creates new variable for that
	for(int i =0; i < fline.size(); i++){
		tv = cs.at(i) - sl.at(i);
		switch(rt.at(i)){
			case 'i':
				tf = tv * 5.2252;
				f.push_back(tf);
				break;
			case 'h':
				tf = tv * 9.4412;
				f.push_back(tf);
				break;
			case 'r':
				tf = tv * 17.1525;
				f.push_back(tf);
				break;
			default: 
				tf = tv * 12.152;
				f.push_back(tf);
		}
	}
	// Correcting for double didgit year input to 21st century
	for(int i =0; i < y.size(); i++){
		if(y.at(i) < 100){
			y.at(i) += 2000;
		}
	}
	// New time value for date checking
	vector<int> nt;
	int tnt;
	for(int i =0; i < y.size(); i++){
		tnt = y.at(i) *10000 + m.at(i) * 100 + d.at(i);
		nt.push_back(tnt);
	}
	ofstream ofile;
	string fto;
	cout << "Enter a report file: ";
	cin >> fto;
	cout << "Enter report start date (mm dd yyyy): ";
	cin >> m1 >> d1 >> y1;
	cout << "Enter report end date (mm dd yyyy): ";
	cin >> m2 >> d2 >> y2;
	int nt1 = y1 * 10000 + m1 * 100 + d1;
	int nt2 = y2 * 10000 + m2 * 100 + d2;
	// Actual outuput to file begins here
	ofile.open(fto);
	string marr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	cout << nt1 << "\t" << nt2 << "\n";
	for(int i = 0; i < fline.size(); i++){
		cout << nt.at(i) << "\n";
		if(nt.at(i) < nt2 && nt.at(i) > nt1){
			ofile << setfill('0') << setw(2)
			       	<< d.at(i) << "-" << marr[m.at(i)-1] << 
				"-" << y.at(i) << " " << 
				setfill(' ') << setw(10) << left << tnum.at(i) << "$" <<
				setfill(' ') << setw(9) << setprecision(2) << fixed << right << f.at(i) << "\n"; 
	
		}
	}
	ofile.close();	
	
}
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
