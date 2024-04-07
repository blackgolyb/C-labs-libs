#include "list_stack.h"

LStack *lstack_create()
{
    LStack *stack = malloc(sizeof(LStack));
    stack->top = NULL;

    return stack;
}

void lstack_destroy(LStack *stack)
{
    while (stack->top != NULL)
        lstack_pop(stack);
    free(stack);
}

void lstack_destroy_with_elems(LStack *stack)
{
    while (stack->top != NULL)
        free(lstack_pop(stack));
    free(stack);
}

void lstack_push(LStack *stack, void *elem)
{
    LStackNode *node = malloc(sizeof(LStackNode));
    node->data = elem;
    node->prev = stack->top;
    stack->top = node;
}

void *lstack_pop(LStack *stack)
{
    if (!stack->top)
        return NULL;
    LStackNode *node = stack->top;
    void *elem = node->data;
    stack->top = node->prev;
    free(node);
    return elem;
}

void *lstack_top(LStack *stack)
{
    if (!stack->top)
        return NULL;
    return stack->top->data;
}

int lstack_size(LStack *stack)
{
    int size = 0;
    for (LStackNode *node = stack->top; node != NULL; node = node->prev)
        size++;

    return size;
}

bool lstack_is_empty(LStack *stack)
{
    return !stack->top;
}

void lstack_repack(LStack *stack, LStack *src)
{
    while (!lstack_is_empty(src))
        lstack_push(stack, lstack_pop(src));
}

void lstack_copy(LStack *stack, LStack *src)
{
    LStack *tmp = lstack_create();
    lstack_repack(tmp, src);
    while (!lstack_is_empty(tmp))
    {
        void *p = lstack_pop(tmp);
        lstack_push(stack, p);
        lstack_push(src, p);
    }
    lstack_destroy(tmp);
}