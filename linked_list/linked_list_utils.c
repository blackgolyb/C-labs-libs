#include "linked_list_utils.h"

void __ll__printf_void_pointer(void *ptr, char *type)
{
    if (ptr == NULL)
        printf("NULL\n");
    else
    {
        if (!strcasecmp(type, "int"))
            printf("%d", *(int *)ptr);
        else if (!strcasecmp(type, "char"))
            printf("%c", *(char *)ptr);
        else if (!strcasecmp(type, "float"))
            printf("%f", *(float *)ptr);
        else if (!strcasecmp(type, "double"))
            printf("%lf", *(double *)ptr);
        else if (!strcasecmp(type, "string") || !strcasecmp(type, "str"))
            printf("%s", *(char *)ptr);
        else if (!strcasecmp(type, "pointer") || !strcasecmp(type, "ptr"))
            printf("%p", ptr);
        else if (!strcasecmp(type, "bool"))
            printf("%s", *(bool *)ptr ? "true" : "false");
    }
}

void ll_print(List *list, char *type, char *sep, char *end)
{
    if (list == NULL)
        return;

    struct ListNode *node = list->head;
    while (node != NULL)
    {
        __ll__printf_void_pointer(node->data, type);
        printf(sep);
        node = node->next;
    }
    printf(end);
}

int __ll__random_number(int start, int stop)
{
    return (rand() % (stop - start + 1)) + start;
}

void ll_fill_int_random(List *list, int n, int a, int b)
{
    ll_clear(list);

    for (int i = 0; i < n; i++)
    {
        int *value = malloc(sizeof(int));
        *value = __ll__random_number(a, b);
        ll_push_back(list, value);
    }
}