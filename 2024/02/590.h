//
// Created by 李洋 on 2024/2/19.
//

#ifndef LEETCODE_C_590_H
#define LEETCODE_C_590_H

#include <stdlib.h>


struct Node {
    int val;
    int numChildren;
    struct Node **children;
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODE_SIZE 10000

void helper(const struct Node* root, int* res, int* pos) {
    if (NULL == root) {
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {
        helper(root->children[i], res, pos);
    }
    res[(*pos)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    int * res = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int pos = 0;
    helper(root, res, &pos);
    *returnSize = pos;
    return res;
}

#endif //LEETCODE_C_590_H
