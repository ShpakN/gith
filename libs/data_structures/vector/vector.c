#include "vector.h"

bool isEmpty(vector *v) {
    bool isEmpty = sizeof(v) == 0;
    printf("%s\n", isEmpty ? "true" : "false");
    return 0;
};

void STD_ERROR_N_EXIT(vector (*create)(const size_t), const char *string);

vector vector_create(const size_t size) {
    vector vec;

    if (size == 0) {
        vec.data = NULL;
    } else {
        vec.data = malloc(sizeof(int) * size);
        if (!vec.data) {
            STD_ERROR_N_EXIT(vector_create, "bad allocation for vec.m_data{}");
        }
    }

    vec.size = 0u;
    vec.capacity = size;

    return vec;
}

void STD_ERROR_N_EXIT(vector (*create)(const size_t), const char *string) {

}


bool isFull(vector *v) {
    vector vec;
    bool isFull = sizeof(v) == vec.size;
    printf("%s\n", isFull ? "true" : "false");
    return 0;
}

void pop_back() {
    vector vec;
    while (vec.size < vec.capacity) {
        vec.capacity = vec.capacity - 1;
    }
    if (vec.size == vec.capacity) {
        int *temp = (int *) malloc((vec.size - 1) * sizeof(int));
        const void *p;
        memmove(temp, p, (vec.size - 1) * sizeof(int));
        free(p);
        p = temp;
        vec.size = vec.size - 1;
    }
}

void push_back(const int val, int i) {
    vector vec;
    if (vec.size > 0) {
        const void *p;
        if (vec.size == vec.capacity) {
            vec.capacity *= 2;
            int *tmp = (int *) malloc(vec.capacity * sizeof(int));
            memmove(tmp, p, vec.size * sizeof(int));
            free(p);
            p = tmp;
        }
    }
}
void clear(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
void shrinkToFit(vector *v) {
    v->capacity = v->size;
    v->data = realloc(v->data, v->capacity * sizeof(void*));
}
void deleteVector(vector *v){
    clear(v);
    shrinkToFit(v);
}
void init_vector(vector *vector, size_t block_size, size_t element_size) {
    vector->data = (void *) malloc(block_size * element_size);
    vector->element_size = element_size;
    vector->size = 0;
    vector->capacity = block_size * element_size;
}

void atVector(vector *vector, size_t new_size) {
    void *data2 = (void *) malloc(new_size * vector->element_size);
    int i = 0;
    memmove(data2, vector->data, new_size * vector->element_size);
    vector->data = data2;
    if (new_size > vector->size) {
        for (i = vector->size - 1; i < new_size; i++) {
            vector->data[i] = 0;
        }
    } else {
        vector->size = new_size;
    }
    vector->capacity = new_size * vector->element_size;
}
