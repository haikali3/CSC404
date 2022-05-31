#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	
	ifstream inFile;
	inFile.open("covid.txt");
	
	
	int row = 2;
	int col = 14;
	int covid[row][col] = {0};
