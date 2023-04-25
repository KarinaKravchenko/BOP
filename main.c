#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(5);
    pushBack(&v, 3);

    assert(v.size == 1 && v.data[0] == 3);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    pushBack(&v, 3);

    assert(v.size == 6 && v.data[5] == 3 && v.capacity == 10);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}