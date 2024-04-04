#ifndef LINKED_LIST_UTILS_H_INCLUDED
#define LINKED_LIST_UTILS_H_INCLUDED


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

void ll_print(List *list, char *type, char *sep, char *end);
void ll_fill_int_random(List *list, int n, int a, int b);


#endif // LINKED_LIST_UTILS_H_INCLUDED
