#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 定义 myVector 结构体
typedef struct myVector {
    unsigned capacity;   // 容量
    int *data;           // 指向数据的指针
} myVector;

// 初始化 myVector
void initVector(myVector *vec, unsigned initialCapacity);

// 扩大容量
void enlargeVector(myVector *vec);

// 清理 myVector
void freeVector(myVector *vec);

#endif // MYVECTOR_H