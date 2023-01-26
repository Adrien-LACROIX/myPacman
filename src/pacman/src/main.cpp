/**
 * \file main.cpp
 * \main program
 * \author Adrien Lacroix
 * \author Constant Alberola
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 1.1
 * \date 4 mai 2021
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
#include "src/pacman/src/map.cpp"
#include "src/pacman/src/move.cpp"
#include "src/pacman/src/EasterEggs.cpp"

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
int game(const unsigned & cptMax, unsigned & cpt) { //game depends of the player's point's number max and of the player point's number

    //declare the lines and columns depending of MapY and MapX
    unsigned KLines (MapY);
    unsigned KColumns (MapX);
    unsigned TurnNum (1); //declare and set the player's turn at 1
    unsigned TurnGhost; //Declare the variable of the number ghost's position

    CMat Mat;
    char car;
    bool Victory (false);

    cpt = 100;


    CPosition Pos, PosPlayer1, PosPlayer2, PosPlayer3, PosPlayer4, PosPlayer5, PosEasterEgg1, PosEasterEgg2, PosEasterEgg3, PosEasterEgg4, PosEasterEgg5, PosFinish; //declare all variables positions

    InitMat (Mat, KLines, KColumns, PosPlayer1, PosPlayer2, PosPlayer3, PosPlayer4, PosPlayer5, PosEasterEgg1, PosEasterEgg2, PosEasterEgg3, PosEasterEgg4, PosEasterEgg5, PosFinish) ; //Run the matrix's initialization fuction

    ShowMatrix (Mat); //Run the matrix's print function

    if (choice == '4') { //if the labyrinth mode is choose
         while (PosPlayer1 != PosFinish) { //run while the Player one isn't on the finish point
             Colors (PRed); //print in red
             cout << "Essayez d'atteindre l'arrivée A avec le moins de points possible !" << endl;
             Colors (KReset); //reset colors
             Colors (PBlue); //print in blue
             cout << "vous avez : " << cpt << " points" << endl; //print the player's number of point
             Colors (KReset);//reset colors
             cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : "; //print the turn's number

             char Move;
             cin >> Move; //enter the player's move

             Move = toupper (Move);
             while (!MoveToken (Mat, Move, PosPlayer1)){ //run while "MoveToke" function return false
                 Clear_Screen(); //clear the screen
                 cout << "déplacement impossible" << endl;
                 ShowMatrix (Mat);
                 Colors (PBlue);
                 cout << "vous avez " << cpt << " points" << endl;
                 Colors (KReset);
                 cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
                 cin >> Move;
                 Move = toupper (Move);
             }
             Clear_Screen();
             ShowMatrix (Mat);
         }

         Colors (PGreen); //print in blue
         cout << "Félicitations vous avez gagné avec " << cpt << " points ! :)" << endl;
         Colors (KReset);
     }
     else {
        while (cpt < cptMax) { //else, run while the player's number of point is lower than the point's number max

            Easter_Eggs(PosPlayer1, PosEasterEgg1, PosEasterEgg2, PosEasterEgg3, PosEasterEgg4, PosEasterEgg5); //test Easter_Eggs function

            Colors (PBlue);
            cout << "vous avez " << cpt << "/" << cptMax << " points" << endl; //print the player's number of point and the point's number max
            Colors (KReset);
            cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
            char Move;
            cin >> Move;

            Move = toupper (Move);
            while (!MoveToken (Mat, Move, PosPlayer1)){ //run while "MoveToke" function return false
                Clear_Screen();
                cout << "déplacement impossible" << endl;
                ShowMatrix (Mat);
                Colors (PBlue);
                cout << "vous avez " << cpt << "/" << cptMax << " points" << endl;
                Colors (KReset);
                cout << "tour numero : " << TurnNum << endl << "Saisisez un déplacement : ";
                cin >> Move;
                Move = toupper (Move);
            }
            Clear_Screen();
            ShowMatrix (Mat);

            //defeat test
            if ((PosPlayer1 == PosPlayer2) | (PosPlayer1 == PosPlayer3) | (PosPlayer1 == PosPlayer4) | (PosPlayer1 == PosPlayer5)) {  //loose if the player is on the same position than one the ghost
                cout << "Vous avez perdu :'(" << endl;
                break;
            }

            //Victiry test
            if (cpt == cptMax) Victory = true; //if the player's number of point and the point's number max are equals, the party is win
            else {
                TurnGhost = 1; //set turn ghost at 1
                while (TurnGhost < 5) { //run while Ghost's turns's number is lower than 5
                    if (TurnGhost == 1) { //if the Ghost's turn's number equals 1
                        Pos = PosPlayer2; //Pos take the PosPlayer2 value
                        car = 'X'; //car take 'X' value
                    }
                    if (TurnGhost == 2) { //if the Ghost's turn's number equals 2
                        PosPlayer2 = Pos; //PosPlayer2 take the Pos value
                        Pos = PosPlayer3; //Pos take the PosPlayer3 value
                        car = 'C'; //car take 'X' value
                    }
                    if (TurnGhost == 3) { //if the Ghost's turn's number equals 3
                        PosPlayer3 = Pos; //PosPlayer3 take the Pos value
                        Pos = PosPlayer4; //Pos take the PosPlayer4 value
                        car = 'V'; //car take 'X' value
                    }
                    if (TurnGhost == 4) { //if the Ghost's turn's number equals 4
                        PosPlayer4 = Pos; //PosPlayer4 take the Pos value
                        Pos = PosPlayer5;//Pos take the PosPlayer5 value
                        car = 'B'; //car take 'X' value
                    }
                    srand(time(0));
                    unsigned botchoice = rand() % NBCOMMAND; // Give a radom value between 0, 1, 2 or 3
                    botchoice = toupper (botchoice);
                    while (!MoveBot(Mat, botchoice, car, Pos, PosPlayer1)) { //run while "MoveBot" function return false
                        botchoice = rand() % NBCOMMAND;
                        botchoice = toupper (botchoice);
                    }
                    Clear_Screen();
                    ShowMatrix (Mat);
                    ++TurnGhost;
                }
                PosPlayer5 = Pos;
            }

            if ((PosPlayer1 == PosPlayer2) | (PosPlayer1 == PosPlayer3) | (PosPlayer1 == PosPlayer4) | (PosPlayer1 == PosPlayer5)) {
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
int main()
{
    Menu(); //run the menu's function
    ChoiceMenu(); //run the  menu's choice function
    game(cptMax, cpt);//run the game's function
    while (!escape()){
        Menu(); //run the menu's function
        ChoiceMenu(); //run the  menu's choice function
        game(cptMax, cpt);//run the game's function
    }
    return 0;
}
