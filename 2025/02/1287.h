#ifndef L1287
#define L1287

int findSpecialInteger(int *arr, int arrSize)
{
    int now = arr[0];
    int count = 1;
    int st = arrSize / 4;
    for (int i = 1; i < arrSize; i++)
    {
        if (now == arr[i])
            count++;
        if (count > st)
        {
            return now;
        }
        if (now != arr[i])
        {
            now = arr[i];
            count = 1;
        }
    }
    return now;
}


#include <vector>
using namespace std;


// 基本思想，出现1/4次代表在每个1/4的点上，至少有一个点是结果
class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int n = arr.size();
            int span = n / 4 + 1;
            for (int i = 0; i < n; i += span) {
                auto iter_l = lower_bound(arr.begin(), arr.end(), arr[i]);
                auto iter_r = upper_bound(arr.begin(), arr.end(), arr[i]);
                if (iter_r - iter_l >= span) {
                    return arr[i];
                }
            }
            return -1;
        }
    };

#endif