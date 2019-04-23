#include <stdio.h>
#include <stdlib.h>
#include "MyMath.h"

int GT(double x, double y)
{
	return x > y + epsilon;
}

int LT(double x, double y)
{
	return x < y - epsilon;
}

int GE(double x, double y)
{
	return !LT(x, y);
}

int LE(double x, double y)
{
	return !GT(x, y);
}

int EQ(double x, double y)
{
	return !NE(x, y);
}

int NE(double x, double y)
{
	return GT(x, y) || LT(x, y);
}

int IsOdd(int n)
{
	int ok;
	if (n % 2 != 0)
	{
		ok = 1;
	}
	else
	{
		ok = 0;
	}
	return ok;
}

int IsEven(int n)
{
	return n % 2 == 0;
}

/*
// 此方法效率不高
double Power(double x, int n)
{
	double y;
	if (n == 0)
	{
		y = 1.0;
	}
	else // n > 0
	{
		y = Power(x, n - 1) * x;
	}
	return y;
}
*/

/*
// 此方法效率较低
double Power(double x, int n)
{
	double y, t;
	if (n == 0)
	{
		y = 1.0;
	}
	else
	{
		y = Power(x, n / 2);
		y *= y;
		if (IsOdd(n))
		{
			y *= x;
		}
	}
	return y;
}
*/


double Power(double x, int n)
{
	double y, t;
	if (EQ(x, 0.0)) // x == 0
	{
		if (n <= 0)
		{
			puts("无意义");
			exit(1);
		}
		y = 0.0;
	}
	else // x != 0
	{
		if (0 == n)
		{
			y = 1.0;
		}
		else if (n > 0)
		{
			y = Power(x, n / 2);
			y *= y;
			if (IsOdd(n))
			{
				y *= x;
			}
		}
		else // n < 0
		{
			y = 1.0 / Power(x, -n);
		}
	}	
	return y;
}

int TopDigit(int x)
{
	int y;
	if (x < 10)
	{
		y = x;
	}
	else
	{
		y = TopDigit(x / 10);
	}
	return y;
}

int LowDigit(int x)
{
	return x % 10;
}

int Digit(int x, int n)
{
	int y;
	if (n == 0)
	{
		y = x % 10;
	}
	else
	{
		y = Digit(x / 10, n - 1);
	}
	return y;
}

int NumDigit(int x)
{
	int y;
	if (x < 10)
	{
		y = 1;
	}
	else
	{
		y = NumDigit(x / 10) + 1;
	}
	return y;
}

int SumDigit(int x)
{
	int y;
	if (x < 10)
	{
		y = x;
	}
	else
	{
		y = SumDigit(x / 10) + x % 10;
	}
	return y;
}

void PrintInteger(int x, int r)
{
	int d;
	if (r < 2 || r > 36)
	{
		puts("Error!");
		exit(1);
	}
	if (x >= r)
	{
		PrintInteger(x / r, r);
	}
	d = x % r;
	if (d < 10)
	{
		putchar(d + '0');
	}
	else // d >= 10
	{
		putchar(d - 10 + 'A');
	}
}

/*
// 此方法效率非常低
double Cmb(int m, int n)
{
	double c;
	if (0 == n || n - m == 0)
	{
		c = 1.0;
	}
	else
	{
		c = Cmb(m - 1, n) + Cmb(m - 1, n - 1);
	}
	return c;
}
*/

// 此方法效率较高
double Cmb(int m, int n)
{
	double c;
	if (0 == n)
	{
		c = 1.0;
	}
	else if (n > m / 2)
	{
		c = Cmb(m, m - n);
	}
	else
	{
		c = Cmb(m, n - 1) * (m - n + 1) / n;
	}
	return c;
}


