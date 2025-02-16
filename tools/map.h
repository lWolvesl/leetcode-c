// 使用冲突链表实现的哈希表
#ifndef LISTMAP
#define LISTMAP

#include <stdlib.h>
#include <stdio.h>

int getPri(int n) {
    int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
        127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
        179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
        233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
        283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
        353, 359, 367, 373, 379, 383, 389, 397
    };
    int len = sizeof(primes) / sizeof(primes[0]);
    for (int i = len - 1; i >= 0; i--) {
        if (primes[i] < n) {
            return primes[i];
        }
    }
    return 1; // 如果n小于2，返回1
}

typedef struct List
{
    int value;
    struct List *next;
}List;

typedef struct ListMap
{
    int hash;
    int valid;
    int value;
    List *next;
}ListMap;

ListMap *createListMap(int n){
    int size = getPri(n);

    ListMap *map = (ListMap *)malloc(sizeof(ListMap)*size);
    if (map == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    // 初始化每个链表节点
    for (int i = 0; i < size; i++) {
        map[i].hash = size;
        map[i].valid = 0;      // 初始状态
        map[i].value = 0;      // 初始值
        map[i].next = NULL;    // 初始指针
    }

    return map;
}

int hashCode(int key, int hash) {
    return key % hash;
}

static int get(ListMap *map, int key) {
    int hash = hashCode(key, map[0].hash);
    if(map[hash].valid == 0){
        return -1;
    }else{
        if(map[hash].value == key){
            return hash;
        }
        List *node = map[hash].next;
        while (node)
        {
            if(node->value == key){
                return hash;
            }
            node = node->next;
        }
    }
    return -1;
}

int insert(ListMap *map, int key) {
    int hash = hashCode(key, map[0].hash);
    if(get(map, key) != -1){
        return 2;
    }
    if(map[hash].valid == 0){
        map[hash].valid = 1;
        map[hash].value = key;
    }else{
        List *node = map[hash].next;
        while (node)
        {
            node = node->next;
        }
        
        List *newNode = (List *)malloc(sizeof(List));
        newNode->value = key;
        newNode->next = NULL;
        node->next = newNode;
    }
    return 1;
}

#endif
