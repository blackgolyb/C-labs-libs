#ifndef LIST_STACK_H_INCLUDED
#define LIST_STACK_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <utils.h>

typedef struct LStackNode
{
    void *data;
    struct LStackNode *prev;
} LStackNode;

typedef struct LStack
{
    LStackNode *top;
} LStack;

LStack *lstack_create();
void lstack_destroy(LStack *stack);
void lstack_destroy_with_elems(LStack *stack);
void lstack_push(LStack *stack, void* elem);
void *lstack_pop(LStack *stack);
void *lstack_top(LStack *stack);
int lstack_size(LStack *stack);
bool lstack_is_empty(LStack *stack);
void lstack_repack(LStack *stack, LStack *src);
void lstack_copy(LStack *stack, LStack *src);

#endif