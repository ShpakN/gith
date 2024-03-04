#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <stddef.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;


#endif