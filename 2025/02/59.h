#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int **ret = (int**)malloc(sizeof(int*) * n);
    *returnSize = n; // 设置返回的行数
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ret[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    int dir = 0; // 0:右,1:下,2:左,3:上
    
    while (top <= bottom && left <= right) {
        switch (dir) {
            case 0: // 向右填充上边界
                for (int i = left; i <= right; i++) {
                    ret[top][i] = num++;
                }
                top++; // 上边界下移
                dir = 1;
                break;
            case 1: // 向下填充右边界
                for (int i = top; i <= bottom; i++) {
                    ret[i][right] = num++;
                }
                right--; // 右边界左移
                dir = 2;
                break;
            case 2: // 向左填充下边界
                for (int i = right; i >= left; i--) {
                    ret[bottom][i] = num++;
                }
                bottom--; // 下边界上移
                dir = 3;
                break;
            case 3: // 向上填充左边界
                for (int i = bottom; i >= top; i--) {
                    ret[i][left] = num++;
                }
                left++; // 左边界右移
                dir = 0;
                break;
        }
    }
    return ret;
}
