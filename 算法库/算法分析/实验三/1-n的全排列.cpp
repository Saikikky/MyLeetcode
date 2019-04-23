#include <iostream> 
using namespace std;
#define N 100

int n, count = 1;
int a[N], used[N];

void f(int k);
void Output();
int xianjie(int i); // 判断a[k]是否能取

int main()
{
	cin >> n;
	f(1);
	cout << count;
	return 0;
}

void Output()
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int xianjie(int i)
{
	if (used[i]) return 0;
	else return 1;
}

void f(int k)
{
	int i;
	if (k - 1 == n)
	{
		Output();
		count++;
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (xianjie(i))
			{
				a[k] = i;
				used[i] = 1; // 数字i已经被使用，让i在递归f(k+1)里面不会再次被使用
				f(k + 1);
				used[i] = 0; // f(k+1)结束之后，清空标记
			}
		}
	}
}
