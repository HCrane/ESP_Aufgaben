//-----------------------------------------------------------------------------
// hw7.c
//
// Playing with recursion
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int fibo_nr);
void iterativeDivision(int divident, int divisor);

//-----------------------------------------------------------------------------
/// Main program that checks for errors in the cmd parameters
///
/// @param  argc argument count
/// @param  argv arguments in characters
///
/// @return      depending on errors
//-----------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
  int check;
  if (argc > 3)
  {
    printf("Wrong parameter count! 2 expected, %d given.\n", argc - 1);
    return -1;
  }
  else if (argc <= 2)
  {
    printf("Wrong parameter count! 2 expected, %d given.\n", argc - 1);
    return -1;
  }
  else
  {
    if (sscanf(argv[1], "%d", &check) && sscanf(argv[2], "%d", &check))
    {
      int first = atoi(argv[1]);
      int second = atoi(argv[2]);

      if (first <= 40 && first >= -40)
      {
        if (second <= 40 && second >= -40) {
          int return_first = fibonacci(first);
          int return_second = fibonacci(second);

          printf("Fibonacci[%d] = %d\n",first, return_first);
          printf("Fibonacci[%d] = %d\n",second, return_second);
        }
        else{
          int return_first = fibonacci(first);
          printf("Fibonacci[%d] = %d\n",first, return_first);
        }
      }
      else
      {
        if (second <= 40 && second >= -40) {
          int return_second = fibonacci(second);
          printf("Fibonacci[%d] = %d\n",second, return_second);
        }
      }
      iterativeDivision(first, second);
    }
    else
    {
      printf("Wrong parameter type! Expected type is int.\n");
    }
  }

  return 0;
}

//-----------------------------------------------------------------------------
///
/// Function computes a division and remainder without using the
/// devision and modulo operator and prints the result
///
/// @param divident the divident
/// @param divisor  the divisor
///
/// @return none because of void
//-----------------------------------------------------------------------------
void iterativeDivision(int divident, int divisor)
{
  int division_result = 0;
  int rest = divident;

  if (rest != 0) {
    while (rest >= divisor)
    {
      rest -= divisor;
      division_result++;
    }
  }
  else
  {
    division_result = 0;
  }

  printf("Integer division: %d / %d = %d\n",
          divident, divisor, division_result);
  printf("Remainder = %d\n", rest);
}

//-----------------------------------------------------------------------------
///
/// Fibonacci Function
/// Function computes fibonacci number of given positive / negative input
///
/// @param int starting number for fibonacci computation
///
/// @return int final fibonacci number
///
//-----------------------------------------------------------------------------
int fibonacci(int fibo_nr)
{
  if (fibo_nr >= 0)
  {
    if (fibo_nr <= 2)
    {
      return 1;
    }
    else
    {
      return (fibonacci(fibo_nr - 1) + fibonacci(fibo_nr - 2));
    }
  }
  else
  {
    return ((-1)^(fibo_nr + 1)) * fibonacci((-1)*fibo_nr);
  }
}
