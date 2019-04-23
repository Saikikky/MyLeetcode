#include <iostream>
using namespace std;

const unsigned int NUMBER_COUNT = 4; //9
const int NUM_MIN_VALUE = 1;
const int NUM_MAX_VALUE = 9;
const unsigned int FULL_NUMBER_VALUE = 24;//45;

void EnumNumbers(int *numbers, int level, int total)
{
    int i;
 	for(i = NUM_MIN_VALUE; i <= NUM_MAX_VALUE; i++)
    {
        numbers[level] = i;
        if(level == (NUMBER_COUNT - 1))
        {
            if(i == total)
            {
                 PrintNumbers(numbers, NUMBER_COUNT);
            }
        }
        else
        {
             EnumNumbers(numbers, level + 1, total - i);
        }
    }
}

 void PrintAllSResult2(void)
 {
    int numbers[NUMBER_COUNT] = { 0 };

     EnumNumbers(numbers, 0, FULL_NUMBER_VALUE);
 }
