/*
 * Knox Crichton
 * November 20
 * Lab 10
 * COSC 102 Josh Dunn
 * TA: Katherine Huckaby
 * Description: 
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <sstream>
#include <algorithm>
#include <fstream>
using namespace std;

struct Pixel{
	int red;
	int blue;
	int green;
};

class Picture{
	public:
		Picture();
		const Pixel& get_pixel(int row, int column);
		// In order to overload the get_pixel funtion parameters must be different
		Pixel& get_pixel(int row, int column, int o);
		void set_pixel(int row, int column, Pixel px);
		void remove_channel(const string& color); 
		void flip_x();
		void flip_y();
		bool read_input(istream& in);
		void write_output(ostream& out);
	private:
		vector<Pixel> image;
		int width;
		int height;
		int inten;
};

int main(int argc, char* argv[]){
	// Managing argv
	if(argc != 4){
		cout << "Error: Invalid input.\nUsage: lab10 input.ppm ouput.ppm funtion\n";
		return 0;
	}
	string input = argv[1];
	string ppmInData;
	Picture p =  Picture();
	if(input == "-"){
		cout << "Input PPM data: \n";
		p.read_input(cin);
	} else {
		ifstream ppmIn;
		ppmIn.open(input);
		if(!ppmIn.is_open()){
			cout << "Error failed to open file\n";
			return 0;
		}
		p.read_input(ppmIn);
	}
	if(argv[3] == "flip_x"){
		p.flip_x();
	}else if(argv[3] == "flip_y"){
		//p.flip_y();
	}else if(argv[3] == "remove_red"){
		//p.remove_channel("red");
	}else if(argv[3] == "remove_blue"){
		//p.remove_channel("blue");
	}else if(argv[3] == "remove_green"){
		//p.remove_channel("geen");
	
	}else if(argv[3] == "remove_gray"){
		//p.remove_channel("gray");
	}

	if(argv[2] == "-"){
		p.write_output(cout);
		return 0;
	}
	ofstream ox;
	ox.open(argv[2]);
	p.write_output(ox);
}
Picture::Picture(){
	this->width =0;
	this->height =0;
	this->inten =0;
}
bool Picture::read_input(istream &in){
	vector<string> rowString;
	string line;
	while(getline(in, line)){
		rowString.push_back(line);
	}
	vector<vector<string>> rowValString;
	rowValString.resize(rowString.size());
	for(int i =0;i < rowString.size();i++){
		istringstream sv(rowString[i]);
		do {
			string val;
			sv >> val;
			rowValString[i].push_back(val);
		} while (sv);
	}
	//for(int i =0;i < rowValString.size(); i++){
	//	cout << "Row " << i < "\n";
	//	for(int j=0; j < rowValString[i].size(); j++){
	//		cout << rowValString[i][j] << " ";
	//	}
	//	cout << "\n";		
	//}
	// Removing lines that are comments
	for(int i =0;i < rowValString.size()-1; i++){
	//	cout << i << "\n";
		if(rowValString[i][0].at(0) == '#'){
			//cout << "Trying to remove comments at line " << rowValString.begin() + i<< "\n";
			rowValString.erase(rowValString.begin() + i);
		}
	}
	//for(int i =0;i < rowValString.size(); i++){
	//	cout << "Row " << i < "\n";
	//	for(int j=0; j < rowValString[i].size(); j++){
	//		
	//		cout << rowValString[i][j] << " ";
	//	}
	//	cout << "\n";		
	//}
	
	// Now that comments are removed from the file, the height and width will always be on line 2
	this->width=stoi(rowValString[1][0]);
	this->height=stoi(rowValString[1][1]);
	this->inten=stoi(rowValString[2][0]);
	this->image.resize(this->width * this->height);
	//Actually declaring vector of pixels here
	for(int i=0; i < rowValString.size(); i++){
	       for(int j =0; j< rowValString[i].size(); j=j+3){
			Pixel f {j, j+1, j+2};
			this->image[i]=f;
	       }
	}	       

}

const Pixel& Picture::get_pixel(int row, int column){
	int x = row * this->width;
	x+=column;
	return this->image[x];
}
void Picture::set_pixel(int row, int column, Pixel px){
	int x = row * this->width;
	x+=column;
	image[x] = px;
}
void Picture::flip_x(){
	// Returning to 2d vector
	vector<vector<Pixel>> fx;
	fx.resize(this->height);
	for(int i =0; i < this->height; i++){
		for(int j =0; j < this->width; j++){
			fx[i].push_back( this->image[i*this->width + j]);
		}
	}
	reverse(fx.begin(), fx.end());
	this->image.resize(0);
	for(int i=0; i < fx.size(); i++){
		for(int j=0; j<fx[i].size(); j++){
			this->image.push_back(fx[i][j]);
		}
	}
}

void Picture::write_output(ostream& out){
	// Returning to 2d vector
	vector<vector<Pixel>> fx;
	fx.resize(this->height);
	for(int i =0; i < this->height; i++){
		for(int j =0; j < this->width; j++){
			fx[i].push_back( this->image[i*this->width + j]);
		}
	}
	vector<vector<int>> fxx;
	fxx.resize(this->height);
	for(int i =0; i < this->height; i++){
		for(int j =0; j < this->width; j++){
			fxx[i].push_back(fx[i][j].red);
		}
		for(int j =0; j < this->width; j++){
			fxx[i].push_back(fx[i][j].green);
		}
		for(int j =0; j < this->width; j++){
			fxx[i].push_back(fx[i][j].blue);
		}
	}
	string xf;
	for(int i =0; i < this->height; i++){
		for(int j =0; j < this->width; j++){
			xf+=fxx[i][j];
		}
		xf+="\n";
	}
		
	out << "P3\n" << "#width height\n" << this->width << " " << this->height << "\n" << xf;
}
