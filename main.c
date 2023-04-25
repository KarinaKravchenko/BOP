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


void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);

    assert(v.data == atVector(&v, 0));

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);

    assert(&v.data[4] == atVector(&v, 4));

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    assert(v.data == back(&v));

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    assert(v.data == front(&v));

    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}