//
// Created by 李洋 on 2024/3/26.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int coinChange(int *coins, int coinsSize, int amount)
{
    int *dp = (int *)calloc((amount + 1), sizeof(int));
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < coinsSize; ++j)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

void run()
{
    int a1[3] = {1, 2, 5};
    int a2[4] = {3, 7, 405, 436};
    int a3[1] = {2};
    coinChange(a3, 1, 3);
}
