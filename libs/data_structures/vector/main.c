#include <stdio.h>
#include <stdint.h>
#include "vector.h"
void test_atVector_notEmptyVector() {
    vector *v = {(vector *) 1, 3, 5};
    isEmpty(v);
};
void test_pushBack_emptyVector(){
    vector *v = {(vector *) 1, 3, 5};
    push_back((int) v, 3);
    isEmpty(v);
}
void test_PopBack_notEmptyVector() {
    vector v = vector_create(0);
    push_back(12, 14);
    assert(v.size == 1);
    pop_back(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}
void test() {
    test_atVector_notEmptyVector();
    test_pushBack_emptyVector();
    test_PopBack_notEmptyVector();
}
int main() {
    vector v = vector_create(SIZE_MAX);
    test();
    return 0;
}