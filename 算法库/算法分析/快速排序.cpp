#include <iostream>
using namespace std;

void QuickSort(int A[], int from, int to);
int part(int A[], int from, int to);

int main()
{
	
	return 0;
}

void QuickSort(int A[], int from, int to)
{
	int position;
	if (from < to)
	{
		position = part(A, from, to);
		QuickSort(A, from, postion - 1);
		QuickSort(A, position + 1, to);
	}
}

int part(int A[], int from, int to)
{
	int i = from + 1, j = to, t;
	while (i <= j)
	{
		while (i <= to && A[i] <= A[from]) i++;
		while (j >= from && A[j] > A[from]) j--;
		if (i < j)
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	t = A[j];
	A[j] = A[from];
	A[from] = t;
	return j;
}
