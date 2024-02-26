#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;
vector vector_create( const size_t size ) {
    vector vec;

    if ( size == 0 ) {
        vec.data = NULL;
    }
    else {
        vec.data = malloc( sizeof( int ) * size );
        if ( !vec.data ) {
//            STD_ERROR_N_EXIT( vector_create, "bad allocation for vec.m_data{}" );
        }
    }

    vec.size = 0u;
    vec.capacity = size;

    return vec;
}
bool isEmpty(vector *v){
    bool isEmpty = sizeof(v) == 0;
    printf("%s\n", isEmpty ? "true" : "false");
    return 0;
}
//void test_popBack_notEmptyVector() {
//    vector v = vector_create(0);
//    pushBack(&v, 10);
//    assert(v.size == 1);
//    popBack(&v);
//    assert(v.size == 0);
//    assert(v.capacity == 1);
//}