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
		void remove_channel(const string& color); 
		void flip_x();
		void flip_y();
		bool read_input(istream& in);
		void write_ouput(ostream& out);
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
	}
}
Picture::Picture(){
	this->width =0;
	this->height =0;
	this->inten =0;
}
bool Picture::read_input(istream &in){
//	string thing = in;
}

