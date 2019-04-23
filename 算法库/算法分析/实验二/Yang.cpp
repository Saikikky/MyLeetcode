#include <iostream>
using namespace std;
#define N 50

int a[N][N];
int b[N][N];
int f1(int n, int k);
int f2(int n, int k);
int f3(int n, int k);

int main()
{
	int n, k, i, j;
	cout << endl << "Input n, k (< 50): ";
	cin >> n >> k;
	if (n >= 50) return 1;
	cout << endl << "C(" << n << "," << k << ") = " << f3(n, k) << endl;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= i; j++)
		{
			cout << f1(i, j) << " ";
		}
		cout << endl;
	}
	return 0;
}

int f1(int n, int k)
{
	if (k < 0 || n < k) return 0;
	if (k == 0 || k == n) return a[n][k] = 1;
	if (a[n][k]) return a[n][k];
	else
	{
		return a[n][k] = f1(n - 1, k) + f1(n - 1, k - 1);
	}
	return a[n][k];
}

int f2(int n, int k)
{
	int i, j;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i ; j++)
		{
			if (j < 0 || i < j) return 0;
			if (j == 0 || i == j) return b[i][j] = 1;
			else
			{
				b[i][j] = b[i - 1][j] + b[i - 1][j - 1];
			}
		}
	}
	return b[n][k];
}

int f3(int n, int k)
{
	int i, j;
	int b1[N] = {0}, b2[N] = {0};
	int *p1 = b1, *p2 = b2, *p;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j < 0 || i < j) return 0;
			if (j == 0 || i == j) return p1[j] = 1;
			else
			{
				p2[j] = p1[j] + p1[j - 1];
			}
			p = p1;
			p1 = p2;
			p2 = p;
		}
	}
	return p2[k];
}
