#include <iostream>
#include <cstdlib>
// Allows access to time in the computer
#include <ctime>
#include <windows.h>
using namespace std;


#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H



int Get_Random_Number(int Range)
{
  // Seed that randomly takes a number. Time 0 calculates the time since 1970
  //    in seconds. Increases over time.
  srand(time(0));

  int answer = rand()%Range;

  return(answer);




}

#endif
