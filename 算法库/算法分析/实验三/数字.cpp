/////////////////////////////////////////////////////
//���������0,1,3,4,6,7,9���ɵ������ܹ���9������
//���������ظ���ʮλ���ֲ�С�ڸ�λ����
//m��1<m<100���ɼ������룩λ������
//����9���ִ���������[m/2]��
/////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int a[10] = {0, 1, 3, 4, 6, 7, 9};
int X[100], count = 0, m; // X[100]���ڴ��

void f(int k);
int xianjie(int k, int i);
void Output();

int main()
{
	cin >> m;
	f(1);
	return 0;
}

int xianjie(int k, int i) // X[k]�Ƿ����ȡa[i]
{
	int sum = 0, count9 = 0;
	if (k == 1 && a[i] == 0) return 0;  // ��λ������0
	if (k == m) // X[k]Ϊ���һλ��
	{
		if (!(a[i] % 2)) return 0; // ������Ϊ����
		if (X[k - 1] < a[i]) return 0; // ʮλ��С�ڸ�λ
		for (int j = 1; j < k; j++)
		{
			sum += X[j];
			sum *= 10;
		}
		if ((sum + a[i]) % 9) return 0;   // Ҫ��9����
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
