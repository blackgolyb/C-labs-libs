#ifndef LDEQUE_H_INCLUDED
#define LDEQUE_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"

typedef struct LDequeNode
{
    void *data;
    struct LDequeNode *next;
    struct LDequeNode *prev;
} LDequeNode;

typedef struct LDeque
{
    LDequeNode *head;
    LDequeNode *tail;
} LDeque;

LDeque *ldeque_create();
void ldeque_destroy(LDeque *deque);
void ldeque_destroy_with_elems(LDeque *deque);
void ldeque_push_front(LDeque *deque, void* elem);
void *ldeque_pop_front(LDeque *deque);
void ldeque_push_back(LDeque *deque, void* elem);
void *ldeque_pop_back(LDeque *deque);
int ldeque_size(LDeque *deque);
bool ldeque_is_empty(LDeque *deque);
void ldeque_copy(LDeque *deque, LDeque *src);
void ldeque_swap(LDeque *deque, void *elem1, void *elem2, CmpFun cmp);

#endif