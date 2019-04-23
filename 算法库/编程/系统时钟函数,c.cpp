#include <stdio.h>
#include <time.h>

int main()
{
	time_t n;
	int h,m,s;
	time(&n);
	n = n + 8 * 3600;
	n = n % 86400;
	h = n / 3600;
	n = n % 3600;
	m = n / 60;
	s = n % 60;
	printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}
