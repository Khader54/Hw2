#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_MAX_LENGTH 50


int main()
{
    int seen[ARR_MAX_LENGTH] = {0};

    int number, copyNumber, sumOfSquares = 0;

    printf("please enter a number:\n");
    scanf("%d", &number);
    copyNumber = number;


    for (int i = 0; i < ARR_MAX_LENGTH; i++)
    {
        while (copyNumber != 0)
        {
            sumOfSquares += (pow((copyNumber%10), 2));
            copyNumber /= 10;
        }
        if(sumOfSquares == 1)
        {
            printf("the number %d is happy\n", number);
            return 0;
        }
        copyNumber = sumOfSquares;
        seen[i] = sumOfSquares;
        sumOfSquares = 0;
        //printf("%d\n", seen[i]);

        for (int j = i - 1; j > 0; j--)
            if(seen[i] == seen[j] && seen[i] != 1)
            {
                printf("the number %d is not happy\n", number);
                return 0;
            }
    }
    printf("the number %d is not happy\n", number);
    return 0;
}