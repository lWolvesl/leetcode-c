#ifndef L624
#define L624

#include <math.h>

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int res = 0;
    int n = arraysColSize[0];
    int min_val = arrays[0][0];
    int max_val = arrays[0][arraysColSize[0] - 1];
    for (int i = 1; i < arraysSize; i++) {
        n = arraysColSize[i];
        res = fmax(res, fmax(abs(arrays[i][n - 1] - min_val), 
                             abs(max_val - arrays[i][0])));
        min_val = fmin(min_val, arrays[i][0]);
        max_val = fmax(max_val, arrays[i][n - 1]);
    }
    
    return res;
}

#include <vector>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int res = 0;
    int n = arrays[0].size();
    int max_val = arrays[0][n-1];
    int min_val = arrays[0][0];
    for (int i = 1; i < arrays.size(); i++)
    {
        n = arrays[i].size();
        res = max(res,max(abs(arrays[i][n-1]-min_val),abs(arrays[i][0] - max_val)));
        min_val = min(min_val,arrays[i][0]);
        max_val = max(max_val,arrays[i][n-1]);
    }
    return res;
}

#endif