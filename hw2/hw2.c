//------------------------------------------------------------------------------
// hw2.c
//
// Arithmetical Operators
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//
//------------------------------------------------------------------------------

#include <stdio.h>

int main() {
  int last_digit = 3;
  int sum = 1 + 4 + 3;
  int product = 0 * 6 * 8;

  int diff = ++product - sum++;
  int result = sum * diff;

  ++last_digit;
  int divison = result / last_digit;
  int remain = result % last_digit;


  printf("Result = %d\n", result);
  printf("Integer division = %d\n", divison);
  printf("Remainder = %d\n", remain);
  printf("Division = %.2f\n", (float)(result / (float)last_digit));
  return 0;
}
