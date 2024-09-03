#include <stdio.h>
#include <stdlib.h>
#include "myVector.h"

// 初始化 myVector
void initVector(myVector *vec, unsigned initialCapacity) {
    vec->capacity = initialCapacity;
    vec->size = 0;
    vec->data = (int *)calloc(vec->capacity, sizeof(int));
    if (vec->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// 检查容量
unsigned getCapacity(myVector *vec) {
    return vec->capacity;
}
//扩大容量
void enlargeVector(myVector *vec) {
    unsigned newCapacity = 2 * vec->capacity;
    if (newCapacity <= vec->capacity) {
        fprintf(stderr, "New capacity must be greater than current capacity\n");
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
// 检查大小
unsigned getSize(myVector *vec) {
    return vec->size;
}

// 扩大容量
static void resizeVector(myVector *vec) {
    vec->capacity *= 2;
    vec->data = (int *)realloc(vec->data, sizeof(int) * vec->capacity);
    if (vec->data == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// 插入元素
void insertElement(myVector *vec, int element) {
    if (vec->size == vec->capacity) {
        resizeVector(vec);
    }
    vec->data[vec->size] = element;
    vec->size++;
}


// 清理 myVector
void freeVector(myVector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
    vec->size = 0;
}