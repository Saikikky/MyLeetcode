#include "MyComplex.h"
#include <stdio.h> 

int main()
{
	double rp,ip;
	printf("����:");
	InputComplex(&rp,&ip);
	printf("����:");
	OutputComplex(rp,ip);
	putchar('\n');
	return 0; 
}
