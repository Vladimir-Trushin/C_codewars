/*
DESCRIPTION:
Complete the solution so that it returns true
if the first argument(string) passed in ends
with the 2nd argument (also a string).

Examples:
solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false
*/

#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>


bool solution(const char *string, const char *ending);

int main()
{
    printf("%s\n", solution("hello world", "world") ? "true" : "false"); // true
    printf("%s\n", solution("hello world", "wold") ? "true" : "false");  // false
    printf("%s\n", solution("hello world", "orld") ? "true" : "false");  // true
    printf("%s\n", solution("hello world", "worl") ? "true" : "false");  // false
    printf("%s\n", solution("hello world", "ld") ? "true" : "false");    // true


    return 0;
}

//----------------------------------------------------
bool solution(const char *string, const char *ending)
{
    bool ret = true;
    size_t len_str = strlen(string);
    size_t len_end = strlen(ending);

    if (len_str < len_end)
        return false;

    for (;len_end; len_end--, len_str--)
    {
        if (string[len_str - 1] != ending[len_end - 1])
        {
            ret = false;
            break;
        }
    }
    return ret;
}