/*
DESCRIPTION:
Write a function that takes an integer as input, 
and returns the number of bits that are equal to one 
in the binary representation of that number. 
You can guarantee that input is non-negative.

Example: 
The binary representation of 1234 is 10011010010, 
so the function should return 5 in this case
*/




#include <stddef.h>
#include <stdio.h>


size_t countBits(unsigned value);

int main()
{
    printf("number: %d => ones bits: %d\n", 1234, countBits(1234)); // 5
    printf("number: %d => ones bits: %d\n", 0xFF, countBits(0xFF)); // 8
    printf("number: %d => ones bits: %d\n", 0xF0, countBits(0xF0)); // 4
    printf("number: %d => ones bits: %d\n", 0x07, countBits(0x07)); // 3
    printf("number: %d => ones bits: %d\n", 0x77, countBits(0x77)); // 6


    return 0;
}


//---------------------------------------------------------------
size_t countBits(unsigned value)
{
  size_t count = 0;
  
  for (size_t i = 0; i < sizeof(unsigned) * 8; i++, value >>= 1)
  {
    if (value & 1u)
    {
      count++;
    }
  }
  
	return count;
}