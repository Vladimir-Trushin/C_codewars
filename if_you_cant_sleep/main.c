/*
DESCRIPTION:
If you can't sleep, just count sheep!!

Task:
Given a non-negative integer, 3 for example,
return a string with a murmur: "1 sheep...2 sheep...3 sheep...".
Input will always be valid, i.e. no negative integers.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


size_t count_digit(int n);
char *count_sheep(int n);

int main()
{
    char *str1 = count_sheep(1);
    char *str2 = count_sheep(2);
    char *str3 = count_sheep(3);
    char *str4 = count_sheep(4);
    char *str5 = count_sheep(5);

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);
    printf("%s\n", str5);

    free(str1);
    free(str2);
    free(str3);
    free(str4);
    free(str5);

    return 0;
}

//----------------------------------------------------
size_t count_digit(int n)
{
    size_t count = 0;

    while (n)
    {
        n /= 10;
        count++;
    }

    return count;
}

//----------------------------------------------------
char *count_sheep(int n)
{
    char *sheep = " sheep...";
    char num_sheep[80] = { 0 };

    char *str = malloc((count_digit(n) + strlen(sheep)) * n * (sizeof(char)) + 1);
    if (!str)
    {
        printf("%s", "error, can't allocate memory\n");
        exit(1);
    }

    *str = '\0';

    for (size_t i = 1; i <= n; i++)
    {
        sprintf(num_sheep, "%zu%s", i, sheep);
        strcat(str, num_sheep);
    }

    return str;
}