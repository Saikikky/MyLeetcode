#include <iostream>
using namespace std;


int f1(int n);
int f2(int n);
int f3(int n);

int main()
{
	int i;
	for (i = 0; i < 50; i++)
	{
		cout << endl << "n = " << i << " " << f1(i) << " " << f2(i) << " " << f3(i);
	}
	return 0;
}

/*
int f1(int n)
{
	if (n == 1 || n == 2)
	{
		a[n] = 1;
	}
	else
	{
		if (a[n]) return a[n];
		else
		{
			return a[n] = f1(n - 1) + f1(n - 2);
		}
	}
}
*/

int f1(int n)
{
	int a[100] = {0};
	if (n < 1) return 0;
	if (a[n]) return a[n];
	if (n == 1 || n == 2) return a[n] = 1;
	else return a[n] = f1(n - 1) + f1(n - 2);
}

int f2(int n)
{
	int a[100] = {0};
	int i;
	for (i = 1; i <= n; i++)
	{
		if (i == 1 || i == 2) a[i] = 1;
		else a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}

int f3(int n)
{
	int a[100] = {0};
	int f1 = 1, f2 = 1, i, t;
	for (i = 3; i <= n; i++)
	{
		t = f1 + f2;
		f1 = f2;
		f2 = t;
	}
	return t;
}
