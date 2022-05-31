// Paralle Array

#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
double salary[4]= {3500,4000,6500,1200};
double max= salary[0];
double min= salary[0];
double staff_id[4] = {3122,3244,3133,3245};
string name[4]= {"Ahmad Tarmizi","Nurliza Saari","Nora Azman","Marissa Latif"};
int maxno,minno;

for (int i=1; i < 4;i++)
{
	if (salary[i] > max)
	{
		max = salary[i];
		maxno = i;
	}
}
	cout << endl << "Maximum Salary: " <<endl;
	cout <<staff_id[maxno] << setw(20) << name[maxno]<< setw(20) << max << endl;
	
for (int i=1; i < 4;i++)
{
	if (salary[i] < max)
	{
		min = salary[i];
		minno = i;
	}
}
	cout << endl << "Minimum Salary: "<< endl;
	cout <<staff_id[minno] << setw(20) << name[minno]<< setw(20) << min << setw(20) << endl;
return 0;
}
