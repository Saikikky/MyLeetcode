#include <iostream> 
using namespace std;
#define N 100

int n, count = 1;
int a[N], used[N];

void f(int k);
void Output();
int xianjie(int i); // �ж�a[k]�Ƿ���ȡ

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
				used[i] = 1; // ����i�Ѿ���ʹ�ã���i�ڵݹ�f(k+1)���治���ٴα�ʹ��
				f(k + 1);
				used[i] = 0; // f(k+1)����֮����ձ��
			}
		}
	}
}
