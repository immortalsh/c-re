#include<iostream>
using namespace std;
int main()
{
	int* p;
	p = new int[2];
	for (int i = 0; i <= 2; i++)
		p[i - 1] = 2;
	for (int i = 0; i < 2; i++)
	cout << p[i];
}
