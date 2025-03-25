#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cs50.h>

int main(void)
{
    int L = 1, U = 100;
    srand(time(NULL));
    int C = (rand() % (U - L + 1)) + L;

    string answer = get_string("你叫什麼名字? ");
    printf("嗨, %s! 我們來玩終極密碼吧!\n", answer);

    while (true)
    {
        int A = get_int("猜猜我的密碼是什麼? \n");

        if (A <= L || A >= U)
        {
            printf("誒誒! 你必須要猜 %d 與 %d 之間喔。\n", L, U);
            continue;
        }

        if (A == C)
        {
            printf("恭喜你，答對了!!\n");
            break;
        }
        else if (A > C)
        {
            U = A;
            printf("No no, 答案是 %d, 到 %d 之間\n", L, A);
        }
        else if (A < C)
        {
            L = A;
            printf("No no, 密碼是 %d 到 %d 之間 \n", A, U);
        }
    }
}
