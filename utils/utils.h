#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    ({                                                  \
        lambda$_ret lambda$__anon$ lambda$_args         \
            lambda$_body                                \
                &lambda$__anon$;                        \
    })

/**
 * @brief  compare function for your type of elements
 * @return  -1 if first less than second element 1 if greater and 0 if equal
 * 
 */
typedef int (* CmpFun)(void *a, void *b);

int random_number(int start, int stop);
char *generate_name(int len);
int imax(int a, int b);
int imin(int a, int b);
char *int_to_string(int value);

#endif // UTILS_H_INCLUDED