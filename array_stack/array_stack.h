#ifndef ARRAY_STACK_H_INCLUDED
#define ARRAY_STACK_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <utils.h>

typedef struct AStack
{
    void **data;
    int top;
    int capacity;
} AStack;

AStack *astack_create();
void astack_destroy(AStack *stack);
void astack_destroy_with_elems(AStack *stack);
void astack_push(AStack *stack, void* elem);
void *astack_pop(AStack *stack);
void *astack_top(AStack *stack);
int astack_size(AStack *stack);
bool astack_is_empty(AStack *stack);
void astack_repack(AStack *stack, AStack *src);
void astack_copy(AStack *stack, AStack *src);

#endif