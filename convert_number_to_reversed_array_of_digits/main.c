/*
DESCRIPTION:
Convert number to reversed array of digits
Given a random non-negative number,
you have to return the digits of
this number within an array in reverse order.

Example(Input => Output):
35231 => [1,3,2,5,3]
0 => [0]
*/

#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>


void digitize(uint64_t n, uint8_t digits[], size_t *length_out);
void test_print(uint8_t digits[], size_t length);

int main()
{
    uint8_t digits[80] = {0};
    size_t length = 0;

    digitize(12345, digits, &length);
    test_print(digits, length);

    digitize(98765, digits, &length);
    test_print(digits, length);

    digitize(2468, digits, &length);
    test_print(digits, length);

    digitize(1092837, digits, &length);
    test_print(digits, length);

    digitize(567438, digits, &length);
    test_print(digits, length);


    return 0;
}

//----------------------------------------------------
void digitize(uint64_t n, uint8_t digits[], size_t *length_out)
{
    if (!n)
    {
        digits[0] = n;
        *length_out = 1;

        return;
    }

    *length_out = 0;

    while (n)
    {
        digits[*length_out] = n % 10;
        (*length_out)++;
        n /= 10;
    }
}

//----------------------------------------------------
void test_print(uint8_t digits[], size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("%d", digits[i]);
    }

    printf("\n");
}