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

vectorVoid createVectorV(const size_t size, unsigned long long int i) {
    vectorVoid vec;

    if (size == 0) {
        vec.data = NULL;
    } else {
        vec.data = malloc(sizeof(int) * size);
    }

    vec.size = 0u;
    vec.capacity = size;

    return vec;
}

void vectorV_push_back(vectorVoid *v, int value) {
    if (v->size >= v->capacity) {
        v->capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
        v->data = (int *) realloc(v->data, v->capacity * sizeof(int));
    }
}

void vectorV_swapV(vectorVoid *v1, vectorVoid *v2) {
    vectorVoid temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void vectorV_clearV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    bool isEmpty = sizeof(v) == 0;
    printf("%s\n", isEmptyV ? "true" : "false");
}

bool isFullV(vectorVoid *v) {
    vectorVoid vec;
    bool isFullV = sizeof(v) == vec.size;
    printf("%s\n", isFullV ? "true" : "false");
    return 0;
}
void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}
int main() {
    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        vectorV_push_back(&v, x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        printf("%d ", x);
    }
    return 0;
}
#endif