//2D arrays

#include<iostream>
using namespace std;

int main()

{

	int arr1[4][5]; //initialization for 1st matrix
	int arr2[4][5]; //initialization for 2nd matrix
 	int sum[4][5]; //initialization for sum of 1st and 2nd matrix
	 cout << "Enter value for 1st 4x5 matrix" << endl;
	 for (int i=0;i<4;i++)
	 {
	 	 for (int j=0;j<5;j++)
			{
		 	cin>>arr1[i][j];
			}	
			cout << endl;
	 }
	  		cout << "1st Matrix " << endl;
			 for (int i=0;i<4;i++) //loop for display arr1
			 {
			 	 	for (int j=0;j<5;j++)
					{
			 		cout<<arr1[i][j]<< " ";
					}
					cout << endl;
			 }
			 
	 cout << "Enter value for 2nd 4x5 matrix" << endl;
	for (int i=0;i<4;i++)
	 {
	 	 for (int j=0;j<5;j++)
			{
		 	cin>>arr2[i][j];
			}
			cout << endl;
	 }
	 	  	cout << "2nd Matrix " << endl;
			 for (int i=0;i<4;i++) // loop for display arr2
			 {
			 	 	for (int j=0;j<5;j++)
					{
			 		cout<<arr2[i][j]<< " ";
					}
					cout << endl;
			 }
			 

			 	  	cout << "Sum of 2 Matrices " << endl;
					 for (int i=0;i<4;i++) // loop for displaying sum of 2 matrix
					 {
					 	 	for (int j=0;j<5;j++)
							{
					 		sum[i][j]=arr1[i][j]+arr2[i][j];
					 		cout << sum[i][j]<< " ";
							}
						cout << endl;
					}
	 return 0;
}
