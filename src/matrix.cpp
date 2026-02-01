/**
 * \file map.cpp
 * \make the map
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
#include <fstream>
#include <string>
#include <ctime> // pour avoir le time() [pas sûr que ce soit obligatoire]
#include <cstdlib> // pour avoir le rand()

#include "include/type.h"
#include "include/models.h"
#include "src/classes.cpp"


using namespace std;
unsigned cptMax; //declare the point's numbers max
char choice ; // declare char choice

/**
 * @brief Clear_Screen clear the screen
 */
void Clear_Screen () {
    system("clear");
}

/**
 * @brief InitMat Matrix's initialization
 * @param Mat
 * @param NbLine
 * @param NbColumn
 * @param PosPlayer1
 * @param PosPlayer2
 * @param PosPlayer3
 * @param PosPlayer4
 * @param PosPlayer5
 * @param PosFinish
 */
void InitMat (CMat & Mat, MapSettings & mapSettings) {
    unsigned y = 0; //declare and set y at 0
    unsigned x = 0; //declare and set x at 0
    Mat.resize (mapSettings.lignes); //set the matrix 's size at the number of lines
    const CVLine KLine (mapSettings.columns, KPoint);
    for (CVLine &ALine : Mat)
    ALine = KLine;  

    ifstream ifs (mapSettings.linkMap);                         //open the doc with the map's link in the string
    if(ifs.is_open() == false)                      // if is not open
        cout << "Problème de chargement de la map"; // print ...
    Mat [y][x] = Kwall;                             // put wall in Matrix coordinates is  Y=PosWall.first X=PosWall.second
    char Carac;                                     // declare char for put in the char of the file
    while (true){
        Carac = ifs.get();                          // read and write in Carac the char of the file
        if (ifs.eof())                              //if is finsish
                break;                              //stop
        if (Carac == '|'){                          // if Carac is egal ofe '|'
            y=y +1;                                 // add one at y
            x=0;                                    //put x at 0
        }
        if(Carac == ' '){
            Mat [y][x] = KPoint;                    //put space in Matrix coordinates  Y=y X=x
            x = x+1;                                //add one at X
        }
        if(Carac == '*'){
            Mat [y][x] = Kwall;                     //put wall in Matrix coordinates  Y=y X=x
            x = x+1;                                //add one at X
        }
        if(Carac == ','){
            Mat [y][x] = FalseWall;                 //put a false wall in Matrix coordinates  Y=y X=x
            x = x+1;                                //add one at X
        }
        if (Carac == 'A'){
            Mat [y][x] = Finish;                    //put the finish in Matrix coordinates  Y=y X=x
            x = x+1;                                //add one at X
        }
    }

    //set starting position
    player.Pos = mapSettings.player;
    Mat [player.Pos.first][player.Pos.second] = Pacman;
    if (choice != '4') { ////if the labyrinth mode isn't choose
        ghost1.Pos = mapSettings.ghost1;
        Mat [ghost1.Pos.first][ghost1.Pos.second] = Ghost1;     //put the Ghost number one in Matrix coordinates Y = PosPlayer2.first X = PosPlayer2.second
        ghost2.Pos = mapSettings.ghost2;
        Mat [ghost2.Pos.first][ghost2.Pos.second] = Ghost2;      //put the Ghost number two in Matrix coordinates Y = PosPlayer3.first X = PosPlayer3.second
        ghost3.Pos = mapSettings.ghost3;
        Mat [ghost3.Pos.first][ghost3.Pos.second] = Ghost3;      //put the Ghost number three in Matrix coordinates Y = PosPlayer4.first X = PosPlayer4.second
        ghost4.Pos = mapSettings.ghost4;
        Mat [ghost4.Pos.first][ghost4.Pos.second] = Ghost4;      //put the Ghost number four in Matrix coordinates Y = PosPlayer5.first X = PosPlayer5.second

        if (choice == '2') {
            //set the position of all Easter Eggs
            PosEasterEgg1 = mapSettings.eggs.egg1;
            Mat [PosEasterEgg1.first][PosEasterEgg1.second] = EasterEgg1;
            PosEasterEgg2 = mapSettings.eggs.egg2;
            Mat [PosEasterEgg2.first][PosEasterEgg2.second] = EasterEgg2;
            PosEasterEgg3 = mapSettings.eggs.egg3;
            Mat [PosEasterEgg3.first][PosEasterEgg3.second] = EasterEgg3;
            PosEasterEgg4 = mapSettings.eggs.egg4;
            Mat [PosEasterEgg4.first][PosEasterEgg4.second] = EasterEgg4;
            PosEasterEgg5 = mapSettings.eggs.egg5;
            Mat [PosEasterEgg5.first][PosEasterEgg5.second] = EasterEgg5;
        }
    }
    else {

        PosFinish.first = PosFinishY;                         // Y coordinates of the finish point one is PosSFinishY
        PosFinish.second =PosFinishX;                          // X coordinates of the finish point one is PosFinishX
        Mat [PosFinish.first][PosFinish.second] = Finish;        //put the finish point in Matrix coordinates Y = PosFinish.first X = PosFinish.second
    }

    if (choice == '1') cptMax = 12400;      //set the point's number max of the map4 at 12 400
    if (choice == '2') cptMax = 32200;      //set the point's number max of the map5 at 32 200
    if (choice == '3') cptMax = 33000;      //set the point's number max of the map4 at 33 000

}

