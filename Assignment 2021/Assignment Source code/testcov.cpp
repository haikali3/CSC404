#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

	struct headofcenter {
		string hospital_name;
		string director_name;
		string director_email;
		string director_phone_num;
	};
	
	struct district {
		string district_name;
		int cases[7][2];
		headofcenter head;
	};
		
	struct week {
		string week_num;
		district dist[9];
	};
	

int main() {
	
	int i;
	district disctrictRecord[9];
	week weekRecord[2];
	headofcenter headofRecord[100];
	string day[7] = {"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
	string district[10] = {"GOMBAK","KLANG","SABAK BERNAM","SEPANG","HULU LANGAT","KUALA LANGAT","PETALING","HULU SELANGOR","HULU SELANGOR","KUALA SELANGOR"};
	string gender[2] = {"M","F"};
	string fileName;
	string outfileName;
	string line;
	
	
	ofstream myFile;
	myFile.open(covidcases.txt)
	cout<< "OPENING FILE" << endl;
	
	 
	 return 0;
	 
}