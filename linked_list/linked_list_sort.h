#ifndef LINKED_LIST_SORT_H_INCLUDED
#define LINKED_LIST_SORT_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"
#include "linked_list.h"

void ll_bubble_sort(List *list, CmpFun cmp);

#endif // LINKED_LIST_SORT_H_INCLUDED
