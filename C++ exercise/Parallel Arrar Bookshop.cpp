//2D arrays

#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{


double products[3][3]= {{3000,3500,1850},
						{3500,3200,1950},
						{4000,3530,1880}};


cout << "BOOK     MAGAZINE   STATIONARY   TOTAL SALES" << endl;

for (int i=0;i<3;i++) 
		 {
		 	int total= 0;
			 	for (int j=0;j<3;j++)
				{
			 	cout<<products[i][j]<<setw(13);
			 	total= total + products[i][j];
			
				}
				cout << setw(13)<< total;
				cout << endl;
		}

return 0;
}
