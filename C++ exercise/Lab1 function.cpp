#include <iostream> 
using namespace std;

void display (int i,char a)
{
	i++;
	a--;
	cout <<" GOODMORENING!";
	cout << "There are" << i << "apples in " << a <<" baskets";
	cout <<endl;
}
 int main()
 {
 int x=5, y=5;
 display (x,y);
 x++;
 display (x,y);

 }
 

