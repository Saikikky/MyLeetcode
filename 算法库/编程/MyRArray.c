#include <stdio.h>
#include "MyRArray.h"

// ����ʵ��
void SwapReal(REAL *x, REAL *y)
{
	REAL t;
	t = *x;
	*x = *y;
	*y = t;
}
