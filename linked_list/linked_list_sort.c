#include "linked_list_sort.h"

void ll_bubble_sort(List *list, CmpFun cmp, bool ascending)
{
    int swapped;
    struct ListNode *i, *j;
    i = list->tail;

    int cmp_param = ascending ? 1 : -1;

    while (i->prev)
    {
        j = list->head;
        swapped = 0;

        while (j != i)
        {
            if (cmp(j->data, j->next->data) == cmp_param)
            {
                ll_swap_data(j, j->next);
                swapped = 1;
            }
            j = j->next;
        }

        i = i->prev;

        if (swapped == 0)
            break;
    }
}

struct ListNode *__ll__partition(struct ListNode *l, struct ListNode *r, CmpFun cmp, bool ascending)
{
    struct ListNode *pivot = r;
    struct ListNode *i = NULL;
    struct ListNode *j = l;

    int cmp_param = ascending ? -1 : 1;

    while (j != pivot)
    {
        if (cmp(j->data, pivot->data) == cmp_param)
        {
            if (i)
                i = i->next;
            else
                i = l;
            ll_swap_data(i, j);
        }
        j = j->next;
    }

    if (i)
        i = i->next;
    else
        i = l;
    ll_swap_data(i, j);
    return i;
}

void __ll__ll_quick_sort_body(List *list, struct ListNode *l, struct ListNode *r, CmpFun cmp, bool ascending)
{
    if (l == r || !l || !r)
    {
        return;
    }

    // printf("l: %d  r: %d\n", *(int *)l->data, *(int *)r->data);
    // struct ListNode *t = list->head;
    // while(t != NULL)
    // {
    //     if (t == l)
    //         printf("\033[31m");
    //     printf("%d ", *(int *)t->data);
    //     if (t == r)
    //         printf("\033[0m");
    //     t = t->next;
    // };
    // putchar('\n');

    struct ListNode *pivot = __ll__partition(l, r, cmp, ascending);

    // printf("pivot: %d\n", *(int *)pivot->data);

    // t = list->head;
    // while(t != NULL)
    // {
    //     if (t == l)
    //         printf("\033[31m");
    //     printf("%d ", *(int *)t->data);
    //     if (t == r)
    //         printf("\033[0m");
    //     t = t->next;
    // };
    // putchar('\n');
    // putchar('\n');

    if (pivot && pivot->next && pivot != r)
    {
        // puts("r");
        __ll__ll_quick_sort_body(list, pivot->next, r, cmp, ascending);
    }

    if (pivot && pivot->prev && pivot != l)
    {
        // puts("l");
        __ll__ll_quick_sort_body(list, l, pivot->prev, cmp, ascending);
    }
}

void ll_quick_sort(List *list, CmpFun cmp, bool ascending)
{
    __ll__ll_quick_sort_body(list, list->head, list->tail, cmp, ascending);
}

struct ListNode *__ll__split(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct ListNode *__ll__merge(struct ListNode *first, struct ListNode *second, CmpFun cmp, bool ascending)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    int cmp_param = ascending ? -1 : 1;

    // Pick the smaller value
    if (cmp(first->data, second->data) == cmp_param)
    {
        first->next = __ll__merge(first->next, second, cmp, ascending);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = __ll__merge(first, second->next, cmp, ascending);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

struct ListNode *__ll__ll_marge_sort_body(struct ListNode *node, CmpFun cmp, bool ascending)
{
    if (!node || !node->next)
        return node;
    struct ListNode *second = __ll__split(node);

    // Recur for left and right halves
    node = __ll__ll_marge_sort_body(node, cmp, ascending);
    second = __ll__ll_marge_sort_body(second, cmp, ascending);

    // Merge the two sorted halves
    return __ll__merge(node, second, cmp, ascending);
}

void ll_marge_sort(List *list, CmpFun cmp, bool ascending)
{
    list->head = __ll__ll_marge_sort_body(list->head, cmp, ascending);
    for (list->tail = list->head; list->tail->next; list->tail = list->tail->next);
}