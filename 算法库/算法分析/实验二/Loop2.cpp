#include <iostream>
using namespace std;
#define N 100
int a[N][N];
int rows, cols;

void Input();
int f(int x, int y);
int Down(int x, int y);
int Up(int x, int y);
int Max(int x, int y);

int main() 
{
	int sum = 0;
	cout << "�������к���:";
	cin >> rows >> cols;
	Input();
	sum = f(0, 0);
	cout << sum;
	return 0;
}

void Input()
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			cin >> a[i][j];
		}
	} 
}

// ���� 
int Down(int m, int n)
{
	if (m == rows - 1 && n == cols - 1) return a[m][n]; // �ݹ���� 
	else if (m == rows - 1) return a[m][n] + f(m, n + 1);
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); // ֻ��������
	else return a[m][n] + Max(Down(m + 1, n), f(m, n + 1)); // �º���ȡ��� 
}

// ���� 
int Up(int m, int n)
{
	if (m == 0 && n == cols - 1) return a[m][n]; // ���Ͻ� �ݹ���� 
	else if (m == 0) return a[m][n] + f(m, n + 1); // ���� ������(3������)
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); // ���� ֻ�������� 
	else return a[m][n] + Max(Up(m - 1, n), f(m, n + 1)); // �Ϻ���ȡ��� 
}

int f(int m, int n)
{
	if (m == rows - 1 && n == cols - 1) return a[m][n]; // �ݹ���� 
	else if (m == rows - 1) return a[m][n] + Max(Up(m - 1, n), f(m, n + 1));  // ���� �Ϻ���ȡ��� 
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); //���� ֻ������ 
	else if (m == 0) return a[m][n] + Max(Down(m + 1, n), f(m, n + 1)); // ���� �Һ���ȡ��� 
	else
	{
		int max = Max(Down(m + 1, n), f(m, n + 1));
		return a[m][n] + Max(max, Up(m - 1, n));
	} 
}

int Max(int x, int y)
{
	return x > y ? x : y;
}
