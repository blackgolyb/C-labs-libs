#include "utils.h"

int random_number(int start, int stop)
{
    return (rand() % (stop - start + 1)) + start;
}

char *generate_name(int len)
{
    char *res = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
    {
        res[i] = random_number('a', 'z');
    }
    res[len] = '\0';

    return res;
}

int imax(int a, int b)
{
    return (a > b)? a : b;
}
int imin(int a, int b)
{
    return (a > b)? b : a;
}


char *int_to_string(int value)
{
    int len = 1;
    int temp = value;

    // Calculate the length of the integer
    while (temp >= 10)
    {
        temp /= 10;
        len++;
    }

    // Allocate memory for the string
    char *str = (char *)malloc((len + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Convert the int to a wide string
    sprintf(str, "%d", value);
    str[len] = '\0';

    return str;
}