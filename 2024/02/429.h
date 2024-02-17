//
// Created by 李洋 on 2024/2/17.
//

#ifndef LEETCODE_C_429_H
#define LEETCODE_C_429_H

#include "stdlib.h"

struct Node {
    int val;
    int numChildren;
    struct Node **children;
};

struct linkedNode {
    int val;
    struct linkedNode *next;
};

struct queue {
    struct linkedNode *head;
    struct linkedNode *tail;
    int size;
};

void push(struct queue Q, int val) {
    struct linkedNode *temp = (struct linkedNode *) malloc(sizeof(struct linkedNode));
    Q.size++;
    if (Q.size == 0) {
        temp->val = val;
        Q.head = temp;
        Q.tail = temp;
        return;
    }
    Q.tail->next = temp;
    Q.tail = temp;
}

int pop(struct queue Q) {
    int top = Q.head->val;
    struct linkedNode *temp = Q.head;
    Q.head = temp->next;
    free(temp);
    Q.size--;
    return top;
}

int top(struct queue Q) {
    return Q.head->val;
}

int **levelOrder(struct Node *root, int *returnSize, int **returnColumnSizes) {
    int ** ans = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    if (!root) {
        *returnSize = 0;
        return ans;
    }
    struct Node ** queue = (struct Node **)malloc(sizeof(struct Node *) * 10000);
    int head = 0, tail = 0;
    int level = 0;
    queue[tail++] = root;

    while (head != tail) {
        int cnt = tail - head;
        ans[level] = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; ++i) {
            struct Node * cur = queue[head++];
            ans[level][i] = cur->val;
            for (int j = 0; j < cur->numChildren; j++) {
                queue[tail++] = cur->children[j];
            }
        }
        (*returnColumnSizes)[level++] = cnt;
    }
    *returnSize = level;
    free(queue);
    return ans;
}

#endif //LEETCODE_C_429_H
