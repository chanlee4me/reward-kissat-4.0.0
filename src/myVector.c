//added by cl
#include <stdio.h>
#include <stdlib.h>
#include "myVector.h"

// 初始化 myVector
void initVector(myVector *vec, size_t initialCapacity) {
    vec->capacity = initialCapacity;
    vec->data = (int *)calloc(vec->capacity, sizeof(int));
    if (vec->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}


//扩大容量
void enlargeVector(myVector *vec) {
    size_t newCapacity = 2 * vec->capacity;
    if (newCapacity <= vec->capacity) {
        fprintf(stderr, "Capacity overflow: current capacity = %llu\n", vec->capacity);
        return;
    }
    int *newData = (int *)realloc(vec->data, sizeof(int) * newCapacity);
    if (newData == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    // 使用 memset 初始化新分配的内存
    memset(newData + vec->capacity, 0, (newCapacity - vec->capacity) * sizeof(int));
    vec->data = newData;
    vec->capacity = newCapacity;
}

// 清理 myVector
void freeVector(myVector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
}