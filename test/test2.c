#include <stdio.h>

int main(){
    int i,j;
    i = 16;
    j = (i++)+i;
    printf("%d\n",j);
    i = 15;
    printf("%d %d\n",++i,i);
}