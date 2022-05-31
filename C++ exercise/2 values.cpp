/*Group Member: 
Amirul Asyraf
Haikal Tahar */


#include<iostream>
#include<string>
using namespace std;

void calcSum(int x, int y);
void calcProduct(int x, int y);
void calcAverage(float x, float y, float& z);
void switcher(int& x, int& y,int temp);

int  main()
{
	string need;
	float num3;
	int num1, num2;
	cout<<"INSERT TWO VALUES :"<<endl;
	cin>>num1;
	cin>>num2;
	cout<<"WHAT YOU WANT?"<<endl;
	cout<<"sum | product | average | switch"<<endl;
	cin>>need;
	if(need=="sum")
	calcSum(num1,num2);
	else if(need=="product")
	calcProduct(num1, num2);
	else if(need=="average")
	{
		calcAverage(num1, num2, num3);
		cout<<num3;
	}	
	else if(need=="switch")
	{
		cout<<"the bigger integer is ";
		switcher(num1, num2, num3);
		cout<<"\nNum 1 has become "<<num1<<" and num 2 is "<<num2;
	}
	else
	cout<<"error...";
}
void calcSum(int x, int y)
{
	cout<<x+y<<endl;
}
void calcProduct(int x, int y)
{
	cout<<x*y<<endl;
}
void calcAverage(float x, float y, float& z)
{
	z=(x+y)/2;
}
void switcher(int& x, int& y,int temp)
{	
	if(x>y)
	cout<<x;
	else
	cout<<y;
	temp=x;
	x = y;
	y= temp;
}
