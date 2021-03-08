#include<iostream>
using namespace std;
int main()
{
	char* s;
	s = new char[20];
	for (int i = 0; i < 3; i++)
	{
		cin >> s;
		cout << s;
	}
}