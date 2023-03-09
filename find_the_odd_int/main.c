/*
DESCRIPTION:
Given an array of integers, find the
one that appears an odd number of times.

There will always be only one integer
that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/



#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


int find_odd(size_t length, const int array[length]);

int main()
{
    int test1[] = { 7 };                                     // 7
    int test2[] = { 0 };                                     // 0
    int test3[] = { 1, 1, 2 };                               // 2
    int test4[] = { 0, 1, 0, 1, 0 };                         // 0
    int test5[] = { 1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1 }; // 4

    printf("%d\n", find_odd(sizeof(test1) / sizeof(int), test1));
    printf("%d\n", find_odd(sizeof(test2) / sizeof(int), test2));
    printf("%d\n", find_odd(sizeof(test3) / sizeof(int), test3));
    printf("%d\n", find_odd(sizeof(test4) / sizeof(int), test4));
    printf("%d\n", find_odd(sizeof(test5) / sizeof(int), test5));
    

    return 0;
}


//----------------------------------------------------------
int find_odd(size_t length, const int array[length])
{
    if (length == 1)
        return *array;

    bool *flags = malloc(length * sizeof(bool));
    if (!flags)
    {
        printf("%s", "error, cannot allocate memory\n");
        exit(1);
    }

    for (size_t i = 0; i < length; i++)
    {
        flags[i] = 1;
    }

    size_t count;

    for (size_t i = 0; i < length; i++)
    {
        if (flags[i])
        {
            count = 0;

            for (size_t k = 0; k < length; k++)
            {
                if (array[i] == array[k])
                {
                    count++;
                    flags[k] = 0;
                }
            }

            if (count % 2)
            {
                free(flags);
                return array[i];
            }

        }
    }
}