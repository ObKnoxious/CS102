//lab4
//Program takes input of miles and gallons for a fleet of cars and truck to find the total average 
//for the trucks and cars in the fleet
//Philip Alex Bingham
//9-12-19
//Professor - Dr. Dunn
//TA - Syd
//Students Worked with: N/A
#include<iostream>
#include<vector>
using namespace std;

//Calculates the average miles per gallon of the fleet for cars and trucks based on the user's input
int main(){
	string type = "a";
	double carM;
	double carG;
	double carA;
	double carTotal;
	double carCounter = 0;
	double carFinal;
	double truckM;
	double truckG;
	double truckA;
	double truckTotal;
	double truckCounter = 0;
	double truckFinal;
	vector<double> carAverage;
	vector<double> truckAverage;
	while(type != "done"){
		cout << "Enter a command: ";
		cin >> type;
		if(type == "car"){
			cout << "Enter car's miles: ";
			cin >> carM;
			cout << "Enter car's gallons: ";
			cin >> carG;
			carA = carM / carG;
			carAverage.push_back(carA);
			carCounter++;
		}else if(type == "truck"){
			cout << "Enter truck's miles: ";
			cin >> truckM;
			cout << "Enter truck's gallons: ";
			cin >> truckG;
			truckA = truckM / truckG;
			truckAverage.push_back(truckA);
			truckCounter++;
		}else if (type != "done"){
			cout << "Unknown command: " << endl;
		}
	}
	if(carCounter != 0){
		for(auto cA : carAverage){
			carTotal += cA;
		}
		carFinal = carTotal / carCounter;
		cout << "Average car MPG = " << carFinal << endl;
	}else{
		cout << "Fleet has no cars.";
	}
	if(truckCounter != 0){
		for(auto tA : truckAverage){
			truckTotal += tA;
		}
		truckFinal = truckTotal / truckCounter;
		cout <<"Average truck MPG = " << truckFinal << endl;
	}else{
		cout << "Fleet has no trucks.";
	}
	return 0;
}
