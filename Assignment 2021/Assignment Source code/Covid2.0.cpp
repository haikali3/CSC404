#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
void dnReq(float totals[], int size); //point 7
		
	struct center {
		string director_name;
		string phoneNo;
	};
	
	struct district {
		string district_name;
		int cases[7][2];
		center head;
	};
	
		struct week {
		string week_num;
		district dist[9];
	};
	district distRecord[9];
	week weekRecord[2];
//	void activeRate(float recovery, float death, float total[]);
	
int main() 
{
	
	int n;
	string line;
	int sum;
	float rec = 0.5; 
	float die = 0.01; 
	float totals[9];
	string highdist;
	int maxIndex = 0;

	//read data from file and output to system
	ifstream myFile;
	myFile.open("covidcases.txt");
	cout<< "OPENING FILE" << endl;
	if (myFile.is_open()) 
	{
		for (int i=0; i<2; i++) 
		{
			getline(myFile, weekRecord[i].week_num,',');
			cout<<weekRecord[i].week_num;
	
			for (int p=0; p<9; p++) 
			{
				getline (myFile, weekRecord[i].dist[p].district_name,';');
				cout<<weekRecord[i].dist[p].district_name;
			
			
				for(int z=0; z<7; z++)
				{
					for(int s=0;s<2;s++)
					{                  
						if(z==6 && s==1)
						{
				 			getline(myFile,line, '\n');
							weekRecord[i].dist[p].cases[z][s] = stoi (line);						
						}
						else
						{
							getline(myFile,line,',');                
							weekRecord[i].dist[p].cases[z][s] = stoi(line) ;
							
						} 
						cout<<" "<<weekRecord[i].dist[p].cases[z][s];   
						sum+=weekRecord[i].dist[p].cases[z][s];
						
					}
				}
				cout<<endl;
				cout<<"sum of cases = "<<sum<<endl;                    
				sum=0;
			}
			
		}
		cout<<endl;	
	}
	else 
	{
 		cout << "FILE MISSING" << endl;
 		exit (0);
	 } //end of read data from file


	 	ifstream ourFile; //read file from headofcenter
	ourFile.open("headcenter.txt");
	cout<< "OPENING FILE" << endl;
	if (ourFile.is_open()) 
	{
			for (int p=0; p<9; p++) 
			{
				getline (ourFile,distRecord[p].district_name);
				cout << distRecord[p].district_name << endl;
			}
	}
	else
	{
 		cout << "FILE MISSING" << endl;
 		exit (0);
	 } //end of read data from file
	 	
	 	
	 //find highest cases.
	 for(int t=0; t<9; t++)
	 {
		for(int k=0; k<7; k++)
		{
			for(int f=0; f<2; f++)
			{
				totals[t] += (weekRecord[1].dist[t].cases[k][f]+weekRecord[0].dist[t].cases[k][f]);
			}
		}
		cout<<weekRecord[0].dist[t].district_name<<" "<<totals[t]<<endl;
		if ( totals[t]>maxIndex)
		{
			maxIndex = totals[t];
			highdist = weekRecord[0].dist[t].district_name;
		}	
		
	}
	cout<<endl;
	cout<<highdist<<" has the highest cases which is "<<maxIndex<<" cases for this month."<<endl;
	cout<<endl; //end of find highest cases
	
	 for(int t=0; t<9; t++)
	 {
		for(int k=0; k<7; k++)
		{
			for(int f=0; f<2; f++)
			{
				totals[t] = totals[t]-((totals[t]*rec)-(totals[t]*die));
				if(totals[t] >= 1000)
				{
					cout<<weekRecord[0].dist[t].district_name<<" WARNING!!!"<<endl;
				}
			}
		}
	}
dnReq(totals, 9); 

}
	void dnReq(float totals[], int size) //point 7
	{
		int docs;
		int nurs;
		cout << "*********";
		cout << "\n Number of doctors and nurses required for each district\n\n";
		cout << "   DISTRICT" << "\t\t\tNumber required" << endl;
	
	for(int t=0; t<9; t++)
	 {
		for(int k=0; k<7; k++)
		{
			for(int f=0; f<2; f++)
			{
				totals[t] += (weekRecord[1].dist[t].cases[k][f]+weekRecord[0].dist[t].cases[k][f]);
				docs = totals[t]/20;
				nurs = totals[t]/30;
			}
		}
			cout <<"\n"<< weekRecord[0].dist[t].district_name<<"\t\t"<< docs <<"doctors and"<< nurs <<"nurses";
	}
	
	cout<<"\n\n**********\n";
	}