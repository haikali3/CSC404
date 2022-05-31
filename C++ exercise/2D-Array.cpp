#include<iostream>
using namespace std;

int main()
{
   int row, col, num1[4][5], num2[4][5], sum[4][5];

   cout << "Please enter the values of Array 1 (4x5): "<<endl;
   for (int i = 0; i<4; i++ ) 
   {
     for (int j=0; j<5; j++ ) 
	 {
       cin>>num1[i][j];
     }
     cout<<endl;
   }
   cout << "Please enter the values of Array 2 (4x5): "<<endl;
   for (int i = 0; i<4; i++ ) 
   {
     for (int j = 0; j<5; j++ ) 
	 {
       cin>>num2[i][j];
     }
     cout<<endl;
   }

   cout<<"The sum is: "<<endl;
   for (int i = 0;i<4;i++ ) 
   {
      for (int j = 0;j<5;j++ ) 
	  {
        sum[i][j]=num1[i][j]+num2[i][j];
        cout<<sum[i][j]<<" ";
      }
      cout<<endl;
   }

   return 0;
}
