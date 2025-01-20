//
// Created by 李洋 on 2025/1/14.
//

#ifndef LEETCODE_C_3065_H
#define LEETCODE_C_3065_H

int minOperations(int* nums, int numsSize, int k) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]<k){
            count++;
        }
    }
    return count;
}

#endif //LEETCODE_C_3065_H
