#include <stdio.h>
#include <ctype.h>

int countVowels (char str[])
{
  /* Implement this method.  
     The method should return the number of vowels in the string "str". */
  int i;
  int vowels = 0;
  char c;

  while (str[i] != '\0') {
    c = toupper (str[i]);
    
    if ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
      vowels++;

    i++;
  }
  return vowels;

  
  
  return 0;
}

int main ()
{
  if (countVowels ("Hello, how are you?") == 7)
    printf ("Passed 1\n");
  else
    printf ("Failed 1\n");

  if (countVowels ("AEIOUaeioubcDF?") == 10)
    printf ("Passed 2\n");
  else
    printf ("Failed 2\n");

  if (countVowels ("qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKL") == 0)
    printf ("Passed 3\n");
  else
    printf ("Failed 3\n");

  if (countVowels ("") == 0)
    printf ("Passed 4\n");
  else
    printf ("Failed 4\n");
}
  
  
  
