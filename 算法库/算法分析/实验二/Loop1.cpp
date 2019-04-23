#include <iostream>
using namespace std;

int a[100][100];
int rows, cols;

void Input();
int Max(int x, int y);
int f(int m, int n);

int main()
{
	int sum = 0;
	cin >> rows >> cols;
	Input();
	sum = f(0, 0);
	cout << sum << endl;
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

int Max(int x, int y)
{
	return x >= y ? x : y;
}

int f(int m, int n)
{
	if (m == rows - 1 && n == cols - 1) return a[m][n];
	else if (m == rows - 1) return a[m][n] + f(m, n + 1);
	else if (n == cols - 1) return a[m][n] + f(m + 1, n);
	else return a[m][n] + Max(f(m + 1, n), f(m, n + 1));
}
