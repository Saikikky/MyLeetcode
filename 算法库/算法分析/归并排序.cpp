/*#include <iostream>
using namespace std;

void Merge(int A[], int from, int to);

int main()
{
	
	return 0;
}

void Merge(int A[], int from, int to)
{
	int *t = new int [to - from + 1];
	int k = 0, i = from, mid = (from + to) / 2, j = mid + 1;
	if (from == to) return;
	Merge(A, from, mid);
	Merge(A, mid + 1, to);
	while (i <= mid && j <= to)
	{
		if (A[i] < A[j])
		{
			t[k++] = A[i++];
		}
		else
		{
			t[k++] = A[j++];
		}
	}
	while (i <= mid) t[k++] = A[i++];
	while (j <= to) t[k++] = A[j++];
	i = from;
	k = 0;
	while (i <= to) A[i++] = t[k++];
}*/
#include<iostream>
using namespace std;

int a[8] = {1, 2, 3, 4, 6, 5, 8, 7};
int b[8] = {};
void F(int *a, int from, int to)
{
	int i, j, t, pos, tag;
	if(from < to)
	{
		int pos = (to+from)/2;

		F(a, from, pos);
		F(a, pos+1, to);
//		cout << from << " " << pos << " " << pos+1 << " " << to << endl;
		if(from <= pos)
		{
			for(tag =from, i=from, j=pos+1; i <=pos && j <= to;)
			{
				if(a[i] < a[j])
				{
					b[tag++] = a[i++];
				}
				else if( a[i] > a[j])
				{
					b[tag++] = a[j++];
				}
				else if( a[i] == a[j])
				{
					b[tag++] = a[i++];
					b[tag++] = a[j++];
				}
			}
			while (i <= pos) b[tag++] = a[i++];
			while (j <= to) b[tag++] = a[j++];
			for (int m = from; m <= to; m++)
			{
				a[m] = b[m];
			}
		}
	}
}

int main()
{
	F(a, 0, 7);
	for(int i =0; i<8; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

