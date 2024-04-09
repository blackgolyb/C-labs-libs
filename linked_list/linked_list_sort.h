#ifndef LINKED_LIST_SORT_H_INCLUDED
#define LINKED_LIST_SORT_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

#include "utils.h"
#include "linked_list.h"

void ll_bubble_sort(List *list, CmpFun cmp, bool ascending);
void ll_quick_sort(List *list, CmpFun cmp, bool ascending);
void ll_marge_sort(List *list, CmpFun cmp, bool ascending);

#endif // LINKED_LIST_SORT_H_INCLUDED
