//STRUCT and FILES
/*12. Suppose that you have the following definitions:
struct timeType struct tourType
{ {
int hr; string cityName;
double min; int distance;
int sec; timeType travelTime;
}; };
a. Declare the variable destination of type tourType.
b. Write C++ statements to store the following data in destination:
cityName—Chicago, distance—550 miles, travelTime—9 hours
and 30 minutes.
c. Write the definition of a function to output the data stored in a variable
of type tourType.
d. Write the definition of a value-returning function that inputs data into
a variable of type tourType.
e. Write the definition of void function with a reference parameter of
type tourType to input data in a variable of type tourType.
*/

#include <iostream>
using namespace std;
#include <string>
#include <fstream>


struct timeType
{ 
int hr; 
double min; 
int sec; 
};

 struct tourType 
 {string cityName;
 int distance;
 timeType travelTime;};
 
 ifstream infile;
 ofstream outfile;
 
 
void display(const tourType dest[],int);
void getdata(tourType dest[]);
void write(const tourType dest[],int);

tourType destination[5]; //a

int main()
{ 
 /*  b. Write C++ statements to store the following data in first destination:
cityName—Chicago, distance—550 miles, travelTime—9 hours
and 30 minutes. */
   destination[0].cityName="Chicago";
   destination[0].distance=550;
   destination[0].travelTime.hr=9;
   cout<<destination[0].cityName<<" "<<destination[0].distance<<" "
   <<destination[0].travelTime.hr;
      
  //call functions
   getdata(destination);
   display(destination,5);
//open a file in write mode.
  ofstream outfile;
  write(destination,5);
//close files
  infile.close();
  outfile.close();
  system("pause");
    return 0;
}

void display(const tourType dest[],int k)
{  
        for (int i=0; i<k; i++)
        {
            cout<<"destination : "<<dest[i].cityName;
            cout<<"  distance : "<<dest[i].distance;
            cout<<"  travel time : "<<dest[i].travelTime.hr<<"hours:"<< dest[i].travelTime.min<<"min:"
                     << dest[i].travelTime.sec<<"sec."<<endl<<endl;
        }
        return;
} 
        
void getdata(tourType dest[]) //enter tour info
{  
     infile.open("tour.txt");
     cout<< "\nReading from the file" << endl;
         int i=0;
         while(!infile.eof())
          { 
         infile>>dest[i].cityName;
         infile>>dest[i].distance;
         infile>>dest[i].travelTime.hr;
         infile>> dest[i].travelTime.min;
         infile>>dest[i].travelTime.sec; 
         i=i+1;
         } 
        return;
} 
 
void write(const tourType dest[],int k)
{   
         outfile.open("out.txt",ios::app);//open output file to write append mode
                                    //other mode trunc, ate, binary
         outfile<<"TRAVEL SUMMARY"<<endl<<endl;
        for (int i=0; i<k; i++)
        {
            outfile<<"destination : "<<dest[i].cityName;
            outfile<<"  distance : "<<dest[i].distance;
            outfile<<"  travel time : "<<dest[i].travelTime.hr<<"hours:"<< dest[i].travelTime.min<<"min:"
                        << dest[i].travelTime.sec<<"sec."<<endl<<endl;
        }
        return;
} 
