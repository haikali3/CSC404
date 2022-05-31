#include <iostream>
using namespace std;

struct Student{
	string name;
	int id;
	int mark[2];
}

int main()
{
	Student stu;
	float aveMark;
	
getline(cin, Student.name);
	cin >> stu.id;
	cin >> stu.mark;

	stu.aveMark = (stu.mark[0] + stu.mark[1]) / 2;

	cout << “Average marks: ” << aveMark;
	return 0;
}
