//------------------------------------------------------------------------------
// hw3.c
//
// Overflow Errors
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//------------------------------------------------------------------------------
//

#include <limits.h>
#include <stdio.h>


// signed int = int;
// because of history

int main()
{
  int matr = 1430683;
  int i = 0;
  int overf = 0;

  //startet teil1 mit *
  for (i = 2; i < 10; (i++))
  {
    //checkt auf overflowerror
    if ((INT_MAX / i) < matr)
    {
      printf("%10d * %d \n", matr,i);
      printf("An overflow has occurred!\n");
      overf = 1;
      break;
    }
    else
    {
      printf("%10d * %d \n", matr,i);
      matr = matr * i;
    }
  }

  //divisionsausgabe
  for (i = 2; i < 10; (i++))
  {
    if (!overf)
    {
      printf("%10d : %d \n", matr,i);
      matr = matr / i;
    }
  }
  return 0;
}
