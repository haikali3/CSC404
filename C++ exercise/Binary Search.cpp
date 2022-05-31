#include<iostream>
#include<cstdlib>
using namespace std;
int binarySearch(const int list[], int listLength, int searchItem);

int main()
{
	
 
	
	int binarySearch(const int list[], int listLength, int searchItem)
	{
		int first = 0;
		int last = listLength - 1;
		int mid;
		
		bool found = false;
		
				while (first <= last && !found)
				{
				mid = (first + last) / 2;
					
						if (list[mid] == searchItem)
							found = true;
						else if (list[mid] > searchItem)
							last = mid - 1;
						else
							first = mid + 1;
				}
	if (found)
		return mid;
	else
		return -1;	
	}
}
