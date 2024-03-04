#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "assert.h"

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t element_size; // размер элемента
    size_t capacity; // вместимость вектора
} vector;

