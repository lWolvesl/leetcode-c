//
// Created by 李洋 on 2024/6/21.
//

#ifndef LEETCODE_C_LCP61_H
#define LEETCODE_C_LCP61_H

# include <math.h>

int getTemper(int *temperA, int i) {
    if (temperA[i + 1] == temperA[i]) {
        return 0;
    }
    return temperA[i + 1] < temperA[i] ? -1 : 1;
}

int temperatureTrend(int *temperatureA, int temperatureASize, int *temperatureB, int temperatureBSize) {
    int ans = 0, count = 0;
    for (int i = 0; i+1 < temperatureASize; ++i) {
        int a = getTemper(temperatureA, i);
        int b = getTemper(temperatureB, i);
        if (a == b) {
            count++;
            ans = fmax(ans, count);
        } else count = 0;
    }
    return ans;
}

#endif //LEETCODE_C_LCP61_H
