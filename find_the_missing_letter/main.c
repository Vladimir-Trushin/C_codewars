/*
DESCRIPTION:
Find the missing letter
Write a method that takes an array 
of consecutive (increasing) letters 
as input and that returns the missing 
letter in the array.

You will always get an valid array. 
And it will be always exactly one letter be missing. 
The length of the array will always be at least 2.
The array will always contain letters in only one case.

Example:
['a','b','c','d','f'] -> 'e'
['O','Q','R','S'] -> 'P'
*/


#include <stddef.h>
#include <stdio.h>


char findMissingLetter(char array[], int arrayLength);

int main()
{
    char str1[] = {"abcfg"};  // d
    char str2[] = {"123467"}; // 5
    char str3[] = {"ACDFG"};  // B
    char str4[] = {"46789"};  // 5

    printf("%s -> %c\n", str1, findMissingLetter(str1, sizeof(str1)));
    printf("%s -> %c\n", str2, findMissingLetter(str2, sizeof(str2)));
    printf("%s -> %c\n", str3, findMissingLetter(str3, sizeof(str3)));
    printf("%s -> %c\n", str4, findMissingLetter(str4, sizeof(str4)));

    return 0;
}

char findMissingLetter(char array[], int arrayLength)
{
  for (size_t i = 0, len = (size_t)(arrayLength - 1); i < len; i++)
  {
    if (array[i + 1] - array[i] > 1)
      return (char)(array[i] + 1);
  }
}