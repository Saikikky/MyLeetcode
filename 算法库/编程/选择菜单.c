#include <stdio.h>
#include "MyMath.h"
void Encrypt();
char Encode(char plain);
void Decrypt();
char Decode(char plain); 
int main()
{
	char c;
	do
	{
		printf("E-加密 D-解密 Q-退出 >_");
      	scanf(" %c",&c);
      	fflush(stdin);
      
	    if('E' == c||'e' == c)
	    {
		    printf("明文：");
		   	Encrypt();
		   	
	   	}
	    else if('D' == c||'d' == c)
	    {
	       	printf("密文：");
	       	Decrypt();
	    }
	    else if('Q' == c||'q' == c)
	    {
	    	exit(1);
	    }
	    else
	    {
	     	printf("不正确的选项！");
	    }

	    putchar('\n');
    }
   
    while(c);
	return 0;
}
void Decrypt()
{
	char c,a;
	while(c != '\n')
	{
		c = getchar();
		a = Decode(c);
		printf("%c",a);
	}
}

char Decode(char cipher)

{

     char x , y;

     if (islower(cipher))     

     {

          x = toupper(cipher);

     }

     else

     {

          x = cipher;

     }

     switch(x)

     {

          case 'A':

               y = 'C';

               break;

          case 'B':

               y = 'O';

               break;

          case 'C':

               y = 'G';

               break;

          case 'D':

               y = 'U';

               break;

          case 'E':

               y = 'I';

               break;

          case 'F':

               y = 'K';

               break;

          case 'G':

               y = 'N';

               break;

          case 'H':

               y = 'S';

               break;

          case 'I':

               y = 'M';

               break;

          case 'J':

               y = 'H';

               break;

          case 'K':

               y = 'W';

               break;

          case 'L':

               y = 'Z';

               break;

          case 'M':

               y = 'E';

               break;

          case 'N':

               y = 'L';

               break;

          case 'O':

               y = 'D';

               break;

          case 'P':

               y = 'V';

               break;

          case 'Q':

               y = 'R';

               break;

          case 'R':

               y = 'J';

               break;

          case 'S':

               y = 'B';

               break;

          case 'T':

               y = 'P';

               break;

          case 'U':

               y = 'T';

               break;

          case 'V':

               y = 'X';

               break;

          case 'W':

               y = 'Y';

               break;

          case 'X':

               y = 'A';

               break;

          case 'Y':

               y = 'F';

               break;

          case 'Z':

               y = 'Q';

               break;

          default:

               y = '.' ;

     }

     if (islower(cipher))     

     {

          y = tolower(y);

     }

     else

     {

          y = y;

     }

     return y;

}

void Encrypt()
{
	char c,a;
	c = getchar();
	while(c != '\n')
	{
		a = Encode(c);
		if(isupper(c))
		{
			putchar(a);
		}
		else
		{
			a = tolower(a);
			putchar(a);
		}
	   
	    c = getchar(); 
	}
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
	case ' ':
		y = '.';
		break; 
	case ',':
		y = '.';
		break;
	case '.':
	    y = '.'; 
	}
	return y;
}
