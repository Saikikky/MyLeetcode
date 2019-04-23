#include "MyComplex.h"

void InputComplex(REAL *rp,REAL *ip)//复数的输入 
{
	char s,t;
	double m,n;
	printf("复数：");
	scanf("%lg %c %lg %c",&m,&s,&n,&t);
	if(s != '+' && s != '-' || t != 'i')
	{
		puts("不正确的复数！");
		exit(1); 
	}
	if(s == '-')
	{
		*ip=-n;//修改虚部系数 
	} 
	else
	{
		*ip=n;
	}
	*rp=m;
} 
void OutputComplex(REAL rp,REAL ip)//复数的输出 
{
	printf("%.15g",rp);
	putchar(' ');
	putchar(ip >= 0 ? '+' : '-');
	putchar(' ');
	printf("%.15g", fabs(ip));
	putchar('i');
	putchar('\n');
}

 void AddComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip)
{
	 *zrp = xrp + yrp;
     *zip = xip + yip;    
}

void SubComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip)
{
     *zrp = xrp - yrp;
     *zip = xip - yip;    
}

void MulComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip)
{
     *zrp = xrp * yrp - xip * yip;
     *zip = xrp * yip + xip * yrp;    
}

void DivComplex(REAL *zrp, REAL *zip, REAL xrp, REAL xip, REAL yrp, REAL yip)
{
     if(0 == yrp && 0 == yip)
     {
          puts("除以零错误！");
          exit(1);
     }
     REAL t = yrp * yrp + yip * yip;
     *zrp = (xrp * yrp + xip * yip)/t;
     *zip = (xip * yrp - xrp * yip)/t;    

}
