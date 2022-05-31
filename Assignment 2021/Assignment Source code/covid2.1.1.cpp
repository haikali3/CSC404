#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include<windows.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

void readData();
void readOtherData();
void highestCases(float totals[]);
void warningSign(float totals[]);
void totalCases(float totals[9]);
void dnReq(float totals[], int size); //the number of doctors and nurses required for each district
void exportReport();
void showMenu();
		
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
	int choice;
	int menuChoice;
	bool covidMenu = true;
	bool mainMenu=true;

	while(choice!=8)
	{
		showMenu();
		cout << "\nENTER CHOICE : ";
		cin >> choice;
		if (choice == 1)
		{
			cout <<"Reading from the file..." << endl;
			readData(); 
		}
		else if(choice==2)
		{
			readOtherData();
		}
		else if(choice==3)
		{
			totalCases(totals);
		}
		else if(choice==4)
		{
			highestCases(totals); 
			
		}
		else if(choice==5)
		{
			warningSign(totals);
		}
		else if (choice==6)
		{
			dnReq(totals, 9);
		}
		else if (choice==7)
		{
			cout<<"Exporting..."<<endl;
			Sleep(2000);
			cout<<"Done /"<<endl;
			Sleep(500);
			exportReport();
		}
		else if( choice==8)
		{
			cout<<"Thankyou!! Byebye."<<endl;
			Sleep(500);
		}
		else 
		{
			cout<<"Invalid Number"<<endl;
			return 0;
		}
	}
}

void showMenu()
 // Menu for user's selection
   {
     cout<<"_______________________________________________________________________"<<endl;
     cout << "PROGRAM MENU" << endl;
     cout <<endl;
     cout << 1 << ".COVID-19 CASES"<<endl;
     cout << 2 << ".HOSPITAL INFORMATION" << endl;
     cout << 3 << ".TOTAL NEW CASES FOR EVERY DISTRICT"<< endl;
     cout << 4 << ".HIGHEST CASES"<< endl;
     cout << 5 << ".ACTIVE RATE BY DISTRICT"<< endl;
     cout << 6 << ".NUMBER OF DOCTOR AND NURSE REQUIRED FOR EACH DISTRICT"<< endl;
     cout << 7 << ".EXPORT REPORT"<<endl;
     cout << 8 << ".EXIT PROGRAM"<<endl;
     cout<<"_______________________________________________________________________"<<endl;
   }

