#include <stdio.h>
#include <ctype.h>
char Encode(char plain);
int main()
{
	char x,y;
	printf("Ã÷ÎÄ£º");
	scanf(" %c",&x);
	y = Encode(x);
	printf("ÃÜÎÄ£º%c\n",y);
	return 0;
} 
char Encode(char plain)
{
	char y;
	switch(isupper(plain))
	{
		case 0:
		plain = toupper(plain);	
		break;
	}
	switch(plain)
	{
	case 'A':
		y = 'X';
		break;
	case 'B':
		y = 'S';
		break;
	case 'C':
		y = 'A';
		break;
	case 'D':
		y = 'O';
		break;
	case 'E':
		y = 'M';
		break;
	case 'F':
		y = 'Y';
		break;
	case 'G':
		y = 'C';
		break;
	case 'H':
		y = 'J';
		break;
	case 'I':
		y = 'E';
		break;
	case 'J':
		y = 'R';
		break;
	case 'K':
		y = 'F';
		break;
	case 'L':
		y = 'N';
		break;
	case 'M':
		y = 'I';
		break;
	case 'N':
		y = 'G';
		break;
	case 'O':
		y = 'B';
		break;
	case 'P':
		y = 'T';
		break;
	case 'Q':
		y = 'Z';
		break;
	case 'R':
		y = 'Q';
		break;
	case 's':
		y = 'H';
		break;
	case 'T':
		y = 'U';
		break;
	case 'U':
		y = 'D';
		break;
	case 'V':
		y = 'P';
		break;
	case 'W':
		y = 'K';
		break;
	case 'X':
		y = 'V';
		break;
	case 'Y':
		y = 'W';
		break;
	case 'Z':
		y = 'L';
		break;
	}
	return y;
}
