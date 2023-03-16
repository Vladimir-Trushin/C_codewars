/*
DESCRIPTION:
Check to see if a string has the same 
amount of 'x's and 'o's. The method 
must return a boolean and be case insensitive. 
The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' 
                         is present should return true
XO("zzoo") => false
*/

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


bool xo(const char* str);

int main()
{
    printf("%s\n", xo("xo") ? "true" : "false");      // true
    printf("%s\n", xo("xooxx") ? "true" : "false");   // false
    printf("%s\n", xo("ooxXm") ? "true" : "false");   // true
    printf("%s\n", xo("zpzpzpp") ? "true" : "false"); // true
    printf("%s\n", xo("xoXXOo") ? "true" : "false");  // true


    return 0;
}

//----------------------------------------------------
bool xo(const char* str)
{
  int count = 0;
  
  while (*str)
  {
    if (tolower(*str) == 'x')
    {
      count++;
    }
    
    if (tolower(*str) == 'o')
    {
      count--;
    }
    
    str++;
  }
  
  return !count;
}