//
// Created by 李洋 on 2025/1/11.
//
#include <math.h>

int min(int n1, int n2, int n3) {
    if (n1 <= n2 && n1 <= n3) {
        return n1;
    }
    return n2 <= n3 ? n2 : n3;
}

int generateKey(int num1, int num2, int num3) {
    int key = 0;
    for (int i = 0; i < 4; i++) {
        int div = (int)pow(10, 4 - i - 1);
        key += min(num1/div,num2/div,num3/div) * div;
        num1 %= div;
        num2 %= div;
        num3 %= div;
    }
    return key;
}

void run(){
    printf("%d\n",generateKey(1,100,1000));
}