//
// Created by 李洋 on 2025/1/13.
//

#ifndef LEETCODE_C_2270_H
#define LEETCODE_C_2270_H

int waysToSplitArray(int *nums, int numsSize) {
    long long int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }
    long long int count = 0;
    int i = 0;
    int res = 0;
    while (i < numsSize - 1) {
        count += nums[i];
        if(count * 2 > sum){
            res ++;
        }
        i++;
    }
    return res;
}

void run(){
    int nums[4] = {10,4,-8,7};
    int *p = nums;
    int res = waysToSplitArray(p,4);
    printf("%d\n",res);
}

#endif //LEETCODE_C_2270_H
