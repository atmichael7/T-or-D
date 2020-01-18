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
#include "PrintLetter.h"
#include "Truth_List.h"
#include "Dare_List.h"

using namespace std;

// Initializing game functions for later use
void Game_Run(int Gamemode);
int Stage_2(int Score, string P_Name);

// Main menu to select game type
int main()
{
  // Initialize values that pertain to the main menu
     // Amount of Players
  int Players;
  int Main_Menu_Answer;
     // Main Menu Loop
  bool ToD_Main_Menu_Loop = true;

  // Begin the Loop
  while (ToD_Main_Menu_Loop)
  {
    system("CLS");
    cout << endl;
    PLR("       ==============================", 10);
    PLR("          Welcome to Truth or Dare", 10);
    PLR("       ==============================", 10);
    cout << endl;
    PLR("            [1] - Normal Mode", 20);
    PLR("            [2] - Extreme Mode", 20);
    PLR("            [3] - NSFW Mode", 20);
    cout << endl;
    PLR("       ==============================", 10);
    PLR("            Please select a mode", 10);
    PLR("       ==============================", 10);
    cout << " \n       --> ";

    // Asked user what mode to choose, gather question in form of integer
    cin >> Main_Menu_Answer;

    // Go to the appropriate game mode based on users integer input
    // Doing so by having if statements to select correct input
        // Menu Option 1; Normal Mode
    if (Main_Menu_Answer == 1)
      {
        Game_Run(1);
      }
        // Menu Option 2; Extreme Mode
    if (Main_Menu_Answer == 2)
      {
        Game_Run(2);
      }
        // Menu Option 3; NSFW Mode
    if (Main_Menu_Answer == 3)
      {
        Game_Run(3);
      }

  }

}

// =================== GAME RUN FUNCTION / WHILE LOOP ==========================

void Game_Run(int Gamemode)
{
  // Clear screen, and display current gamemode
  system("CLS");
  if (Gamemode == 1)
  {
    cout << "\n    >> Normal Mode << \n" << endl;
  }
  if (Gamemode == 2)
  {
    cout << "\n    >> Hardcore Mode << \n" << endl;
  }
  if (Gamemode == 3)
  {
    cout << "\n    >> NSFW Mode << \n" << endl;
  }


  // Ask user how many players with participate
  cout << "  How many players do you have? \n"
       << "  ---> ";
  // Gather their answer and set it to Players
  int Players;
  cin >> Players;
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
    // Ask user to input names into each player slot
    cout << "\n  Enter player " << i << "'s name: ";
    cin >> TempPlayerName;
    // Put user input into the player list vector
    Player_Names.push_back(TempPlayerName);
    i++;
  }



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
  // Get a random number to choose truth or dare (1, 2)
  // Get a random number to select index for question (Dare_List.size || Truth_List.size)

  // Set up a while loop of Game Time
  bool Game_Time = true;
  int Player_Turn = 0;
  string Player_Answer;


  while(Game_Time)
  {
    // Prevents player count to not exceed total amount of players
    // Ex. If there are 3 players total, and count is greater than 3
    //       it will reset it to player 1.. aka position 0 in player list
    if (Player_Turn >= Players)
    {
      Player_Turn = 0;

    }

    //Making a while loop to ensure players can't skip their turn if they
    //   type things that don't match in the if statements
    bool Anti_Cheat = true;

    while (Anti_Cheat)
    {

      // Alerts player turn, asks for truth or dare, in form of char
      cout << endl << " >>> Player " << Player_Names[Player_Turn] << ", it is your turn..."
           << endl << "     Truth or Dare? (T/D): ";

      cin >> Player_Answer;



      // Utility section of response PAUSE / SCORES / NEW GAME

// -----PAUSE THE GAME FUNCTION-------------------------------------------------------------
      if (Player_Answer == "p")
      {
        // Displays the game is paused and waits for player input to continue
        system("CLS");
        cout << "\n   >>> The game is paused <<< \n" << "       Type c to continue the game...";
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
          cout << Player_Names[i] << " - " << Player_Scores[i] << endl;
        }
        // Waits 3 seconds after printing all the scores, then waits for user input to continue
        Sleep(3000);
        cout << "\n   >>> Type c to continue...";
        cin >> Player_Answer;
        system("CLS");
      }

// -----START A NEW GAME FUNCTION-------------------------------------------------------------
      if (Player_Answer == "n")
      {
        system("CLS");
        cout << "  >>> Are you sure you want to start a new game? (y/n): ";
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

// -----OUT OF UTILITY SECTION, CONTINUES T OR D FUNCTIONS--------------------------------------------------
      // Based on player response send them to correct function of truth or dare
      //    with correct difficulty in mind; Normal, Hardcore, NSFW
      if (Player_Answer == "t")
      {
        Get_Truth(Gamemode);
        Anti_Cheat = false;
        Player_Scores[Player_Turn] = Stage_2(Player_Scores[Player_Turn], Player_Names[Player_Turn]);
      }

      if (Player_Answer == "d")
      {
        Get_Dare(Gamemode);
        Anti_Cheat = false;
        Player_Scores[Player_Turn] = Stage_2(Player_Scores[Player_Turn], Player_Names[Player_Turn]);
      }

      if (Player_Answer != "p" && Player_Answer != "s" && Player_Answer != "n"
            && Player_Answer != "t" && Player_Answer != "d" && Player_Answer != "y"
            && Player_Answer != "c")
      {
        system("CLS");
        cout << " Incorrect input.";
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
    bool Anti_Cheat = true;
    string Player_Answer;
    while (Anti_Cheat)
    {
      // After the Truth or Dare was asked, ask host if they completed it and add or subtract score.
      cout << "\n   >>>>> Did " << P_Name << " complete their task? (y/n): ";
      cin >> Player_Answer;


      if (Player_Answer == "y")
      {
        cout << "\n   ^^ Nice, here's +5 points ^^";

        Sleep(1000);
        system("CLS");
        Anti_Cheat = false;
        return(Score += 5);
      }

      if (Player_Answer == "n")
      {
        cout << "\n   vv Lame, minus -7 points vv";

        Sleep(1000);
        system("CLS");
        Anti_Cheat = false;
        return(Score -= 7);
      }

      if (Player_Answer != "y" && Player_Answer != "n")
      {
        system("CLS");
        cout << " Incorrect input.";
        Sleep(5000);
      }

    }
  }