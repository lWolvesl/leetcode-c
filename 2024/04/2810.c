//
// Created by 李洋 on 2024/4/3.
//
#include <stdlib.h>
#include <string.h>

void reverse(char *s, int end) {
    int i = 0;
    while (i < end) {
        char temp = s[i];
        s[i] = s[end];
        s[end] = temp;
        i++;
        end--;
    }
}

char *finalString(char *s) {
    int len = strlen(s);
    char *r = malloc((len + 1) * sizeof(char));
    int x = 0;
    for (int i = 0; i < len; i++) {
        if (i != 0 && s[i] == 'i') {
            reverse(r, x - 1);
        } else {
            r[x++] = s[i];
        }
    }
    r[x] = '\0';
    return r;
}