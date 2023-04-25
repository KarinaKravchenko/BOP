#include "vector.h"

void errorMemory() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    int* a = (int*) malloc(sizeof(int) * n);

    if (a == NULL) {
        errorMemory();
    }

    vector v = {n ? a : NULL, 0, n};

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    }
    else if (newCapacity > v->capacity) {
        v->data = (int*) realloc(v->data, sizeof(v->data[0]) * newCapacity);
        v->capacity = newCapacity;
        if (v->data == NULL) {
            errorMemory();
        }
    }
    else if (newCapacity < v->capacity) {
        if (newCapacity < v->size) {
            v->size = newCapacity;
        }
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*) realloc(v->data, sizeof(v->data[0]) * v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        reserve(v, 2 * v->capacity);
    }
    if (v->data == NULL) {
        *v = createVector(1);
    }
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->size == 0) {
        errorMemory();
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }

    return &v->data[index];
}

int* back(vector *v) {
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    return v->data;
}