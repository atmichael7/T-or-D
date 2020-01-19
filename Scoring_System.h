#include <iostream>
#include <windows.h>

#ifndef SCORING_SYSTEM_H
#define SCORING_SYSTEM_H

using namespace std;


/*
This is what will be called after the truth or dare function has been called.
  It will ask the host if the player has completed their task or not.
  If they have it will add five points and return this value to add to the score.
  If they haven't it will take seven and return the subraction of the score.

  Afterwards it should terminate this function and go back to the top of Game_Time
*/



int Stage_2(int Score, string P_Name)
{
  // Set up color changer
  HANDLE  hConsole;
  int k;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  bool Anti_Cheat = true;
  string Player_Answer;
  while (Anti_Cheat)
  {
    k = 3;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---

    // After the Truth or Dare was asked, ask host if they completed it and add or subtract score.
    cout << "\n   >>>>> Did " << P_Name << " complete their task? (y/n): ";

    k = 7;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    cin >> Player_Answer;


    if (Player_Answer == "y")
    {
      k = 288;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---


      cout << "\n   ^^ Nice, here's +5 points ^^   ";

      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      Sleep(1000);
      system("CLS");
      Anti_Cheat = false;
      return(Score += 5);
    }

    if (Player_Answer == "n")
    {
      k = 79;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---

      cout << "\n   vv Lame, minus -7 points vv   ";

      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      Sleep(1000);
      system("CLS");
      Anti_Cheat = false;
      return(Score -= 7);
    }

    if (Player_Answer != "y" && Player_Answer != "n")
    {
      system("CLS");
      k = 64;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---

      cout << "  Incorrect input.  ";
      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      Sleep(5000);
      system("CLS");
    }

  }
}

#endif
