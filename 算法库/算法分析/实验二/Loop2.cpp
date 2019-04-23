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
	cout << "请输入行和列:";
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

// 向下 
int Down(int m, int n)
{
	if (m == rows - 1 && n == cols - 1) return a[m][n]; // 递归结束 
	else if (m == rows - 1) return a[m][n] + f(m, n + 1);
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); // 只能向下走
	else return a[m][n] + Max(Down(m + 1, n), f(m, n + 1)); // 下和右取最大 
}

// 向上 
int Up(int m, int n)
{
	if (m == 0 && n == cols - 1) return a[m][n]; // 右上角 递归结束 
	else if (m == 0) return a[m][n] + f(m, n + 1); // 最上 往右走(3个方向)
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); // 最右 只能向下走 
	else return a[m][n] + Max(Up(m - 1, n), f(m, n + 1)); // 上和右取最大 
}

int f(int m, int n)
{
	if (m == rows - 1 && n == cols - 1) return a[m][n]; // 递归结束 
	else if (m == rows - 1) return a[m][n] + Max(Up(m - 1, n), f(m, n + 1));  // 最下 上和右取最大 
	else if (n == cols - 1) return a[m][n] + Down(m + 1, n); //最右 只能向下 
	else if (m == 0) return a[m][n] + Max(Down(m + 1, n), f(m, n + 1)); // 最上 右和下取最大 
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