void readData()
{
	string line;
	int sum;
	
	//read data from file and output to system
	ifstream infile;
	ofstream outfile;
	infile.open("covidcases.txt");
	cout<< "OPENING FILE" << endl;
	if (infile.is_open()) 
	{
		for (int i=0; i<2; i++) 
		{
			cout<<"--------------------------------------------------"<<endl;
			getline(infile, weekRecord[i].week_num,',');
			cout<<weekRecord[i].week_num;
	
			for (int p=0; p<9; p++) 
			{
				getline (infile, weekRecord[i].dist[p].district_name,';');
				cout<<weekRecord[i].dist[p].district_name;
			
			
				for(int z=0; z<7; z++)
				{
					for(int s=0;s<2;s++)
					{                  
						if(z==6 && s==1)
						{
				 			getline(infile,line, '\n');
							weekRecord[i].dist[p].cases[z][s] = stoi (line);						
						}
						else
						{
							getline(infile,line,',');                
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
		infile.close();
	}
	else 
	{
 		cout << "FILE MISSING" << endl;
 		exit (0);
	} //end of read data from file
	
}

void readOtherData()
{	
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
	 cout<<endl;
	 ourFile.close();
}
void totalCases(float totals[9])
{	
	//find total new cases 
	cout.setf(ios::fixed);
	cout.precision(0);
	cout<<setw(10)<<"District"<<setw(32)<<"Total new cases"<<endl;
	 	
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
		cout<<left;
		cout<<setw(32)<<weekRecord[0].dist[t].district_name<<totals[t]<<endl; //end of find total new cases
	}
}
void highestCases(float totals[9])
{
	 //find highest cases.
	string highdist;
	int maxIndex = 0;
	 for(int t=0; t<9; t++)
	 {
//		for(int k=0; k<7; k++)
//		{
//			for(int f=0; f<2; f++)
//			{
//				totals[t] += (weekRecord[1].dist[t].cases[k][f]+weekRecord[0].dist[t].cases[k][f]);
//			}
//		}

		if ( totals[t]>maxIndex)
		{
			maxIndex = totals[t];
			highdist = weekRecord[0].dist[t].district_name;
		}	
		
	}
	cout<<endl;
	cout<<highdist<<" has the highest cases which is "<<maxIndex<<" cases for this month."<<endl;
	cout<<endl; //end of find highest cases
}


void warningSign(float totals[9])
{
	 float rec = 0.5;
	 float die = 0.01;
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
	cout<<endl;
}



void dnReq(float totals[], int size) //the number of doctors and nurses required for each district
{
		int docs;
		int nurs;
		cout <<"\n Number of doctors and nurses required for each district\n\n";
		cout << "District" << "\t\tNumber required" << endl;
		cout <<"\t\t\t Doctors"<<"\t Nurses"<<endl;
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
			cout<<left;
			cout <<setw(28)<< weekRecord[0].dist[t].district_name<<setw(15)<< docs << setw(15)<<nurs <<endl;
	}	
}

void exportReport() // Write all information to the file
{
	ofstream infile;
	infile.open("covid19_June.txt");
	
	int n;
	string line;
	int sum;
	float rec = 0.5; 
	float die = 0.01; 
	float totals[9];
	string highdist;
	int maxIndex = 0;
	int docs;
	int nurs;
	
	for (int i=0; i<2; i++) 
		{
			infile<<weekRecord[i].week_num;
			infile<<left;
			for (int p=0; p<9; p++) 
			{
				infile<<setw(20)<<weekRecord[i].dist[p].district_name<<setw(10)<<"-->";
			
				for(int z=0; z<7; z++)
				{
					for(int s=0;s<2;s++)
					{                  

						infile<<weekRecord[i].dist[p].cases[z][s]<<" | ";  
						
					}
				}
				infile<<endl;
				
			}
		infile<<"---------------------------------------------"<<endl;	
		}
		for(int t=0; t<9; t++)
	 {
		for(int k=0; k<7; k++)
		{
			for(int f=0; f<2; f++)
			{
				totals[t] += (weekRecord[1].dist[t].cases[k][f]+weekRecord[0].dist[t].cases[k][f]);
			}
		}
		infile<<setw(20)<<weekRecord[0].dist[t].district_name<<totals[t]<<endl;
		
		if ( totals[t]>maxIndex)			//find highest cases.
		{
			maxIndex = totals[t];
			highdist = weekRecord[0].dist[t].district_name;
		}	
		
	}
	infile<<endl;					//display the highest cases
	infile<<"-------------------------------------------------------------------------"<<endl;
	infile<<"DISTRICT WITH HIGHEST CASES IN SELANGOR : "<<endl;	
	infile<<endl;
	infile<<highdist<<" --> "<<maxIndex<<" cases"<<endl;
	infile<<endl; 
	infile<<"-------------------------------------------------------------------------"<<endl;
	infile<<endl;
	
	//find active rate for every district
	infile<<endl;
	infile<<"------------------------------------------"<<endl;
	infile<<"DISTRICT WITH ACTIVE RATE 1000 AND ABOVE :"<<endl;
	infile<<endl;
	 for(int t=0; t<9; t++)
	 {	
		infile<<left;	
		totals[t] = totals[t]-((totals[t]*rec)-(totals[t]*die));
		if(totals[t] >= 1000)		//display active rate that more than 1000
		{
			infile<<setw(20)<<weekRecord[0].dist[t].district_name;
			infile<<" WARNING!!!"<<endl;
		}	
	}
	infile<<"------------------------------------------"<<endl;
	infile<<endl;
		
		infile << "***********************************************************";
		infile << "\n Number of doctors and nurses required for each district\n\n";
		infile << "   DISTRICT" << "\t\t\tNumber required" << endl;
		infile <<"\t\t\t Doctors"<<"\t Nurses"<<endl;	
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
			infile<<left;
			infile <<setw(28)<< weekRecord[0].dist[t].district_name<<setw(15)<< docs << setw(15)<<nurs <<endl;
	}
	
	infile<<"\n\n***********************************************************\n";
	}
	

 