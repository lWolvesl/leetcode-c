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

}

#endif //LEETCODE_C_429_H
