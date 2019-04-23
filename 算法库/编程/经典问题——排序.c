//≤Â»Î≈≈–Ú
void InsertSort(double array[],int size)
{
	double x;
	int i,j;
	for(i = 1;i < size;i++)
	{
		if(array[i] < array[i - 1])
		{
			x = array[i];
			for(j = i - 1;j >= 0 && array[j] > x;j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = x;
		}
	}
} 
//√∞≈›≈≈–Ú
void BubbleSort(double array[],int size)
{
	int i,j,loop = 1;
	for(i = size - 1;loop && i > 0;i--)
	{
		loop = 0;
		for(j = 0;j < i;j++)
		{
			if(array[j + 1] < array[j])
			{
				Swap(&array[j],&array[j + 1]);
				loop = 1;
			}
		}
	}
} 
//Ωªªª≈≈–Ú
void ExchangeSort(double array[],int size)
{
	int i,j,r = size - 1;
	for(i = 0;i < r;i++)
	{
		for(j = i + 1;j < size;j++)
		{
			if(array[j] < array[i])
			{
				Swap(&array[i],&array[j])
			}
		}
	}
//—°‘Ò≈≈–Ú
void SelectSort(double array[],int size)
{
	int i,j,k,r = size - 1;
	for( i = 0;i < r;i++)
	{
		k = i;
		for(j = i + 1;j < size;j++)
		{
			if(array[j] < array[k])
			{
				k = j;
			}
		}
		if(k > i)
		{
			Swap(&array[i],&array[k]);
		}
	}
} 
 
