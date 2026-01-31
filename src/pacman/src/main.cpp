/**
 * \file main.cpp
 * \main program
 * \author Adrien Lacroix
 * \author Constant Alberola
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 2.0
 * \date 31th January 2026
 */

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif
#include <iostream>
#include <stdio.h>
#include <vector>
#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"
#include "src/pacman/src/menu.cpp"
#include "src/pacman/src/matrix.cpp"
#include "src/pacman/src/move.cpp"
#include "src/pacman/src/EasterEggs.cpp"
#include "src/pacman/src/game.cpp"
#include "src/pacman/src/class.cpp"

using namespace std;

/**
 * @brief escape give possibility to escape the game or to begin a new game
 * @return true or false
 */
bool escape () {
    char t;                      //declare a variable t
    cout << "Appuyez sur une touche pour continuer." << endl << "Pour quitter appuyez sur 0" << endl;
    cin >> t;                   //enter t value
    if (t == '0') return true;
    return false;
}

/**
 * @brief game move the player and ghost bots, set the victory condition
 * @return 0
 */
int game(const unsigned & cptMax, MapSettings mapSettings) { //game depends of the player's point's number max and of the player point's number
    unsigned TurnNum (1); //declare and set the player's turn at 1
    unsigned TurnGhost; //Declare the variable of the number ghost's position

    CMat Mat;
    char nextMove;
    bool Victory (false);

    cpt = 100;


    Player player;
    Ghost ghost1;
    Ghost ghost2;
    Ghost ghost3;
    Ghost ghost4;

    player.car = 0;
    ghost1.car = X;
    ghost2.car = C;
    ghost3.car = V;
    ghost4.car = B;

    InitMat (Mat, mapSettings)
    ShowMatrix (Mat); //Run the matrix's print function

    if (choice == '4') { //if the labyrinth mode is choose
         while (player.Pos != PosFinish) { //run while the Player one isn't on the finish point
             Colors (PRed); //print in red
             cout << "Essayez d'atteindre l'arrivée A avec le moins de points possible !" << endl;
             Colors (KReset); //reset colors
             Colors (PBlue); //print in blue
             cout << "vous avez : " << player.cpt << " points" << endl; //print the player's number of point
             Colors (KReset);//reset colors
             cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : "; //print the turn's number

             cin >> nextMove; //enter the player's move

             nextMove = toupper (nextMove);
             while (!player.Move (Mat, nextMove, player.Pos)){ //run while "MoveToke" function return false
                 Clear_Screen(); //clear the screen
                 cout << "déplacement impossible" << endl;
                 ShowMatrix (Mat);
                 Colors (PBlue);
                 cout << "vous avez " << player.cpt << " points" << endl;
                 Colors (KReset);
                 cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
                 cin >> nextMove;
                 nextMove = toupper(nextMove);
             }
             Clear_Screen();
             ShowMatrix(Mat);
         }

         Colors (PGreen); //print in blue
         cout << "Félicitations vous avez gagné avec " << player.cpt << " points ! :)" << endl;
         Colors (KReset);
     }
     else {
        while (player.cpt < cptMax) { //else, run while the player's number of point is lower than the point's number max

            Easter_Eggs(player.Pos, PosEasterEgg1, PosEasterEgg2, PosEasterEgg3, PosEasterEgg4, PosEasterEgg5); //test Easter_Eggs function

            Colors (PBlue);
            cout << "vous avez " << player.cpt << "/" << cptMax << " points" << endl; //print the player's number of point and the point's number max
            Colors (KReset);
            cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
            cin >> nextMove;

            nextMove = toupper (nextMove);
            while (!player.Move (Mat, nextMove, player.Pos)){ //run while "Move" function return false
                Clear_Screen();
                cout << "déplacement impossible" << endl;
                ShowMatrix (Mat);
                Colors (PBlue);
                cout << "vous avez " << player.cpt << "/" << cptMax << " points" << endl;
                Colors (KReset);
                cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
                cin >> nextMove;
                nextMove = toupper (nextMove);
            }
            Clear_Screen();
            ShowMatrix (Mat);

            //defeat test
            if ((player.Pos == ghost1.Pos) | (player.Pos == ghost2.Pos) | (player.Pos == ghost3.Pos) | (player.Pos == ghost4.Pos)) {  //loose if the player is on the same position than one the ghost
                Colors (PGreen);
                cout << "Vous avez perdu :'(" << endl;
                Colors (KReset);
                break;
            }

            //Victory test
            if (player.cpt == cptMax) Victory = true; //if the player's number of point and the point's number max are equals, the party is win
            else {
                TurnGhost = 1; //set turn ghost at 1
                while (TurnGhost < 5) { //run while Ghost's turns's number is lower than 5
                    if (TurnGhost == 1) { //if the Ghost's turn's number equals 1
                        srand(time(0));
                        unsigned botchoice = rand() % NBCOMMAND; // Give a radom value between 0, 1, 2 or 3
                        bool booleanMove;
                        booleanMove = ghost1.Move(Mat, botchoice, player.Pos);
                        while (!booleanMove) { //run while "MoveBot" function return false
                            srand(time(0));
                            if (botchoice == 0) {
                                booleanMove = ghost1.Move(Mat, 1, player.Pos);
                            } else if (botchoice == 1) {
                                booleanMove = ghost1.Move(Mat, 0, player.Pos);
                            }
                        }
                    }
                    if (TurnGhost == 2) { //if the Ghost's turn's number equals 2
                       srand(time(0));
                        unsigned botchoice = rand() % NBCOMMAND; // Give a radom value between 0, 1, 2 or 3
                        bool booleanMove;
                        booleanMove = ghost2.Move(Mat, botchoice, player.Pos);
                        while (!booleanMove) { //run while "MoveBot" function return false
                            srand(time(0));
                            if (botchoice == 0) {
                                booleanMove = ghost2.Move(Mat, 1, player.Pos);
                            } else if (botchoice == 1) {
                                booleanMove = ghost2.Move(Mat, 0, player.Pos);
                            }
                        }
                    }
                    if (TurnGhost == 3) { //if the Ghost's turn's number equals 3
                        srand(time(0));
                        unsigned botchoice = rand() % NBCOMMAND; // Give a radom value between 0, 1, 2 or 3
                        bool booleanMove;
                        booleanMove = ghost3.Move(Mat, botchoice, player.Pos);
                        while (!booleanMove) { //run while "MoveBot" function return false
                            srand(time(0));
                            if (botchoice == 0) {
                                booleanMove = ghost3.Move(Mat, 1, player.Pos);
                            } else if (botchoice == 1) {
                                booleanMove = ghost3.Move(Mat, 0, player.Pos);
                            }
                        }
                    if (TurnGhost == 4) { //if the Ghost's turn's number equals 4
                        srand(time(0));
                        unsigned botchoice = rand() % NBCOMMAND; // Give a radom value between 0, 1, 2 or 3
                        bool booleanMove;
                        booleanMove = ghost4.Move(Mat, botchoice, player.Pos);
                        while (!booleanMove) { //run while "MoveBot" function return false
                            srand(time(0));
                            if (botchoice == 0) {
                                booleanMove = ghost4.Move(Mat, 1, player.Pos);
                            } else if (botchoice == 1) {
                                booleanMove = ghost4.Move(Mat, 0, player.Pos);
                            }
                        }
                    }
                    ++TurnGhost;
                }
                Clear_Screen();
                ShowMatrix (Mat);
            }

            if ((player.Pos == ghost1.Pos) | (player.Pos == ghost2.Pos) | (player.Pos == ghost3.Pos) | (player.Pos == ghost4.Pos)) {
                Colors (PGreen);
                cout << "Vous avez perdu :'(" << endl;
                Colors (KReset);
                break;
            }

            //Increase party's number
            ++TurnNum;
         }
    }

    if (Victory == true) { //if the party is won
        Colors (PGreen);
        cout << "Félicitations vous avez gagné ! :)" << endl;
        Colors (KReset);
    }

    return 0; //return 0
}

/**
 * @brief main run Menu, ChoiceMenu and game
 * @return game
 */
int main() {
    MapSettings mapSettings;
    Menu(); //run the menu's function
    mapSettings = ChoiceMenu(); //run the  menu's choice function
    game(cptMax, mapSettings);//run the game's function
    while (!escape()){
        Menu(); //run the menu's function
        mapSettings = ChoiceMenu(); //run the  menu's choice function
        game(cptMax, mapSettings);//run the game's function
    }
    return 0;
}
