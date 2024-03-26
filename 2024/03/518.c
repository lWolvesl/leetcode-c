//
// Created by 李洋 on 2024/3/26.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int coinChange(int *coins, int coinsSize, int amount)
{
    int *dp = (int *)calloc((amount + 1), sizeof(int));
    //memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int a1[3] = {1, 2, 5};
    int a2[4] = {3, 7, 405, 436};
    int a3[1] = {2};
    coinChange(a3, 1, 3);
}
