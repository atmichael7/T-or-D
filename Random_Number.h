#include <iostream>
#include <cstdlib>
// Allows access to time in the computer
#include <ctime>
#include <windows.h>
using namespace std;

#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
// Uses an algorithm to calculate a random number, with the use of the system time
//  to create a unique seed each run and uses the range defined by the caller
//  to set the number to count up to from zero(0).

// If the user wants to not have zero to be a possible output, add one(1) to the
//  answer. Therefor in the possibility it generates zero, it will become one.

int Get_Random_Number(int Range)
{
  // Seed that randomly takes a number. Time 0 calculates the time since 1970
  //    in seconds. Increases over time.
  srand(time(0));
  int answer = rand()%Range;
  return(answer);
}

#endif
