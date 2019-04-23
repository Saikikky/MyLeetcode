#include <iostream>
using namespace std;

int f1(int n, int k);
int f2(int n, int k);
int f3(int n, int k);

int F[20][100] = {0};

int main()
{
	int k;
	for (k = 0; k <= 52; k++)
	{
		cout << f3(13, k) << endl;
	}
	return 0;
}

int f1(int n, int k)
{
	if (k < 0 || k > 4*n)
	{
		return 0;
	}
	if (F[n][k]) return F[n][k];
	if (k == 0 || k == 4*n)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i <= 4; i++)
		{
			F[n][k] += f1(n - 1, k - i);
		}
		return F[n][k];
	}
}

int f2(int n, int k)
{
	if (F[n][k] == 0)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= 4*i; j++)
			{
	//			if (j < 0 || j > 4*i)
	//			{
	//				F[i][j] = 0;
	//			}
				if (j == 0 || j == 4*i)
				{
					F[i][j] = 1;
				}
				else
				{
					for (int k = 0; k <= 4; k++)
					{
					//	F[i][j] += F[i - 1][j - k];
						if (j - k >= 0) F[i][j] += F[i - 1][j - k]; 
					} 
				}
			}
		}
	}
	
	return F[n][k];
}

int f3(int n, int k)
{
	int i, j;
	int b1[100] = {0}, b2[100] = {0};
	int *p1 = b1, *p2 = b2, *p;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= 4*i; j++)
		{
	//		if (j < 0 || j > 4*i)
	//		{
	//			p2[j] = 0;
	//		}
			if (j == 0 || j == 4*i)
			{
				p2[j] = 1;
			}
			else
			{
				p2[j] = 0;
				for (int k = 0; k <= 4; k++) 
				{
					if (j - k >= 0)
					{
						p2[j] += p1[j - k];
					}
				}
			}
		}
		p = p1;
		p1 = p2;
		p2 = p;
	}
	return p1[k];
}
