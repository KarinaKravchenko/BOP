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

// возвращает "истина", если структура вектор v не содержит
// элементы, иначе - "ложь"
bool isEmpty(vector *v);

// возвращает "истина", если структура вектор v содержит
// максимальное количенство элементов, иначе - "ложь"
bool isFull(vector *v);

// возвращает элемент с индексом i структуры вектор v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец структуры вектор v
void pushBack(vector *v, int x);

// удоляет последний элемент структуры вектор v
void popBack(vector *v);

// возврящает указатель на элемент с индексом index структуры вектор v
int* atVector(vector *v, size_t index);

// возврящает указатель на последний элемент структуры вектор v
int* back(vector *v);

// возврящает указатель на первый элемент структуры вектор v
int* front(vector *v);

#endif //BPROGRAMMING_VECTOR_H
