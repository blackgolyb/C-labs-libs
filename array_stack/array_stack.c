#include "array_stack.h"

AStack *astack_create()
{
    AStack *stack = malloc(sizeof(AStack));
    stack->capacity = 16;
    stack->top = -1;
    stack->data = malloc(sizeof(void *) * stack->capacity);

    return stack;
}

void astack_destroy(AStack *stack)
{
    free(stack->data);
    free(stack);
}

void astack_destroy_with_elems(AStack *stack)
{
    while (!astack_is_empty(stack))
        free(astack_pop(stack));

    astack_destroy(stack);
}

void astack_push(AStack *stack, void *elem)
{
    // printf("%d %d\n", stack->top+1, *(int *)elem);
    if (stack->top + 1 >= stack->capacity)
    {
        stack->capacity *= 2;
        stack->data=realloc(stack->data, stack->capacity * sizeof(void *));
    }

    stack->top++;
    stack->data[stack->top] = elem;
}

void *astack_pop(AStack *stack)
{
    if (stack->top < 0)
        return NULL;
    void *elem = stack->data[stack->top];
    stack->top--;
    return elem;
}

void *astack_top(AStack *stack)
{
    if (stack->top < 0)
        return NULL;
    return stack->data[stack->top];
}

int astack_size(AStack *stack)
{
    return stack->top + 1;
}

bool astack_is_empty(AStack *stack)
{
    return stack->top < 0;
}

void astack_repack(AStack *stack, AStack *src)
{
    while (!astack_is_empty(src))
        astack_push(stack, astack_pop(src));
}

void astack_copy(AStack *stack, AStack *src)
{
    AStack *tmp = astack_create();
    astack_repack(tmp, src);
    while (!astack_is_empty(tmp))
    {
        void *p = astack_pop(tmp);
        astack_push(stack, p);
        astack_push(src, p);
    }
    astack_destroy(tmp);
}