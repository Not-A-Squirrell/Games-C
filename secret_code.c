#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cs50.h>

int main(void)
{
    int L = 1, U = 100;
    srand(time(NULL));
    int C = (rand() % (U - L + 1)) + L;

    string answer = get_string("Hi, friend! What's your name? ");
    printf("Hi, %s! Let's guess what my Secret Code is!\n", answer);

    while (true)
    {
        int A = get_int("What do you think it could be?\n");

        if (A <= L || A >= U)
            {
                printf("Whoa there! Your guess needs to be between %d and %d.\n", L, U);
                continue;
            }
        if (A == C)
        {
            printf("Congratulations, you guessed it!\n");
            break;
        }

        else if (A > C)
        {
            U = A;
            printf("Nope, try again. The answer is somewhere between %d and %d.\n", L, A);
        }

        else if (A < C)
        {
            L = A;
            printf("Nope, try again. The answer is somwhere between %d and %d.\n", A, U);
        }
    }
}
