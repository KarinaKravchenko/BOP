#ifndef BPROGRAMMING_VECTOR_H
#define BPROGRAMMING_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;       // указатель на элементы вектора
    size_t size;     // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру вектор длинны n
vector createVector(size_t n);

// изменяет количество выделенной памяти на newCapacity
// структуре вектор v
void reserve(vector *v, size_t newCapacity);

// удаляет все элементы из структуры вектор v, но не
// освобождает выделенную память
void clear(vector *v);

// освобождает неиспользуюмую память, выделенную структуре
// вектор v
void shrinkToFit(vector *v);

// освобождает память, выделенную структуре вектор v
void deleteVector(vector *v);

#endif //BPROGRAMMING_VECTOR_H
