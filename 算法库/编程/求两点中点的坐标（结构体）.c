#include <stdio.h>

void Input(struct POINT *p);
void Output(struct POINT p);
struct POINT MidPoint(struct POINT,struct POINT q);

struct POINT
{
	double x,y;
};

int main()
{
	struct POINT a,b,c;
	printf("a�������:");
	Input(&a);
	printf("b�������:");
	Input(&b);
	c = MidPoint(a,b);
	printf("c�������:");
	Output(c);
	putchar('\n');
	return 0;
}

void Input(struct POINT *p)
{
	double x,y;
	scanf("%lg%lg",&x,&y);
	p -> x = x;
	p -> y = y;
}


void Output(struct POINT p)
{
	printf("(%g,%g)",p.x,p.y);
}


struct POINT MidPoint(struct POINT,struct POINT q)
{
	struct POINT m;
	m.x = (p.x + q.x) / 2.0;
	m.y = (p.y + q.x) / 2.0;
	return m;
}
