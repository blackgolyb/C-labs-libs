#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string.h>
#include <stdio.h>

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    ({                                                  \
        lambda$_ret lambda$__anon$ lambda$_args         \
            lambda$_body                                \
                &lambda$__anon$;                        \
    })

int random_number(int start, int stop);
char *generate_name(int len);
int imax(int a, int b);
char *int_to_string(int value);

#endif // UTILS_H_INCLUDED