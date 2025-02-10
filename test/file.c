#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp = fopen("example.txt","r+");
    if(fp == NULL){
        printf("error,cannot open file");
        return 1;
    }
    char buffer[100];
    fread(buffer,sizeof(char),100,fp);
    printf("%s\n",buffer);
    char *wt = "hello, World1!";
    fwrite(wt,sizeof(char),strlen(wt),fp);

    fclose(fp);
}