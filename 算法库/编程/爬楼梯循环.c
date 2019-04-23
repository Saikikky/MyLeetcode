#include <stdio.h>
#include "MyMath.h"
REAL Upstairs(INTEGER n);
int main()
{
	INTEGER n;
	REAL u;
	printf("台阶 = ? ");
	scanf(ISF, &n);
	u = Upstairs(n);
	printf("方案 = " RPF "\n", u);
	return 0;
}
REAL Upstairs(INTEGER n)
{
	int u1 = 1,u2 = 2,u3 = 4,k = 4;
	REAL u = 0.0;
	switch(n)
	{
	case 1:
		u = 1;
		break;
	case 2:
		u = 2;
		break;
	case 3:
		u = 4;
		break;
	default:
		while(k <= n)
		{
			u = u1 + u2 + u3;
			u1 = u2;
			u2 = u3;
			u3 = u;
			k++;
		}
    }
		return u;
}
/*
REAL Upstairs(INTEGER n)
{
    REAL ok;
    if (1 == n)
    {
        ok = 1;
    }
    else if (2 == n)
    {
        ok = 2;
    }
    else if (3 == n)
    {
        ok = 4;
    }
    else
    {
        ok = Upstairs(n - 1) + Upstairs(n - 2) + Upstairs(n - 3);
    }
    return ok;
} // 算39等了10秒*/
