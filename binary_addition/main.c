/*
DESCRIPTION:

Implement a function that adds two positives numbers together
and returns their sum in binary. The conversion can
be done before, or after the addition.

The binary number returned should be a string.

Examples:(Input1, Input2 --> Output (explanation)))

1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

char *binary_add(unsigned a, unsigned b, char *binary);

int main()
{
    char buff[65] = {0};

    printf("%s\n", binary_add(1, 1, buff));
    printf("%s\n", binary_add(3, 4, buff));
    printf("%s\n", binary_add(1000000, 1, buff));
    printf("%s\n", binary_add(32, 64, buff));
    printf("%s\n", binary_add(1000000000, 1, buff));

    return 0;
}

////---------------------------------------------------------------------
//
char *binary_add(unsigned a, unsigned b, char *binary)
{
    bool button = false;
    size_t k = 0;
    unsigned long long mask = 0;

    unsigned long long sum = (unsigned long long)a + (unsigned long long)b; // to avoid overflow

    if (!sum)
    {
        binary[0] = '0';
        binary[1] = '\0';

        return binary;
    }

    for (size_t i = sizeof(unsigned long long) * 8; i != 0; i--)
    {
        mask = 1ull << (i - 1);

        if (sum & mask || button)
        {
            button = true; // first enters with bit one

            if (sum & mask)
                binary[k] = '1';
            else
                binary[k] = '0';

            k++;
        }
    }

    binary[k] = '\0';

    return binary;
}