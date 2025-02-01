//
// Created by 李洋 on 2025/1/31.
//

#ifndef LEETCODE_C_541_H
#define LEETCODE_C_541_H

#include <string.h>

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b, *b = tmp;
}

// c语言数组连续分配，指针值就是从小到大且连续
void reverse(char* l, char* r) {
    while (l < r) {
        swap(l++, --r); // 在C语言中，指针的自增（l++）和自减（--r）操作是根据指针的类型来决定的，而不是单纯加一。
    }
}

int min(int a, int b) {
    return a < b ? a : b;
}

char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k) {    // 按照2k的倍数进行开始，k倍结束，仅需在末尾处理大小关系
        reverse(&s[i], &s[min(i + k, n)]);
    }
    return s;
}

#endif //LEETCODE_C_541_H
