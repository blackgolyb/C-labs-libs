#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <utils.h>

typedef struct QueueNode
{
    void *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

Queue *queue_create();
void queue_destroy(Queue *stack);
void queue_destroy_with_elems(Queue *stack);
void queue_insert(Queue *stack, void* elem);
void *queue_remove(Queue *stack);
int queue_size(Queue *stack);
bool queue_is_empty(Queue *stack);
void queue_copy(Queue *stack, Queue *src);

#endif