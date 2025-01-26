//
// Created by 李洋 on 2025/1/25.
//

#ifndef LEETCODE_C_2412_H
#define LEETCODE_C_2412_H

#include <stdlib.h>
#include <limits.h>

// 对任意贸易顺序，要求最小money
// 其实是在要所有贸易顺序对应的最小money中最大的那一个
// 哪怕先亏后赚，流动资金也必须足够
// 那么答案自然需要按先亏钱再赚钱的顺序来

// 假设初始资金为money，所有亏钱交易的总亏损额为sum_lost
// 在付出最后一笔亏钱交易的cost之后，要保证剩余钱数不为负
// 也就是money - sum_lost - last_cashback >= 0
// sum_lost是固定值，要让最小money最大，那就需要last_cashback最大
// 也就是安排cashback最大的亏钱贸易，作为最后一笔亏钱贸易

// 此时剩余的钱数刚好就是max_cashback
// 初始资金money = sum_lost + max_cashback
// 如果此时这个剩余钱数，不足以支付某一笔赚钱交易的cost
// 那么还能让money变大，变成sum_lost + max_cashback + (cost - max_cashback)
// 也就是sum_lost + cost

// 很显然，把cost最大的赚钱贸易放在第一位，更有利于让最小money达到最大
// 此时的money = sum_lost + max_cost

// 所以money答案就是sum_lost + max(max_cost, max_cashback)

long long minimumMoney(int **transactions, int transactionsSize, int *transactionsColSize) {
    long long total_lose = 0;
    int res = 0;

    for (int i = 0; i < transactionsSize; i++) {
        int cost = transactions[i][0];
        int cashback = transactions[i][1];
        if (cost > cashback) {
            total_lose += (cost - cashback);
        }
        if (cashback < cost) {
            if (cashback > res) {
                res = cashback;
            }
        } else {
            if (cost > res) {
                res = cost;
            }
        }
    }
    return total_lose + res;
}

#endif //LEETCODE_C_2412_H
