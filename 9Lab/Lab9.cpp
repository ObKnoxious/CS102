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
const double GLOBAL_I_M = 5.2252;
const double GLOBAL_H_M = 9.4412;
const double GLOBAL_R_M = 17.1525;
const double GLOBAL_O_M = 12.152;
const string mon[] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Now", "Dec"};
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
		void add_ticket(const Ticket t);
		vector<Ticket> gen_report(Date s, Date e);
	private:
		vector<Ticket> data;
};
// I was instructed to use istream not ifsteam
// I spent over an hour trying to get this with istream, it is impossible as far as I can tell
bool Read(Database &d, ifstream &in);
bool Write(const vector<Ticket> &tickets, ostream &out, string c);
int Encode(const Date &d);
int main(int argc, char *argv[]){
	if(argc != 5 ){
		cout << "Usage: ./lab9 <input file> <start: year-month-day> <end: year-month-day> <output or '-'>\n";
		return 0;
	} else {
//		cout << "Valid arguments \n";
		// for debug
//		for(int i =0; i	< argc; i++){
//cout << "  Argv at " << i << " " << argv[i];
//		}
//		cout << "\n";
	}
	ifstream infile;
	infile.open(argv[1]);
	// Don't worry, this is closed inside the Read function
	if(!infile.is_open()){
		cout << "The file '"<< argv[1] << "' cannot be read.";
		return 0;
	}
	Database d;
	cout << endl;
	Read(d, infile);
	ofstream outfile(argv[4]);
	vector<int> stav;
	istringstream sta(argv[2]);
	string token;
	while(getline(sta, token, '-')){
//		cout << "tokens: " << token << "\n";

		stav.push_back(stoi(token));
	}
	if(stav[0] < 100){// Double didgit year is less than 100
		stav[0]+=2000;
	}
	istringstream end(argv[3]);
	vector<int> endv;
	string tokene;
	while(getline(end, tokene, '-')){
//		cout << "tokens: " << tokene << "\n";
		endv.push_back(stoi(tokene));
	}
//	cout << "Endv 0: " << endv[0] << "\n";

	if(endv[0] < 100){// Double didgit year is less than 100
		endv[0]+=2000;
	}
//	cout << "Endv 0: " << endv[0] << "\n";
	Date startr { stav[2], stav[1], stav[0] };
	Date endr { endv[2], endv[1], endv[0] };
	string c = argv[4];
	Write(d.gen_report(startr, endr), outfile, c);
}
bool Read(Database &d, ifstream &in){
	// Breaks file down word by word
	// This is a 2d vector, 1st dimmension is each line, nested (2nd) is word from each file
	vector<vector<string>> fd;
	string fline;
	while(getline(in, fline)){
		vector<string> tfline;
		istringstream ss(fline);
		do {
			string w;
			ss >> w;
			tfline.push_back(w);
		} while(ss);
		fd.push_back(tfline);
	}
	cout << fline;
	// For Debug
	//	for(int i =0; i < fd.size(); i++){
	//	cout << "Line " << i+1 << "\n";
	//	for(int j =0; j < fd[i].size(); j++){
	//		cout << "  " << fd[i][j];
	//	}
	//	cout << "\n";
	//}
	
	// Converting year to 4 didgits
	// Year is always in 4th collum
	for(int i =0; i < fd.size();i++){
		int yn = stoi(fd[i][3]);
		//cout << " " << yn;
		if(yn < 100){// Double didgit year is less than 100
			yn+=2000;
		}
		fd[i][3] = to_string(yn);
		//cout << " new " << fd[i][3];
	}
	for(int i=0; i < fd.size();i++){
		Date d1 = {stoi(fd[i][2]), stoi(fd[i][1]), stoi(fd[i][3]) };
		Ticket t { fd[i][0], d1, stoi(fd[i][4]), stoi(fd[i][5]), fd[i][6][0] };
		d.add_ticket(t);
	}
	in.close();	
	return true;
}	
bool Write(const vector<Ticket> &tickets, ostream &out, string c){

	for(int i =0;i<tickets.size();i++){
		float fine;
		int diff = tickets[i].clocked - tickets[i].limit;
		if(diff <0){diff=0;}
		switch(tickets[i].road){
			case 'i':
				fine = diff * GLOBAL_I_M;
				break;
			case 'h':
				fine = diff * GLOBAL_H_M;
				break;
			case 'r':
				fine = diff * GLOBAL_R_M;
				break;
			default: 
				fine = diff * GLOBAL_O_M;
		}
		if(c == "-"){
			cout << setfill('0') << setw(2)
			<< tickets[i].d.day << "-" << mon[tickets[i].d.month-1] << 
			"-" << tickets[i].d.year << " " << 
			setfill(' ') << setw(10) << left << tickets[i].cNum << "$" <<
			setfill(' ') << setw(9) << setprecision(2) << fixed << right << fine << "\n"; 
		} else {
			out << setfill('0') << setw(2)
			<< tickets[i].d.day << "-" << mon[tickets[i].d.month-1] << 
			"-" << tickets[i].d.year << " " << 
			setfill(' ') << setw(10) << left << tickets[i].cNum << "$" <<
			setfill(' ') << setw(9) << setprecision(2) << fixed << right << fine << "\n"; 
		}
	}
	return true;
}
int Encode(const Date &d){
	int tnt = d.year *10000 + d.month *100 + d.day;
	return tnt;
}
void Database::add_ticket(const Ticket t){
	data.push_back(t);
}
vector<Ticket> Database::gen_report(Date s, Date e){
	int st = Encode(s);
	int en = Encode(e);
//	cout << "st " << st << " en: " << en <<"\n";
	vector<Ticket> r;
	for(int i =0; i < this->data.size();i++){
//		cout << Encode(data[i].d) << "\t";
		if(Encode(data[i].d) >= st && Encode(data[i].d) <= en){
			r.push_back(data[i]);
		}
	}
	for(int i=0; i < r.size();i++){
		//cout << r[i].cNum << "\n";
	}
	return r;
};
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
