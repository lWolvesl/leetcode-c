#include <string.h>

char* breakPalindrome(char* palindrome) {
    int length = strlen(palindrome);
    if (length==1)
    {
        return "";
    }
    for(int i = 0;i<length;i++){
        if(length%2==1&&i==length/2){
            i++;
        }
        if(palindrome[i]!='a'){
            palindrome[i]='a';
            return palindrome;
        }
        if(i==length-1){
            palindrome[i]='b';
        }
    }
    
    return palindrome;
}