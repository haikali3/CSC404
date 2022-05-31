//book shop 2d array with data stored in file

#include<iostream>
#include<iomanip>
using namespace std;
#include <fstream>
#include <cstdlib>

const  int NUMBER_OF_ROWS=3;
const int NUMBER_OF_COLUMNS=3; 
void calcSum(float bs[][NUMBER_OF_COLUMNS],int row, float tot[]);
void dispArr(float bs[][NUMBER_OF_COLUMNS],int row, float tot[]);

int main ()
{ float total[3]={0.0};
 //float bookShop[3][3]={3000.00,3500.00,1850,3500,3200.00,1950.00,4000.00,3530.00,1880.00};
   float bookShop[3][3];
   
   ifstream infile;
    infile.open("book.txt");
    if (!infile.is_open())
        exit(EXIT_FAILURE);
    cout<< "\nReading from the file" << endl;
    int i=0;
    while (!infile.eof())
    {   for (int i=0; i<NUMBER_OF_ROWS;i++)
    		for (int j=0; j<NUMBER_OF_COLUMNS;j++)
           infile>>bookShop[i][j];//read from file           
   }
   
   for (int i=0; i<NUMBER_OF_ROWS;i++)
    {
	  calcSum(bookShop,NUMBER_OF_ROWS,total);
 
	}
	dispArr(bookShop,NUMBER_OF_ROWS,total);
	infile.close();
   return 0;
}

//Sum of each individual row stored in 1D array sum[]
void calcSum(float bs[][NUMBER_OF_COLUMNS],int row, float sum[])
{
 
for (int r=0; r < row; r++)
{
 sum[r] =  0;
for (int c=0; c<NUMBER_OF_COLUMNS; c++)
   sum[r] = sum[r] + bs[r][c];
 
}
return;
}

//Display contents of 2D array bookShop and 1D array total row 
void dispArr(float bs[][NUMBER_OF_COLUMNS],int row, float tot[])
{
	cout<<setw(15)<<left<<"BOOK"<<setw(15)<<left<<"MAGAZINE"<<setw(15)<<left<<"STATIONARY"<<setw(15)<<left<<"TOTAL SALES"<<endl<<endl;
	for (int i=0; i<row;i++)
	 {
	   for (int j=0; j<NUMBER_OF_COLUMNS;j++)
	     cout<<setw(15)<<left<<bs[i][j];
	    cout<<setw(15)<<left<<tot[i];
	    cout<<endl;
	}
}

