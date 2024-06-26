#include "linked_list.h"

List *ll_create()
{
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int ll_len(List *list)
{
    int len = 0;
    for (struct ListNode *node = list->head; node; node = node->next)
        len++;

    return len;
}

void ll_destroy(List *list)
{
    struct ListNode *tmp;
    for (struct ListNode *node = list->head; node;)
    {
        node->data = NULL;
        tmp = node->prev;
        free(node);
        node = tmp;
    }
    free(tmp);
    free(list);
}

void ll_clear(List *list)
{
    for (struct ListNode *node = list->head; node; node = node->next)
    {
        free(node->data);
        node->data = NULL;
    }
    list->head = NULL;
    list->tail = NULL;
}

void ll_push_back(List *list, void *elem)
{
    struct ListNode *last_node = list->tail;

    if (!last_node)
    {
        list->head = malloc(sizeof(struct ListNode));
        list->head->data = elem;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = list->head;
        return;
    }

    last_node->next = malloc(sizeof(struct ListNode));
    last_node->next->data = elem;
    last_node->next->next = NULL;
    last_node->next->prev = last_node;
    list->tail = last_node->next;
}

void *ll_get(List *list, int index)
{
    if (index >= 0)
    {
        int i = 0;
        struct ListNode *node = list->head;

        for (; node && (i != index); node = node->next)
            i++;

        if (!node)
            return NULL;

        return node->data;
    }
    else
    {
        int i = -1;
        struct ListNode *node = list->tail;

        for (; node && (i != index); node = node->prev)
            i--;

        if (!node)
            return NULL;

        return node->data;
    }
}

void *ll_pop(List *list, int index)
{
    int i = 0;
    struct ListNode *node = list->head;

    if (index < 0)
        index = ll_len(list) + index;

    for (; node && (i != index); node = node->next)
        i++;

    if (!node)
        return NULL;

    void *data = node->data;

    if (node->next)
        node->next->prev = node->prev;

    if (node->prev)
        node->prev->next = node->next;

    if (node == list->head)
        list->head = node->next;

    if (node == list->tail)
        list->tail = node->prev;

    free(node);

    return data;
}

void ll_insert(List *list, int index, void *elem)
{
    struct ListNode *node = list->head;
    if (index == 0)
    {
        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->data = elem;
        new_node->next = node;
        new_node->prev = NULL;
        list->head = new_node;
        node->prev = new_node;
        return;
    }

    int n = ll_len(list);
    if (index == n || index == -1)
    {
        ll_push_back(list, elem);
        return;
    }

    if (index < 0)
        index = n + index + 1;

    if (index > n)
        return;

    for (int i = 0; node && (i != index); i++)
        node = node->next;

    if (!node)
        return;

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = elem;
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev->next = new_node;
    node->prev = new_node;
}

void ll_set(List *list, int index, void *value)
{
    struct ListNode *node = list->head;
    for (int i = 0; node && (i != index); node = node->next)
        i++;

    if (!node)
        return;

    node->data = value;
}

List *ll_copy(List *list)
{
    List *new_list = ll_create();
    void *tmp;
    for (struct ListNode *node = list->head; node; node = node->next)
    {
        tmp = malloc(sizeof(void *));
        memcpy(tmp, node->data, sizeof(void *));
        ll_push_back(new_list, tmp);
    }

    return new_list;
}

List *ll_from_array(void **array, int n)
{
    List *list = ll_create();

    for (int i = 0; i < n; i++)
        ll_push_back(list, array[i]);
}

void ll_swap_data(struct ListNode *a, struct ListNode *b)
{
    void *tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

void ll_swap(List *list, struct ListNode *a, struct ListNode *b)
{
    // TODO: this

    // struct ListNode *tmp_next = a->next;
    // struct ListNode *tmp_prev = a->prev;

    // a->next->prev = b;
    // a->prev->next = b;


    // a->next = b->next;
    // a->prev = b->prev;

    // b->next = tmp_next;
    // b->prev = tmp_prev;


    // struct ListNode *tmp_head = list->head;
    // struct ListNode *tmp_tail = list->tail;

    // if (tmp_head == a)
    //     list->head = b;
    // else if (tmp_tail == a)
    //     list->tail = b;

    // if (tmp_head == b)
    //     list->head = a;
    // else if (tmp_tail == b)
    //     list->tail = a;
}