#include<iostream>
using namespace std;
double E(int n,int m)
{
	double sum=0;
	if (m > n) return 0;
	if (n <= 0||m<=0) return  0;
	else {
		for (int i = 1; i <= n; i++)
		{
			sum += (E(n - i, m - i)+1) / double(n);
		}
	}
	return sum;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << E(n, m);
}