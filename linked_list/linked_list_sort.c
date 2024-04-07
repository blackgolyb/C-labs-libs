#include "linked_list_sort.h"

void ll_bubble_sort(List *list, CmpFun cmp)
{
    int swapped;
    struct ListNode *i, *j;
    i = list->tail;

    while (i->prev)
    {
        j = list->head;
        swapped = 0;

        while (j != i)
        {
            if (cmp(j->data, j->next->data))
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

struct ListNode *__ll__partition(struct ListNode *l, struct ListNode *r, CmpFun cmp)
{
    struct ListNode *pivot = r;
    struct ListNode *i = NULL;
    struct ListNode *j = l;

    while (j != pivot)
    {
        if (cmp(j->data, pivot->data))
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

void __ll__ll_quick_sort_body(List *list, struct ListNode *l, struct ListNode *r, CmpFun cmp)
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

    struct ListNode *pivot = __ll__partition(l, r, cmp);

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
        __ll__ll_quick_sort_body(list, pivot->next, r, cmp);
    }

    if (pivot && pivot->prev && pivot != l)
    {
        // puts("l");
        __ll__ll_quick_sort_body(list, l, pivot->prev, cmp);
    }
}

void ll_quick_sort(List *list, CmpFun cmp)
{
    __ll__ll_quick_sort_body(list, list->head, list->tail, cmp);
}