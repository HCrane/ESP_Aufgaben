//------------------------------------------------------------------------------
// hw6.c
//
// reading from file and return gibberish
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


int main()
{
  int max = 100;
  char *text = malloc(max * sizeof(char));

  if(!text)
  {
    printf("Error, out of memory!");
    return 1;
  }

  char *current_char = text;
  int char_counter = 0;
  char c;

  //einlesen
  while((c = getc(stdin)) != EOF)
  {
    if(char_counter >= max)
    {
      text = realloc(text, (max += 100));
      current_char = text + char_counter;
      if(!text)
      {
        printf("Error, out of memory!");
        return 1;
      }
    }
    *(current_char++) = c;
    char_counter++;
  }

//ausgabe rückwerts
  while(--current_char >= text)
  {
    putc(*current_char, stdout);
  }
  putc('\n',stdout);
  free(text);
  return 0;
}