/**
 * @brief ShowMatrix print the matrix
 * @param Mat
 */
void ShowMatrix(const CMat & Mat) {

    //Show the matrix at the screen
    const unsigned KNbLine = Mat.size (); //declare and set the lines's number at the matrix's size
    const unsigned KNbCol  = Mat[0].size (); //declare and set the columns's number at the matrix's lines' size
    cout << string (KNbCol + 2 , '-') << endl; //print '-' on the entire line

    for (unsigned i (0); i < KNbLine; ++i) //run while i is lower than lines's number
    {
    cout << '|';
    //File_Flow();
    for (char c : Mat[i]) {
        //Color the game
        Colors(BBlack);
        switch (c) {
            //color all walls and their background in magenta
            case Kwall:
                Colors(PMagenta);
                Colors(BMagenta);
                cout << c;
                Colors(KReset);
                break;   
            case KEmpty:
                cout << c;
                break;    
            case KPoint:
                cout<< c;
                break;
            case FalseWall:
                Colors(PMagenta);
                Colors(BMagenta);
                cout << c;
                Colors(KReset);
                break;
            //color the ghost number one and his background in blue
            case Ghost1:
                Colors(PBlue);
                Colors(BBlue);
                cout << c;
                Colors(KReset);
                break;
            //color the ghost number two and his background in red
            case Ghost2:
                Colors(PRed);
                Colors(BRed);
                cout << c;
                Colors(KReset);
                break;
            //color the ghost number three and his background in green
            case Ghost3:
                Colors(PGreen);
                Colors(BGreen);
                cout << c;
                Colors (KReset);
                break;
            //color the ghost number four and his background in cyan
            case Ghost4:
                Colors (PCyan);
                Colors (BCyan);
                cout << c;
                Colors (KReset);
                break;
            //color the pacman and his background in yellow
            case Pacman:
                Colors (PYellow);
                Colors (BYellow);
                cout << c;
                Colors (KReset);
                break;
            //color the finish caracter and his background in green
            case Finish :
                Colors (PGreen);
                cout << c;
                Colors(KReset);
                break;

            //color all EaterEggs and their background in White
            case EasterEgg1:
                 Colors (PWhite);
                 Colors (BWhite);
                 cout << c;
                 Colors (KReset);
                 break;
            case EasterEgg2:
                 Colors (PWhite);
                 Colors (BWhite);
                 cout << c;
                 Colors (KReset);
                 break;
             case EasterEgg3:
                 Colors (PWhite);
                 Colors (BWhite);
                 cout << c;
                 Colors (KReset);
                 break;
             case EasterEgg4:
                 Colors (PWhite);
                 Colors (BWhite);
                 cout << c;
                 Colors (KReset);
                 break;
             case EasterEgg5:
                 Colors (PWhite);
                 Colors (BWhite);
                 cout << c;
                 Colors (KReset);
                 break;
        }
    }
        cout << '|' << endl;
    }
    cout << string (KNbCol + 2 , '-') << endl; //print '-' on the entire line
}