#include <iostream>
#include<string>
#include<iomanip>
#include <string>

using namespace std;


	struct Pneumonia {
		string patient_name ;
		char patient_gender;
		int patient_age;
		int days;
	};

	void userdata (Pneumonia patientInfo[], int size)
	{
		
		for(int i = 0; i < size; i++) {

			 cout << "Enter your data" << endl;
			 cout << "Name: " << endl;
			 cin >> patientInfo[i].patient_name;
			 
			 cout << "Gender [m/f]: " << endl;
			 cin >> patientInfo[i].patient_gender;
			 		
			 cout << "Age: " << endl;
			 cin >> patientInfo[i].patient_age;
			 
			 cout << "Days in ward: " << endl;
			 cin >> patientInfo[i].days;
		}
	}
	
	
	void find(Pneumonia patientInfo[],int size)
	{
		int male = 0, female= 0;
		for (int i=0; i<size; i++)
		{
			if(patientInfo[i].patient_gender == 'm' || patientInfo[i].patient_gender == 'M')
				male++;
			else if(patientInfo[i].patient_gender == 'f' || patientInfo[i].patient_gender == 'F')
				female++;
			else
				continue;
		}
		
		cout << " Total number of male: " <<male;
		cout << " Total number of female: "<<female;
		
	}
		
	void fivedays (Pneumonia patientInfo[],int size) {
	
	cout<<"Name that exceed 5 days in ward: "<<endl;
	for (int i=0; i<size; i++)
	{
		if(patientInfo[i].days > 5)
			cout<<patientInfo[i].patient_name<<endl;
		else 
			continue;
	}
}

	
	int main()
{
	int loop;
	Pneumonia patientInfo[100];
	
	cout<<"How many patient: "<<endl;
	cin>>loop;
	
	userdata(patientInfo,loop);
	find(patientInfo,loop);
	fivedays(patientInfo,loop);
	
	return 0;
}
