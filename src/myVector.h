#ifndef MYVECTOR_H
#define MYVECTOR_H

typedef struct myVector {
    unsigned capacity;   // 容量
    unsigned size;       // 大小
    int *data;           // 指向数据的指针
}myVector;

// 初始化myVector
void initVector(myVector *vec, unsigned initialCapacity);

// 检查容量
unsigned getCapacity(myVector *vec);

// 检查大小
unsigned getSize(myVector *vec);
#include <stdio.h>
#include <stdlib.h>

// 定义 myVector 结构体
typedef struct myVector {
    unsigned capacity;   // 容量
    unsigned size;       // 大小
    int *data;           // 指向数据的指针
} myVector;

// 初始化 myVector
void initVector(myVector *vec, unsigned initialCapacity) {
    vec->capacity = initialCapacity;
    vec->size = 0;
    vec->data = (int *)malloc(sizeof(int) * vec->capacity);
    if (vec->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// 扩大容量
void enlargeVector(myVector *vec);

// 插入元素
void insertElement(myVector *vec, int element);

// 获取指向数据的指针
int *getDataPointer(myVector *vec);

// 清理 myVector
void freeVector(myVector *vec);

#endif // MYVECTOR_H