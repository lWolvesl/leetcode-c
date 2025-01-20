//
// Created by 李洋 on 2025/1/20.
//

#ifndef LEETCODE_C_2239_H
#define LEETCODE_C_2239_H

#include <limits.h>
#include <stdlib.h>

int findClosestNumber(int *nums, int numsSize) {
    int min = INT_MAX;
    int res = INT_MIN;

    for (int i = 0; i < numsSize; ++i) {
        int temp = abs(nums[i]);
        if (temp < min) {
            min = temp;
            res = nums[i];
        }
        if (temp == min) {
            res = nums[i] > res ? nums[i] : res;
        }
    }

    return res;
}

#endif //LEETCODE_C_2239_H
