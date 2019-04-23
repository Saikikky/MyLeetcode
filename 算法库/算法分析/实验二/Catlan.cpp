#include <iostream>
using namespace std;

int f1(int n);

int main()
{
	int n;
	cin >> n;
	cout << f1(n) << endl;
	return 0;
}

int f1(int n)
{
	int a[100] = {1, 1};
	int i, j;
	if (i > n) return a[n];
	for (i = 2; i <= n; i++)
	{	
		int s = 0;
		for (j = 0; j < i; j++)
		{
			s += a[i] * a[i - 1 - i];
		}
		a[i] = s;
	}
	return a[n];
}
