//----------------------------------------------------------------------------
// hw9.c
//
// command line parsing fun
//
// Group: 3 study assistant Lorenz Kofler
//
// Authors: Emanuel Moser 1430683
//
// Latest Changes: 07.11.2016 (by Emanuel Moser)
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUP_CMD 1
#define HALVE_CMD 2

#define ADD_CMD 3
#define SUB_CMD 4
#define MUL_CMD 5
#define DIV_CMD 6

#define ERROR -1

void checkParser(int argc, char* command);
int commandHandler(char* command);
void dup(double nbr);
void halve(double nbr);
void add(double first, double second);
void sub(double first, double second);
void mul(double first, double second);
void divi(double first, double second);

//----------------------------------------------------------------------------
// Main function
// handles count of inputs and checks if they are correct
// and delegates the rest
//
// @param  argc argument count
// @param  argv arguments
// @return      depending on errors
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  if (argc == 3) {
    char* errorFirst;
    double first = strtod(argv[1], &errorFirst);
    if (!*errorFirst)
    {
      switch (commandHandler(argv[2]))
      {
        case DUP_CMD:
          dup(first);
          return 0;

        case HALVE_CMD:
          halve(first);
          return 0;

        default:
          printf("Error\n");
          return ERROR;
      }
    }
    else
    {
      printf("Error\n");
      return ERROR;
    }
  }
  else if (argc == 4)
  {
    char* errorFirst;
    char* errorSecond;
    double first = strtod(argv[1], &errorFirst);
    double second = strtod(argv[3], &errorSecond);
    if (!*errorFirst && !*errorSecond)
    {
      switch (commandHandler(argv[2]))
      {
        case ADD_CMD:
          add(first, second);
          return 0;

        case SUB_CMD:
          sub(first, second);
          return 0;

        case MUL_CMD:
          mul(first, second);
          return 0;

        case DIV_CMD:
          divi(first, second);
          return 0;

        default:
          printf("Error\n");
          return ERROR;
      }
    }
    else
    {
      printf("Error\n");
      return ERROR;
    }
  }
  return 0;
}

//----------------------------------------------------------------------------
/// Checks the commands for errors and returns appropriate type
/// If no type given returns -1 for error.
///
/// @param  command command given wia cmd
/// @return          int corrisponding to the defines
//----------------------------------------------------------------------------
int commandHandler(char* command)
{
  if (!strcmp(command, "dup"))
  {
    return DUP_CMD;
  }
  else if (!strcmp(command, "halve"))
  {
    return HALVE_CMD;
  }
  else if (!strcmp(command, "add"))
  {
    return ADD_CMD;
  }
  else if (!strcmp(command, "sub"))
  {
    return SUB_CMD;
  }
  else if (!strcmp(command, "mul"))
  {
    return MUL_CMD;
  }
  else if (!strcmp(command, "div"))
  {
    return DIV_CMD;
  }
  return ERROR;
}

//----------------------------------------------------------------------------
/// doubles given parameters and prints result
///
/// @param nbr double to be doubled
//----------------------------------------------------------------------------
void dup(double nbr)
{
  double result = nbr * 2;
  printf("The result is: %.2lf\n", result);
}

//----------------------------------------------------------------------------
/// halves given parameter and prints result
///
/// @param nbr double to be halved
//----------------------------------------------------------------------------
void halve (double nbr)
{
  double result = nbr / 2;
  printf("The result is: %.2lf\n", result);
}

//----------------------------------------------------------------------------
/// adds 2 parameters
///
/// @param first
/// @param second
//----------------------------------------------------------------------------
void add(double first, double second) {
  double result = first + second;
  printf("The result is: %.2lf\n", result);
}

//----------------------------------------------------------------------------
/// subtract one parameter from other
/// first - second
///
/// @param first  [description]
/// @param second [description]
//----------------------------------------------------------------------------
void sub(double first, double second) {
  double result = first - second;
  printf("The result is: %.2lf\n", result);
}

//----------------------------------------------------------------------------
/// multiplies first with second
/// @param first
/// @param second
//----------------------------------------------------------------------------
void mul(double first, double second) {
  double result = first * second;
  printf("The result is: %.2lf\n", result);
}

//----------------------------------------------------------------------------
/// does a division from first / second
///
/// @param first
/// @param second
//----------------------------------------------------------------------------
void divi(double first, double second) {
  double result = first / second;
  printf("The result is: %.2lf\n", result);
}
