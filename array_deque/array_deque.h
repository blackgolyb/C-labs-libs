#ifndef ARRAY_DEQUE_H_INCLUDED
#define ARRAY_DEQUE_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"

typedef struct ADeque
{
    void **data;
    int head;
    int tail;
    int capacity;
    int size;
} ADeque;

ADeque *adeque_create(int capacity);
void adeque_destroy(ADeque *deque);
void adeque_destroy_with_elems(ADeque *deque);
void adeque_push_front(ADeque *deque, void* elem);
void *adeque_pop_front(ADeque *deque);
void adeque_push_back(ADeque *deque, void* elem);
void *adeque_pop_back(ADeque *deque);
void *adeque_head(ADeque *deque);
void *adeque_tail(ADeque *deque);
int adeque_size(ADeque *deque);
bool adeque_is_empty(ADeque *deque);
void adeque_copy(ADeque *deque, ADeque *src);
void adeque_change_capacity(ADeque *deque, int addition);

#endif