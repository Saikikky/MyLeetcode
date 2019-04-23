#include <iostream>
using namespace std;

int a[100];
int F(int n);

int main()
{
	int n, m;
	cin >> n;
	while( n-- )
	{
		cin >> m;
		cout << F(m) << endl;
	} 
	return 0;	
} 

int F(int n)
{
	if (n == 2) return a[n] = 3;
	else if (n == 3) return a[n] = 5;
	else
	{
		if (a[n]) return a[n];
		else return a[n] = F(n - 1) + F(n - 2);
	}
}
