#ifndef L1299
#define L1299

// 模拟超时
// int* replaceElements(int* arr, int arrSize, int* returnSize) {
//     for(int i = 0;i < arrSize - 1;i++){
//         int max = 0;
//         for (int j = i+1; j < arrSize; j++)
//         {
//             max = fmax(max,arr[j]);
//         }
//         arr[i] = max;
//     }
//     arr[arrSize - 1] = -1;
//     *returnSize = arrSize;
//     return arr;
// }


int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int now = arr[arrSize-1];
    for(int i = arrSize -2;i>=0;i--){
        int temp = arr[i];
        arr[i] = now;
        now = fmax(now,temp);
    }
    arr[arrSize-1] = -1;
    *returnSize = arrSize;
    return arr;
}

#include <vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int now = arr[arr.size()-1];
    int temp = 0;
    for(int i=arr.size()-2;i>=0;i--){
        temp = arr[i];
        arr[i] = now;
        now = max(now,temp);
    }
    arr[arr.size()-1]=-1;
    return arr;
}

#endif