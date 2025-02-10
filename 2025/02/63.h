// 基本思路，反推，计算出从目标点回到出发点每个格子的累加，进行行列反推
// 写法为二维数组，但是每一行都只使用了一次，完全可以用单行数组进行代替
// 下一次优化，当再遇到二维数组dp时，尝试使用单行或者单列代替
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];  // 注意这里需要解引用列数数组
    if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
    
    // 使用 long long 存储路径数
    long long** dp = (long long**)malloc(m * sizeof(long long*));
    for (int i = 0; i < m; i++) {
        dp[i] = (long long*)calloc(n, sizeof(long long));
    }
    
    dp[m-1][n-1] = 1;  // 终点初始化
    
    for (int i = m-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (i == m-1 && j == n-1) continue;
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;  // 障碍物不可达
                continue;
            }
            long long right = (j+1 < n) ? dp[i][j+1] : 0;
            long long down = (i+1 < m) ? dp[i+1][j] : 0;
            dp[i][j] = right + down;
        }
    }
    
    long long result = dp[0][0];
    // 释放内存
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return (int)result;
}


void run(){
    int rows = 1, cols = 2;
    int **ob = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        ob[i] = (int *)malloc(cols * sizeof(int));
    }

    // 初始化数组
    int data[4][4] = {{0, 0}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            ob[i][j] = data[i][j];
        }
    }

    // 调用函数
    int colSize[rows];
    for (int i = 0; i < rows; i++) {
        colSize[i] = cols;
    }
    int res = uniquePathsWithObstacles(ob, rows, colSize);

    // 释放内存
    for (int i = 0; i < rows; i++) {
        free(ob[i]);
    }
    free(ob);
    printf("%d\n",res);
}
