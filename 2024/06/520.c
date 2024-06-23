//
// Created by 李洋 on 2024/6/23.
//

#ifndef LEETCODE_C_520_CPP
#define LEETCODE_C_520_CPP

#include <stdlib.h>
#include "ctype.h"
#include "stdbool.h"
#include "string.h"

char *toLowerCase(const char *str) {
    char *result = (char *) malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        result[i]= tolower(str[i]);
    }
    return result;
}

// 通过数值判断
bool detectCapitalUse(char *word) {
    char *lower = toLowerCase(word);
    int count = 0;
    for (int i = 0; i < strlen(word); ++i) {
        count += lower[i] - word[i];
    }
    int interval = 'a' - 'A';
    if ((count == interval && word[0] >= 'A' && word[0] <= 'Z') || count == interval * strlen(word) || count == 0) {
        return true;
    }
    return false;
}

bool run() {
    return detectCapitalUse("USA");
}

#endif //LEETCODE_C_520_CPP
