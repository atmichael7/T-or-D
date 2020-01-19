/*
PROGRAMMER: MICHAEL BARRETT
PROGRAM START DATE: 1/14/2020

FOLLOWING CODE REFERENCED THAT WAS REFERENCED:
    Random number generator; reference Bucky (Youtube)
    Use of vector clarification; Professor Voigt (CSE 202 Notes / Fall 2019)
    Idea for program; Nefthaly G.

*/

#include <iostream>
#include <vector>
#include <windows.h>

#include "PrintLetter.h"
#include "Truth_List.h"
#include "Dare_List.h"
//#include "Scoring_System.h"
#include "T_Or_D_Game_Run.h"

using namespace std;

// Initializing game functions for later use
void Game_Run(int Gamemode);
int Stage_2(int Score, string P_Name);
//int Players;

// Main menu to select game type
int main()
{
  // Initialize values that pertain to the main menu
     // Amount of Players
  int Players;
  string Main_Menu_Answer;
     // Main Menu Loop
  bool ToD_Main_Menu_Loop = true;

  // Begin the Loop
  while (ToD_Main_Menu_Loop)
  {
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= << COLOR CHANGE >> =-=-=-=-=-=-=-=-=
        HANDLE  hConsole;
        int k;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        k = 6;
        SetConsoleTextAttribute(hConsole, k);
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= << COLOR CHANGE >> =-=-=-=-=-=-=-=-=
    system("CLS");
    cout << endl;
    PLR("       ==============================", 7);
    PLR("          Welcome to Truth or Dare", 5);
    PLR("       ==============================", 7);
    k = 7;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE --------===----===---
    cout << endl;
    PLR("            [1] - Normal Mode", 5);
    PLR("            [2] - Extreme Mode", 5);
    PLR("            [3] - NSFW Mode", 5);
    k = 6;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE --------===----===---
    cout << endl;
    PLR("       ==============================", 7);
    PLR("            Please select a mode", 10);
    PLR("       ==============================", 7);
    cout << " \n       --> ";
    k = 7;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE --------===----===---

    // Asked user what mode to choose, gather question in form of integer
    cin >> Main_Menu_Answer;

    // Go to the appropriate game mode based on users integer input
    // Doing so by having if statements to select correct input
        // Menu Option 1; Normal Mode
    if (Main_Menu_Answer == "1")
      {
        Game_Run(1);
      }
        // Menu Option 2; Extreme Mode
    if (Main_Menu_Answer == "2")
      {
        Game_Run(2);
      }
        // Menu Option 3; NSFW Mode
    if (Main_Menu_Answer == "3")
      {
        Game_Run(3);
      }

    if (Main_Menu_Answer != "1" && Main_Menu_Answer != "2" && Main_Menu_Answer != "3")
      {
        system("CLS");
        k = 64;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << "   Incorrect input.   ";
        Sleep(3000);
        k = 6;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      }

  }

}
