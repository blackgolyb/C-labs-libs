#include "array_deque.h"

ADeque *adeque_create(int capacity)
{
    ADeque *deque = malloc(sizeof(ADeque));
    deque->capacity = capacity;
    deque->data = malloc(deque->capacity * sizeof(void *));
    deque->head = 0;
    deque->tail = 0;
    deque->size = 0;
}

void adeque_destroy(ADeque *deque)
{
    free(deque->data);
    free(deque);
}

void adeque_destroy_with_elems(ADeque *deque)
{
    while (!adeque_is_empty(deque))
        free(adeque_pop_back(deque));
    free(deque->data);
    free(deque);
}

void adeque_push_front(ADeque *deque, void *elem)
{
    deque->head = (deque->head + deque->capacity - 1) % deque->capacity;
    deque->data[deque->head] = elem;
    deque->size++;
}

void adeque_push_back(ADeque *deque, void *elem)
{
    deque->data[deque->tail] = elem;
    deque->tail = (deque->tail + 1) % deque->capacity;
    deque->size++;
}

void *adeque_pop_front(ADeque *deque)
{
    void *elem = deque->data[deque->head];
    deque->head = (deque->head + 1) % deque->capacity;
    deque->size--;
    return elem;
}

void *adeque_pop_back(ADeque *deque)
{
    deque->tail = (deque->tail + deque->capacity - 1) % deque->capacity;
    deque->size--;
    return deque->data[deque->tail];
}

void *adeque_head(ADeque *deque)
{
    return deque->data[deque->head];
}

void *adeque_tail(ADeque *deque)
{
    return deque->data[(deque->tail + deque->capacity - 1) % deque->capacity];
}

int adeque_size(ADeque *deque)
{
    return deque->size;
}

bool adeque_is_empty(ADeque *deque)
{
    return !deque->size;
}

void adeque_copy(ADeque *deque, ADeque *src)
{
    ADeque *tmp = adeque_create(src->capacity);
    adeque_change_capacity(deque, deque->capacity + src->capacity);
    int n = adeque_size(src);

    for (int i = 0; i < n; i++)
        adeque_push_back(tmp, adeque_pop_front(src));

    for (int i = 0; i < n; i++)
    {
        void *elem = adeque_pop_front(tmp);
        adeque_push_back(src, elem);
        adeque_push_back(deque, elem);
    }
}

void adeque_change_capacity(ADeque *deque, int new_capacity)
{
    int min_c = imin(deque->capacity, new_capacity);
    void **new_data = malloc(new_capacity * sizeof(void *));
    int size = deque->size;

    for (int i = 0; i < min_c; i++)
        new_data[i] = deque->data[(deque->head + i) % deque->capacity];

    free(deque->data);
    deque->data = new_data;
    deque->capacity = new_capacity;
    deque->size = imin(size, deque->capacity);
    deque->head = 0;
    deque->tail = deque->size;
}
