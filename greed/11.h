#include <math.h>

// 核心优化，每次移动较小的那个，因为移动较大的那个，面积只会越来越小
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    while(left < right){
        max = fmax(max,(right-left)*fmin(height[left],height[right]));
        if (height[left] < height[right])
        {
            left++;
        }else{
            right--;
        }
    }
    return max;
}