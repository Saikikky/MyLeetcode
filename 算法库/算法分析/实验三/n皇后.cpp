#include <iostream>
using namespace std;
#include <cmath>

#define N 100
int X[N] = {0}, n;

int xianjie(int k, int i);
void f(int k);
void Output();

int main()
{
	cin >> n;
	f(1);
	return 0;
}

int xianjie(int k, int i)
{
	int j;
	for (j = 1; j < k; j++)
	{
		if (X[j] == i || abs(j - k) == abs(X[j] - i)) // i列已有皇后或对角线
		return 0;
	}
	return 1;
}

void f(int k)
{
	if (k - 1 == n)
	{
		Output();
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (xianjie(k, i))
			{
				X[k] = i;
				f(k + 1);
			}
		}
	}
}

void Output()
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == X[i]) cout << X[i] << " ";
			else cout << k << " ";
		}
		cout << endl;
	}
	cout << endl;

}
