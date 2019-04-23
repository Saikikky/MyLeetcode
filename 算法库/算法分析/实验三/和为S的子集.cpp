// 对于一个含n个正整数元素的集合int a[]={a1,a2…,an}，
// 输出其中元素和为S的所有子集。

#include <iostream>
using namespace std;

int a[] = {9, 7, 5, 3, 2, 1};
int X[100];
int n = 6, S;

int Sum();
void f(int k);
int xianjie(int k); // 判断X[k]能否取a[k] 即a[k]能否划分到子集
void Output(); 

int main()
{
	cin >> S;
	f(1);
	return 0;
}

int Sum()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (X[i] == 1) sum += a[i];
	} 
	return sum;	
} 

int xianjie(int k, int t) // 判断X[k]能否取a[k] 即a[k]能否划分到子集
{
	int sum = 0, lsum = 0;
	for (int i = 1; i < k; i++)
	{
		if (X[i] == 1) sum += a[i]; 
	}
	if (t == 1 && sum + a[k] > S) return 0;
	for (int i = k + 1; i <= n; i++)
	{
		lsum += a[i];
	}
	if (t == 0 && sum + lsum < S) return 0;
	return 1;
}

void f(int k)
{
	if (k - 1 == n) // 到达叶子结点 
	{
		if (Sum() == S)
		{
			Output();
		}
	}
	else
	{
		for (int i = 0; i <= 1; i++)
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
	for (int i = 1; i <= n; i++)
	{
		if (X[i] == 1)
		{
			cout << a[i] << " ";
		}
	}
	cout << endl;
}
