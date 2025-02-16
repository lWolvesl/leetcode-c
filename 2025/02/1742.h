#include <stdlib.h>
#include <math.h>

int get(int n){
    int res=0;
    while(n!=0){
        res += n%10;
        n = n/10;
    }
    return res;
}

int countBalls(int lowLimit, int highLimit) {
    int array[46];
    for(int i = 0;i<46;i++){
        array[i] = 0;
    }
    int count = 0;
    for(int i = lowLimit;i<=highLimit;i++){
        int j = get(i);
        array[j]++;
        count = fmax(count,array[j]);
    }
    return count;
}