#include "queue.h"

Queue *queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void queue_destroy(Queue *queue)
{
    while (queue->head != NULL)
        queue_remove(queue);
    free(queue);
}

void queue_destroy_with_elems(Queue *queue)
{
    while (queue->head != NULL)
        free(queue_remove(queue));
    free(queue);
}

void queue_insert(Queue *queue, void* elem)
{
    QueueNode *node = malloc(sizeof(QueueNode));
    node->data = elem;
    node->next = NULL;
    if (queue->tail)
        queue->tail->next = node;

    queue->tail = node;

    if (queue->head == NULL)
        queue->head = node;
}

void *queue_remove(Queue *queue){
    QueueNode *node = queue->head;
    void *data = node->data;
    queue->head = node->next;

    if (queue->tail == node)
        queue->tail = NULL;

    free(node);
    return data;
}

int queue_size(Queue *queue)
{
    int size = 0;
    for (QueueNode *node = queue->head; node; node = node->next)
        size++;

    return size;
}

bool queue_is_empty(Queue *queue)
{
    return !queue->head;
}

void queue_copy(Queue *stack, Queue *src)
{
    Queue *tmp = queue_create();
    while (!queue_is_empty(src))
        queue_insert(tmp, queue_remove(src));

    while (!queue_is_empty(tmp))
    {
        void *elem = queue_remove(tmp);
        queue_insert(stack, elem);
        queue_insert(src, elem);
    }
    queue_destroy(tmp);
}
