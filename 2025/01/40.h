//
// Created by 李洋 on 2025/1/26.
//

#ifndef LEETCODE_C_40_H
#define LEETCODE_C_40_H

#include <stdlib.h>
#include <string.h>
#include <math.h>

int** ans;
int* ansColumnSizes;
int ansSize;

int* sequence;
int sequenceSize;

int** freq;
int freqSize;

void dfs(int pos, int rest) {
    if (rest == 0) {
        int* tmp = malloc(sizeof(int) * sequenceSize);
        memcpy(tmp, sequence, sizeof(int) * sequenceSize);
        ans[ansSize] = tmp;
        ansColumnSizes[ansSize++] = sequenceSize;
        return;
    }
    if (pos == freqSize || rest < freq[pos][0]) {
        return;
    }

    dfs(pos + 1, rest);

    int most = fmin(rest / freq[pos][0], freq[pos][1]);
    for (int i = 1; i <= most; ++i) {
        sequence[sequenceSize++] = freq[pos][0];
        dfs(pos + 1, rest - i * freq[pos][0]);
    }
    sequenceSize -= most;
}

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    ans = malloc(sizeof(int*) * 2001);
    ansColumnSizes = malloc(sizeof(int) * 2001);
    sequence = malloc(sizeof(int) * 2001);
    freq = malloc(sizeof(int*) * 2001);
    ansSize = sequenceSize = freqSize = 0;

    qsort(candidates, candidatesSize, sizeof(int), comp);
    for (int i = 0; i < candidatesSize; ++i) {
        if (freqSize == 0 || candidates[i] != freq[freqSize - 1][0]) {
            freq[freqSize] = malloc(sizeof(int) * 2);
            freq[freqSize][0] = candidates[i];
            freq[freqSize++][1] = 1;
        } else {
            ++freq[freqSize - 1][1];
        }
    }
    dfs(0, target);
    *returnSize = ansSize;
    *returnColumnSizes = ansColumnSizes;
    return ans;
}

#endif //LEETCODE_C_40_H
