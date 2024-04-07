#include "ldeque.h"

LDeque *ldeque_create()
{
    LDeque *deque = malloc(sizeof(LDeque));
    deque->head = NULL;
    deque->tail = NULL;

    return deque;
}

void ldeque_destroy(LDeque *deque)
{
    while (!ldeque_is_empty(deque))
        ldeque_pop_back(deque);

    free(deque);
}

void ldeque_destroy_with_elems(LDeque *deque)
{
    while (!ldeque_is_empty(deque))
        free(ldeque_pop_back(deque));

    free(deque);
}
void ldeque_push_front(LDeque *deque, void *elem)
{
    LDequeNode *node = malloc(sizeof(LDeque));
    node->data = elem;
    node->next = deque->head;
    node->prev = NULL;

    if (deque->head)
        deque->head->prev = node;

    deque->head = node;

    if (deque->tail == NULL)
        deque->tail = node;
}

void *ldeque_pop_front(LDeque *deque)
{
    LDequeNode *node = deque->head;
    if (node == NULL)
        return NULL;

    void *data = node->data;
    deque->head = node->next;

    if (deque->tail == node)
        deque->tail = NULL;
    else
        node->next->prev = NULL;

    free(node);
    return data;
}

void ldeque_push_back(LDeque *deque, void *elem)
{
    LDequeNode *node = malloc(sizeof(LDeque));
    node->data = elem;
    node->next = NULL;
    node->prev = deque->tail;

    if (deque->tail)
        deque->tail->next = node;

    deque->tail = node;

    if (deque->head == NULL)
        deque->head = node;
}

void *ldeque_pop_back(LDeque *deque)
{
    LDequeNode *node = deque->tail;
    if (node == NULL)
        return NULL;

    void *data = node->data;
    deque->tail = node->prev;

    if (deque->head == node)
        deque->head = NULL;
    else
        node->prev->next = NULL;

    free(node);
    return data;
}

int ldeque_size(LDeque *deque)
{
    int size = 0;
    for (LDequeNode *node = deque->head; node; node = node->next)
        size++;

    return size;
}

bool ldeque_is_empty(LDeque *deque)
{
    return deque->head == NULL;
}

void ldeque_copy(LDeque *deque, LDeque *src)
{
    LDeque *tmp = ldeque_create();
    while (!ldeque_is_empty(src))
        ldeque_push_back(tmp, ldeque_pop_front(src));

    while (!ldeque_is_empty(tmp))
    {
        void *elem = ldeque_pop_front(tmp);
        ldeque_push_back(deque, elem);
        ldeque_push_back(src, elem);
    }
    ldeque_destroy(tmp);
}

void ldeque_swap(LDeque *deque, void *elem1, void *elem2, CmpFun cmp)
{
    LDequeNode *n1 = NULL;
    LDequeNode *n2 = NULL;
    LDequeNode *node = deque->head;

    while ((!n1 || !n2) && node)
    {
        if (cmp(node->data, elem1) == 0)
            n1 = node;
        if (cmp(node->data, elem2) == 0)
            n2 = node;

        node = node->next;
    }

    if (n1 && n2)
    {
        void *tmp = n1->data;
        n1->data = n2->data;
        n2->data = tmp;
    }
}
