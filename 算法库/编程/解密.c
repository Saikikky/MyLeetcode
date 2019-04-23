#include <stdio.h>
#include "MyMath.h"
#include <ctype.h>
void Decrypt();
char Decode(char plain); 

int main()
{
	Decrypt();
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

