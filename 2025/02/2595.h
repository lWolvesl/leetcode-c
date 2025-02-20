#ifndef L2595
#define L2595

#include <stdlib.h>

int* evenOddBit(int n, int* returnSize) {
    int *ret = (int*)calloc(2,sizeof(int));
    //memset(arr, 0, n * sizeof(int));
    *returnSize = 2;
    for(int i = 0;n!=0;i++){
        if((n&1)==1){
            if(i%2==1){
                ret[1]++;
            }else{
                ret[0]++;
            }
        }
        n = n >> 1;
    }
    return ret;
}

#include <vector>
using namespace std;

vector<int> evenOddBit(int n) {
    vector<int> ret(2);
    for(int i = 0;n!=0;i++){
        if((n&1)==1){
            if(i%2==1){
                ret[1]++;
            }else{
                ret[0]++;
            }
        }
        n >>= 1;
    }
    return ret;
}

#endif