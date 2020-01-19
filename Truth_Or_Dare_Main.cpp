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

using namespace std;

// Initializing game functions for later use
void Game_Run(int Gamemode);
int Stage_2(int Score, string P_Name);
int Players;

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

// =================== GAME RUN FUNCTION / WHILE LOOP ==========================

void Game_Run(int Gamemode)
{
  // Setting up the color changing stuff
  HANDLE  hConsole;
  int k;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



  // Clear screen, and display current gamemode
  system("CLS");
  if (Gamemode == 1)
  {
    k = 2;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    cout << "\n    >> Normal Mode << \n" << endl;
  }
  if (Gamemode == 2)
  {
    k = 4;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    cout << "\n    >> Hardcore Mode << \n" << endl;
  }
  if (Gamemode == 3)
  {
    k = 13;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    cout << "\n    >> NSFW Mode << \n" << endl;
  }


  bool Anti_Cheat = true;
  while (Anti_Cheat)
  {
    k = 3;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    // Ask user how many players with participate
    cout << "  How many players do you have? \n"
         << "  ---> ";
    k = 7;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---

    // Gather their answer and set it to Players
    //int Players;
    cin >> Players;

    // Make sure the player number is greater than one
    if (Players >= 1)
    {
      Anti_Cheat = false;
    }

    if (Players <= 0)
    {
      k = 64;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      cout << endl << "  The amount of players has to be at least one (1).  ";
      Sleep(3000);
      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      system("CLS");
    }

  }

//  int Players = Players;
  // Create vector for user to input player names
  // (Players) is setting the size of the vector to the amount of players
  vector<string> Player_Names;
  // Makes a vector that scores players, in line with player name position starting from 0
  vector<int> Player_Scores(Players);

  // Initialize i to count while loop for naming players
  // Initialize temporary value to push back to the player list
  string TempPlayerName;
  int i = 1;
  while (Players >= i)
  {
    k = 3;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    // Ask user to input names into each player slot
    cout << "\n  Enter player " << i << "'s name: ";
    k = 7;
    SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
    cin >> TempPlayerName;
    // Put user input into the player list vector
    Player_Names.push_back(TempPlayerName);
    i++;
  }


  k = 6;
  SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
  // Dramatic start, clear screen, countdown using sleep and cout
  Sleep(1000);
  system("CLS");
  cout << "\n   >> The game will begin in: ";
  Sleep(1000);
  system("CLS");
  cout << "\n   >> The game will begin in: 3";
  Sleep(1000);
  system("CLS");
  cout << "\n   >> The game will begin in: 2";
  Sleep(1000);
  system("CLS");
  cout << "\n   >> The game will begin in: 1";
  Sleep(1050);
  system("CLS");



  // Start from player 1
  // Get a random number to select index for question (Dare_List.size || Truth_List.size)

  // Set up a while loop of Game Time
  bool Game_Time = true;
  int Player_Turn = 0;
  string Player_Answer;
  int Round_Counter = 1;

  while(Game_Time)
  {
    // Prevents player count to not exceed total amount of players
    // Ex. If there are 3 players total, and count is greater than 3
    //       it will reset it to player 1.. aka position 0 in player list
    if (Player_Turn >= Players)
    {
      Player_Turn = 0;
      k = 4;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      system("CLS");
      k = 96;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      cout << "   +++ That's the end of round " << Round_Counter << " +++   ";
      Sleep(4000);
      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      system("CLS");
      Round_Counter += 1;

    }

    //Making a while loop to ensure players can't skip their turn if they
    //   type things that don't match in the if statements
    bool Anti_Cheat = true;

    while (Anti_Cheat)
    {
      system("CLS");
      k = 3;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      // Alerts player turn, asks for truth or dare, in form of char
      cout << endl << " >>> Player " << Player_Names[Player_Turn] << ", it is your turn..."
           << endl << "     Truth or Dare? (T/D): ";

      k = 7;
      SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
      cin >> Player_Answer;



      // Utility section of response PAUSE / SCORES / NEW GAME

// -----PAUSE THE GAME FUNCTION-------------------------------------------------------------
      if (Player_Answer == "p")
      {
        // Displays the game is paused and waits for player input to continue
        system("CLS");
        k = 64;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << endl << " >>> The game is paused <<< " << endl;
        k = 3;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << "     Type c to continue the game...    ";
        k = 7;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cin >> Player_Answer;
        system("CLS");
      }

// -----LIST SCORES FUNCTION-------------------------------------------------------------
      if (Player_Answer == "s")
      {
        // Clears screen, prints out all the players followed by their scores in two columns
        system("CLS");
        for (i = 0; i < Player_Scores.size(); i++)
        {
          k = 11;
          SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
          cout << Player_Names[i];
          k = 7;
          SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
          cout << " - ";
          k = 14;
          SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
          cout << Player_Scores[i] << endl;
        }
        // Waits 3 seconds after printing all the scores, then waits for user input to continue
        Sleep(3000);
        k = 3;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << endl << "     >>> Type c to continue...";
        k = 7;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cin >> Player_Answer;
        system("CLS");
      }

// -----START A NEW GAME FUNCTION-------------------------------------------------------------
      if (Player_Answer == "n")
      {
        system("CLS");
        k = 64;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << "   >>> Are you sure you want to start a new game? (y/n):   ";
        k = 7;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cin >> Player_Answer;

        // If player answers yes to quit, it will stop the game time to false
        if (Player_Answer == "y")
        {
          Game_Time = false;
          Anti_Cheat = false;
          system("CLS");
        }
        // If player answers anything other than yes, the game will continue as normal
      }

// -----OUT OF UTILITY SECTION, CONTINUES T OR D FUNCTIONS-------------------------------------------
      // Based on player response send them to correct function of truth or dare
      //    with correct difficulty in mind; Normal, Hardcore, NSFW
      if (Player_Answer == "t")
      {
        k = 12;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        Get_Truth(Gamemode);
        Anti_Cheat = false;
        Player_Scores[Player_Turn] = Stage_2(Player_Scores[Player_Turn], Player_Names[Player_Turn]);
      }

      if (Player_Answer == "d")
      {
        k = 4;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        Get_Dare(Gamemode);
        Anti_Cheat = false;
        Player_Scores[Player_Turn] = Stage_2(Player_Scores[Player_Turn], Player_Names[Player_Turn]);
      }

      if (Player_Answer != "p" && Player_Answer != "s" && Player_Answer != "n"
            && Player_Answer != "t" && Player_Answer != "d" && Player_Answer != "y"
            && Player_Answer != "c")
      {
        system("CLS");
        k = 64;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        cout << "  Incorrect input.  ";
        k = 3;
        SetConsoleTextAttribute(hConsole, k); // COLOR CHANGE -------===----===---
        Sleep(5000);
      }

  }


    // End of current players turn, go back up to top of loop
    Player_Turn++;

  }


//Game run end

}



//------------------STAGE 2 OF CONFIRMING PLAYER COMPLETE OR NOT -----------------------------------
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
