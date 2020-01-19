#include <iostream>
#include <vector>
#include "Random_Number.h"

#ifndef DARELIST_H
#define DARELIST_H


using namespace std;


vector<string> DaresNormal = {"Pluck 5 eyebrows",
                              "Draw a mustache with sharpie",
                              "Eat a spoon of ketchup",
                              "Chug a bottle of water under 20 seconds",
                              "Eat a spoon of wasabi",
                              "Take a shot of Tapatio",
                              "Text a random contact 'Have a good day'",
                              "Immitate a popular YouTube video until a player recognizes it"
                              };


vector<string> DaresExtreme = {"Pour a cup of ice cold water on yourself",
                               "Pour a cup of hot water on yourself",
                               "You must ask other players for permission to go to the bathroom",
                               "For the next ten minutes, randomly yell things",
                               "Eat a spoonful of mustard",
                               "Take 2 shots of the hottest hot sauce you have",
                               "For the next ten minutes, talk without closing your mouth",
                               "Color one of your front teeth black",
                               "Talk in an accent for the next three rounds",
                               "Drink a small cup of condiments created by each player",
                               "Do pushups until your arms give out, wait five seconds then do three more",
                               "Take a bite out of a bar of soap and leave it for others to see"

                              };

vector<string> DaresNSFW = {"Pluck 5 eyebrows",
                            "Draw a mustache with sharpie",
                            "Eat a spoon of ketchup",
                            "Chug a bottle of water under 20 seconds",
                            "Eat a spoon of wasabi",
                            "Take a shot of Tapatio",
                            "Text a random contact 'Have a good day'",
                            };


void Get_Dare(int Gamemode)
{
  // Get a random number first
  // Then go through if statements to use that number to select dare
  // If the number is larger than the vector.size then subract 7 until in range
  //   Do this with a while look, while (Rand >= DaresNSFW.size) { Rand -= 7;}

  /*
    DELAYS:
  1) Waiting for a program that pulls a random number in order to ask questions
  2) Need more material in every list (for each gamemode)

  */
  int Returned_Answer;

  if (Gamemode == 1)
  {
    //cout << "GAMEMODE 1";
    Returned_Answer = Get_Random_Number(DaresNormal.size());
    cout << "\n  >>>> " << DaresNormal[Returned_Answer] << endl << endl;
    Sleep(5000);
  }

  if (Gamemode == 2)
  {
    //cout << "GAMEMODE 2";
    Returned_Answer = Get_Random_Number(DaresExtreme.size());
    cout << "\n  >>>> " << DaresExtreme[Returned_Answer] << endl << endl;
    Sleep(5000);
  }

  if (Gamemode == 3)
  {
    cout << "GAMEMODE 3";
  }
}





#endif
