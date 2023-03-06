/*
Convert a String to a Number

Description
We need a function that can transform a string into a number. What ways of achieving this do you know?
Note: Don't worry, all inputs will be strings, and every string is a perfectly valid representation of an integral number.

Examples
"1234" --> 1234
"605"  --> 605
"1405" --> 1405
"-7" --> -7
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int string_to_number(const char *src);

int main()
{
    printf("%d\n", string_to_number("1234"));
    printf("%d\n", string_to_number("-32"));
    printf("%d\n", string_to_number("1987654"));
    printf("%d\n", string_to_number("-23872"));
    printf("%d\n", string_to_number("0"));
    printf("%d\n", string_to_number(""));

    return 0;
}


////-------------------------------------------------------
//
int string_to_number(const char *src)
{
    if (!src || !src[0])
        return 0;

    int k = 1;
    int num = 0;

    for (size_t i = strlen(src) - 1; i != 0; i--)
    {
        num += (src[i] - '0') * k;
        k *= 10;
    }

    if (src[0] == '-')
        num = -num;
    else
        num += (src[0] - '0') * k;

    return num;
}
