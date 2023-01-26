
/**
 * \file mobe.cpp
 * \make the mouvements
 * \author Adrien Lacroix
 * \author Constant Lacroix
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 1.0
 * \date 21 janvier 2021
 */

#include <iostream>
#include <vector>
#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"

using namespace std;

unsigned cpt; //declare the player's point's number max

/**
 * @brief MoveToken let the user choose his move
 * @param Mat
 * @param Move
 * @param Posplayer1
 * @return
 */
bool MoveToken (CMat & Mat, char Move, CPosition  & Posplayer1) {

        char car = Mat[Posplayer1.first][Posplayer1.second]; //declare the variable car and set his value at the player one's position

        switch (Move)
        {
        case 'Z':       //if the case 'Z' is enter
            if (Posplayer1.first == 0) { //if the player is at the map's top
                if (Mat[Posplayer1.second].size()-1 == Kwall) { //if the case of th last line isn't a wall
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false; //return false
                }
                else {
                    if (Mat[Posplayer1.second].size()-1 == KPoint) cpt = cpt+100; //if the case of the last line is an point
                    Mat [Posplayer1.first][Posplayer1.second] = KEmpty; //the current player's case become empty
                    Posplayer1.first = MapY-1; //the player one go to the case of the last line
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return true; //return true
                }
            }
            else {
                if (Mat[Posplayer1.first-1][Posplayer1.second] == Kwall) { //if the upper case isn't a wall
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first-1][Posplayer1.second] == KPoint) cpt = cpt+100; //if the upper case is an point
                    --Posplayer1.first; //the player one go to the upper case
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    Mat [Posplayer1.first+1][Posplayer1.second] = KEmpty; //the player's bellow case become empty
                    return true;
                }
            }
            break;

        case 'Q':       //if the case 'Q' is enter
            if (Posplayer1.second == 0) { //if the player is at the left border of the map
                if (Mat[Posplayer1.first].size()-1 == Kwall) { //if the case at the right border isn't a wall
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first].size()-1 == KPoint) cpt = cpt+100;
                    Mat [Posplayer1.first][Posplayer1.second] = KEmpty;  //the current player's case become empty
                    Posplayer1.second = MapX-1; //the player one go to the right border case
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return true;
               }
            }
            else {
                if (Mat[Posplayer1.first][Posplayer1.second-1] == Kwall) { //if the left case isn't a wall
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first][Posplayer1.second-1] == KPoint) cpt = cpt+100;
                    --Posplayer1.second;    //the player one go to the upper case
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    Mat [Posplayer1.first][Posplayer1.second+1] = KEmpty; //the player's right case become empty
                    return true;
                }
            }
            break;

        case 'S':
            if (Posplayer1.first == MapY-1) {
                if (Mat[Posplayer1.first][Posplayer1.second] == Kwall) {
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first][Posplayer1.second] == KPoint) cpt = cpt+100;
                    Mat [Posplayer1.first][Posplayer1.second] = KEmpty; //the current player's case become empty
                    Posplayer1.first = 0;
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return true;
                }
            }
            else {
                if (Mat[Posplayer1.first+1][Posplayer1.second] == Kwall) {
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first+1][Posplayer1.second] == KPoint) cpt = cpt+100;
                    ++Posplayer1.first;
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    Mat [Posplayer1.first-1][Posplayer1.second] = KEmpty;
                    return true;
                }
            }
            break;

        case 'D':

            if (Posplayer1.second == Mat[Posplayer1.first].size()-1) {
                if (Mat[Posplayer1.first][0] == '*') {
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first][0] == KPoint) cpt = cpt+100;
                    Mat [Posplayer1.first][Posplayer1.second] = KEmpty; //the current player's case become empty
                    Posplayer1.second = 0;
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return true;
               }
            }
            else {
                if (Mat[Posplayer1.first][Posplayer1.second+1] == Kwall) {
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    return false;
                }
                else {
                    if (Mat[Posplayer1.first][Posplayer1.second+1] == KPoint) cpt = cpt+100;
                    ++Posplayer1.second;
                    Mat [Posplayer1.first][Posplayer1.second] = Pacman; //set the pacman at the current player's position
                    Mat [Posplayer1.first][Posplayer1.second-1] = KEmpty;
                    return true;
                }
            }
            break;
        }
        Mat [Posplayer1.first][Posplayer1.second] = car;

        return 0;
}

