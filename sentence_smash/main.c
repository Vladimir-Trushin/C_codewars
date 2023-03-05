

/*
Sentence Smash

Write a function that takes an array of words and smashes 
them together into a sentence and returns the sentence. 
You can ignore any need to sanitize words or add punctuation, 
but you should add spaces between each word. Be careful, 
there shouldn't be a space at the beginning or the end of the sentence!

Example

['hello', 'world', 'this', 'is', 'great']  =>  'hello world this is great'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *smash (const char *const words[], size_t nb_words);

int main()
{
  const char *const words1[] = {"hello", "world", "ok"};
  const char *const words2[] = {""};
  const char *const words3[] = {"home"};

  char *test1 = smash(words1, 3);
  char *test2 = smash(words2, 1);
  char *test3 = smash(words3, 1);

  printf("%s\n", test1);
  printf("%s\n", test2);
  printf("%s\n", test3);

  free(test1);
  free(test2);
  free(test3);

  return 0;
}



//------------------------------------------------------------------------------

char *smash (const char *const words[], size_t nb_words)
{ 
  size_t amount_char = 0;
  
  if (!words)
    return NULL;
  
  for (size_t i = 0; i < nb_words; i++) // counting amount of characters total
  {
      amount_char += strlen(words[i]);
  }
  
  if (nb_words)
    amount_char += (nb_words - 1); // add spaces
  
	char *string = (char*)calloc(amount_char + 1, sizeof(char)); // one fo null-terminated
  if (!string)
    return NULL;
  
  size_t n = 0;
  
  for (size_t i = 0; i < nb_words; i++)
  {
    char *word = (char*)words[i];
    
    while (*word)
    {
      string[n] = *word;
      
      n++;
      word++;
    }
    
    string[n] = ' ';
    n++;
  }
  
  if (n)
    string[n - 1] = '\0'; // change last space to null-terminated
  else
    *string = '\0'; // input don't have words or empty string
  
  return string;
}