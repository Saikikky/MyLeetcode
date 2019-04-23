#include <iostream>
using namespace std;

int a[100] = {0};
int b[100] = {0};
int c[5] = {0};

int f1(int n);
int g1(int n);
int f3(int n);
int g3(int n);

int main()
{
	int n, i;
	cout << "input n = ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << endl << "n = " << "新兔子数：" << g1(i) << " ";// << g3(i) << " ";
		cout << "兔子总数: " << f1(i) << " " << f3(i);
	}
	return 0;
}

int f1(int n)
{
	return g1(n) + g1(n - 1) + g1(n - 2) + g1(n - 3) + g1(n - 4);
}

int g1(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (i < 1) a[i] = 0;
		else if (i == 1) a[i] = 1;
		else
		{
			a[i] = g1(i - 2) + g1(i - 3) + g1(i - 4) + g1(i - 5);
		}
	}
	return a[n];
}

int f3(int n)
{
	return a[0] + a[1] + a[2] + a[3] + a[4];
}

int g3(int n)
{
	int t, i;
	if (n < 1) t = 0;
	else if (n == 1) t = a[1] = 1;
	else
	{
		a[0] = 0;
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		a[4] = 1;
		for (i = 2; i <= n; i++)
		{
			t = a[0] + a[1] + a[2] + a[3];
			a[0] = a[1];
			a[1] = a[2];
			a[2] = a[3];
			a[3] = a[4];
			a[4] = t;
		}
	}
	return t;
}