/**
 * @brief MoveBot choose automatically a move for ghosts bots
 * @param Mat
 * @param Move
 * @param Posplayer1
 * @return Boolean
 */
bool MoveBot (CMat & Mat, char botchoice, char car, CPosition & Pos, CPosition & Posplayer1){

    # define MOVEVERTICAL       0
    # define MOVEHONRIZONTAL    1
    # define NBCOMMAND          2

   car = Mat [Pos.first][Pos.second];
   Mat [Pos.first][Pos.second] = KPoint;
   unsigned road;
   unsigned tryingRoad;

    srand(time(0));

   switch (botchoice) { //choose a direction
   case MOVEVERTICAL: //vertical direction
       road = Posplayer1.first - Pos.first; //find the shortest road in order to eat player1
       tryingRoad = Posplayer1.first - (Pos.first + 1);

       if(tryingRoad > road){ //up
         if (Pos.first == 0) {
             if (Mat[Pos.second].size()-1 == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 Pos.first = MapY-1;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         else {
             if (Mat[Pos.first-1][Pos.second] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 --Pos.first;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         break;
       }
       else if (tryingRoad < road){ //down
             if (Pos.first == MapY-1) {
                 if (Mat[Pos.second][0] == Kwall) {
                     Mat [Pos.first][Pos.second] = car;
                     return false;
                 }
                 else {
                     Pos.first = 0;
                     Mat [Pos.first][Pos.second] = car;
                     return true;
                 }
             }
             else {
                 if (Mat[Pos.first+1][Pos.second] == Kwall) {
                     Mat [Pos.first][Pos.second] = car;
                     return false;
                 }
                 else {
                     ++Pos.first;
                     Mat [Pos.first][Pos.second] = car;
                     return true;
                 }
             }
             break;
         }
         else {
           return false;
           break;
       }

    case MOVEHONRIZONTAL://horizontal direction
       road = Posplayer1.second - Pos.second; //find the shortest road in order to eat player1
       tryingRoad = Posplayer1.second - (Pos.second + 1);

       if (tryingRoad > road ) { //left
         if (Pos.second == 0) {
             if (Mat[Pos.first].size()-1 == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 Pos.second = MapX-1;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
            }
         }
         else {
             if (Mat[Pos.first][Pos.second-1] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 --Pos.second;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         break;
       }
       else if (tryingRoad < road ) { //right
           if (Pos.second == Mat[Pos.first].size()-1) {
               if (Mat[Pos.first][0] == Kwall) {
                   Mat [Pos.first][Pos.second] = car;
                   return false;
               }
               else {
                   Pos.second = 0;
                   Mat [Pos.first][Pos.second] = car;
                   return true;
              }
           }
           else {
               if (Mat[Pos.first][Pos.second+1] == Kwall) {
                   Mat [Pos.first][Pos.second] = car;
                   return false;
               }
               else {
                   ++Pos.second;
                   Mat [Pos.first][Pos.second] = car;
                   return true;
               }
           }
           break;
       }
       else {
         return false;
         break;
      }

/*
    case MOVEDOWN:
         if (Pos.first == MapY-1) {
             if (Mat[Pos.second][0] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 Pos.first = 0;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         else {
             if (Mat[Pos.first+1][Pos.second] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 ++Pos.first;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         break;


    case MOVERIGHT:
         if (Pos.second == Mat[Pos.first].size()-1) {
             if (Mat[Pos.first][0] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 Pos.second = 0;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
            }
         }
         else {
             if (Mat[Pos.first][Pos.second+1] == Kwall) {
                 Mat [Pos.first][Pos.second] = car;
                 return false;
             }
             else {
                 ++Pos.second;
                 Mat [Pos.first][Pos.second] = car;
                 return true;
             }
         }
         break;
         */
   }
   Mat [Pos.first][Pos.second] = car;
   return 0;
}
