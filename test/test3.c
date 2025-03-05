#include <stdio.h>

int main(){
    int i;
    char *s = "a\045+45\'b";
    for(i=0;s++;i++);
    printf("%d\n",i);
}

// 无限循环
