/////////////////////////////////////////////////////
//输出由数字0,1,3,4,6,7,9构成的所有能够被9整除、
//数字允许重复、十位数字不小于个位数字
//m（1<m<100，由键盘输入）位奇数，
//而且9出现次数不少于[m/2]。
/////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int a[10] = {0, 1, 3, 4, 6, 7, 9};
int X[100], count = 0, m; // X[100]用于存放

void f(int k);
int xianjie(int k, int i);
void Output();

int main()
{
	cin >> m;
	f(1);
	return 0;
}

int xianjie(int k, int i) // X[k]是否可以取a[i]
{
	int sum = 0, count9 = 0;
	if (k == 1 && a[i] == 0) return 0;  // 首位不能是0
	if (k == m) // X[k]为最后一位数
	{
		if (!(a[i] % 2)) return 0; // 该数必为奇数
		if (X[k - 1] < a[i]) return 0; // 十位不小于个位
		for (int j = 1; j < k; j++)
		{
			sum += X[j];
			sum *= 10;
		}
		if ((sum + a[i]) % 9) return 0;   // 要被9整除
	}
	if (a[i] != 9)
	{
		count9 = 0;
		for (int j = 1; j < k; j++)
		{
			if (X[j] == 9) count9++;
		}
		if (count9 + m - k < m / 2) return 0;
	}
	return 1;
}

void f(int k)
{
	if (k - 1 == m)
	{
		Output();
	}
	else
	{
		for (int i = 1; i <= 6; i++)
		{
			if (xianjie(k, i))
			{
				X[k] = a[i];
				f(k + 1);
			}
		}
	}
}

void Output()
{
	for (int i = 1; i <= m; i++)
	{
		cout << X[i];
	}
	cout << endl;
}
