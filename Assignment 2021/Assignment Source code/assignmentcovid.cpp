#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("covid.txt");
	
	string line = "";
	string temp = "";
	
	int row = 2;
	int col = 14;
	int covid[row][col] = {0};

	
	if(inFile.is_open())
	{
		int k = 0;
		int j = 0;
		
		while(getline(inFile,line))
		{
			if(line !="")
			{
				j = 0;
				line = line + ',';
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] != ',')
					{
						temp += line [i];
					}
					else // at a comma, store value in temp
					{
						//cout << temp << endl;
						//covid [k][j] = stoi(temp); // stoi = change string to integer
						temp = "";
						j++;
					}
				}
			}
			k++;
		}
	}
	else
	{
		cout << " File not found. " << endl;
	}
	
	for (int i=0; i <row ; row++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << covid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
