#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

char chose_one_option_input(char *chooses, char *prompt);
void input_float(float *value_ptr, char *prompt);
void input_double(double *value_ptr, char *prompt);
void input_int(int *value_ptr, char *prompt);
void input_char(char *value_ptr, char *prompt);
void input_string(char **value_ptr, char *prompt);

#define input1(value_ptr) _Generic((value_ptr), \
    int *: input_int,                           \
    char *: input_char,                         \
    float *: input_float,                       \
    char **: input_string,                      \
    double *: input_double)(value_ptr, "")

#define input2(value_ptr, prompt) _Generic((value_ptr), \
    int *: input_int,                                       \
    char *: input_char,                                     \
    float *: input_float,                                   \
    char **: input_string,                                  \
    double *: input_double)(value_ptr, prompt)

#define NARGS(...) NARGS_(__VA_ARGS__, 5, 4, 3, 2, 1, 0)
#define NARGS_(_5, _4, _3, _2, _1, N, ...) N

#define CONC(A, B) CONC_(A, B)
#define CONC_(A, B) A##B

#define input(...) CONC(input, NARGS(__VA_ARGS__))(__VA_ARGS__)

#endif // INPUT_H_INCLUDED
