/**
 * \file map.cpp
 * \make the map
 * \author Alain Casali
 * \author Marc Laporte
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


//constant
#include <fstream>
#include <string>

//oussama
#include <ctime> // pour avoir le time() [pas sûr que ce soit obligatoire]
#include <cstdlib> // pour avoir le rand()

using namespace std;

unsigned cptMax; //declare the point's numbers max

char choice ; // declare char choice

// map setting declard
string  LinkMap;         // declare string for map link



/**
 * @brief Clear_Screen clear the screen
 */
void Clear_Screen ()
{
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
void InitMat (CMat & Mat, unsigned NbLine, unsigned NbColumn, CPosition & PosPlayer1, CPosition & PosPlayer2, CPosition & PosPlayer3, CPosition & PosPlayer4, CPosition & PosPlayer5,
              CPosition & PosEasterEgg1, CPosition & PosEasterEgg2, CPosition & PosEasterEgg3, CPosition & PosEasterEgg4, CPosition & PosEasterEgg5, CPosition & PosFinish)
{
    unsigned y = 0; //declare and set y at 0
    unsigned x = 0; //declare and set x at 0
    Mat.resize (NbLine); //set the matrix 's size at the number of lines
    const CVLine KLine (NbColumn, KPoint);
    for (CVLine &ALine : Mat)
    ALine = KLine;  

    ifstream ifs (LinkMap);                         //open the doc with the map's link in the string
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
    PosPlayer1.first = PosStartPY;                           // Y coordinates of player one is PosStatPY
    PosPlayer1.second = PosStartPX;                          // X coordinates of Player one is PosStartPX
    Mat [PosPlayer1.first][PosPlayer1.second] = Pacman;     //put Pacman in Matrix coordinates Y = PosPlayer1.first X = PosPlayer1.second
    if (choice != '4') { ////if the labyrinth mode isn't choose
        PosPlayer2.first = PosStartG1Y;                         // Y coordinates of player one is PosStartG1Y
        PosPlayer2.second =PosStartG1X;                         // X coordinates of Player one is PosStartG1X
        Mat [PosPlayer2.first][PosPlayer2.second] = Ghost1;     //put the Ghost number one in Matrix coordinates Y = PosPlayer2.first X = PosPlayer2.second
        PosPlayer3.first = PosStartG2Y;                         // Y coordinates of player one is PosStartG2Y
        PosPlayer3.second =PosStartG2X;                         // X coordinates of Player one is PosStartG2X
        Mat [PosPlayer3.first][PosPlayer3.second] = Ghost2;      //put the Ghost number two in Matrix coordinates Y = PosPlayer3.first X = PosPlayer3.second
        PosPlayer4.first = PosStartG3Y;                         // Y coordinates of player one is PosStartG3Y
        PosPlayer4.second =PosStartG3X;                         // X coordinates of Player one is PosStartG3X
        Mat [PosPlayer4.first][PosPlayer4.second] = Ghost3;      //put the Ghost number three in Matrix coordinates Y = PosPlayer4.first X = PosPlayer4.second
        PosPlayer5.first = PosStartG4Y;                         // Y coordinates of player one is PosStartG4Y
        PosPlayer5.second =PosStartG4X;                          // X coordinates of Player one is PosStartG4X
        Mat [PosPlayer5.first][PosPlayer5.second] = Ghost4;      //put the Ghost number four in Matrix coordinates Y = PosPlayer5.first X = PosPlayer5.second

        //set the position of all Easter Eggs
        PosEasterEgg1.first = PosEasterEgg1Y;
        PosEasterEgg1.second = PosEasterEgg1X;
        Mat [PosEasterEgg1.first][PosEasterEgg1.second] = EasterEgg1;
        PosEasterEgg2.first = PosEasterEgg2Y;
        PosEasterEgg2.second = PosEasterEgg2X;
        Mat [PosEasterEgg2.first][PosEasterEgg2.second] = EasterEgg2;
        PosEasterEgg3.first = PosEasterEgg3Y;
        PosEasterEgg3.second = PosEasterEgg3X;
        Mat [PosEasterEgg3.first][PosEasterEgg3.second] = EasterEgg3;
        PosEasterEgg4.first = PosEasterEgg4Y;
        PosEasterEgg4.second = PosEasterEgg4X;
        Mat [PosEasterEgg4.first][PosEasterEgg4.second] = EasterEgg4;
        PosEasterEgg5.first = PosEasterEgg5Y;
        PosEasterEgg5.second = PosEasterEgg5X;
        Mat [PosEasterEgg5.first][PosEasterEgg5.second] = EasterEgg5;
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

/**
 * @brief Menu print the menu
 */
void  Menu(){

    Clear_Screen();
    ifstream ifs ("menu.txt"); //open the doc in the link
    if(ifs.is_open() == false) // if ifs.open not open the doc
        cout << "Menu loading problem"; // display "Menu loading problem"
    string Line; // else declare string "Ligne"
    while (true){
        getline(ifs, Line); // get line of the string in Line
        if (ifs.eof()) // if is the end of the file
                break; // finish
        cout << Line << endl; // else display Line and end line
    }
}

/**
 * @brief Random choose a labyrinth map automatically
 */
void Random()
{
    srand(time(NULL)); // pas sûr qque ce soit obligatoire
    int mapchoice = rand()%3 + 1; // mapchoice prend une valeur aléatoire entre 1 et 3
    switch (mapchoice)
    {
        case 1 :
            LinkMap = "map4"; //Link of the map file
            MapY = 21;       // map's size
            MapX = 30;       // map's size

            PosStartPY = 0;  //y coordonate of the PacMan's start position
            PosStartPX = 28;  //x coordonate of the PacMan's start position

            PosFinishY = 20;    //y coordonate of the Finish point's position
            PosFinishX = 3;     //x coordonate of the Finish point's position
            break;

        case 2 :
            LinkMap = "map5"; //Link of the map file
            MapY = 37;       //map's size
            MapX = 34;        //map's size

            PosStartPY = 36;  //y coordonate of the PacMan's start position
            PosStartPX = 17;  //x coordonate of the PacMan's start position

            PosFinishY = 0;     //y coordonate of the Finish point's position
            PosFinishX = 1;     //x coordonate of the Finish point's position
            break ;

        case 3 :
            LinkMap = "map6"; //Link of the map file
            MapY = 46;       // map's size
            MapX = 58;       // map's size

            PosStartPY = 0;  //y coordonate of the PacMan's start position
            PosStartPX = 26; //x coordonate of the PacMan's start position

            PosFinishY = 45;    //y coordonate of the Finish point's position
            PosFinishX = 1;     //x coordonate of the Finish point's position
            break ;
    }
}

/**
 * @brief ChoixMenu let the user choose the level and the game mode
 */
void ChoiceMenu(){

    cout << "choisissez une map" << endl; // ask chose a map or change setting
    cin >> choice ; // enter choix value

    switch(choice)
    {
    case '1':
        LinkMap = "map1"; //Link of the map file
        MapY = 15;       // map's size
        MapX = 21;       // map's size

        PosStartG1Y = 1; // y coordonate of the start position of the ghost number one
        PosStartG1X = 1; // x coordonate of the start position of the ghost number one

        PosStartG2Y = 13; // y coordonate of the start position of the ghost number two
        PosStartG2X = 1; // x coordonate of the start position of the ghost number two

        PosStartG3Y = 13; // y coordonate of the start position of the ghost number three
        PosStartG3X = 19; // x coordonate of the start position of the ghost number three

        PosStartG4Y = 1; // y coordonate of the start position of the ghost number four
        PosStartG4X = 19; // x coordonate of the start position of the ghost number four

        PosStartPY = 7;  //y coordonate of the PacMan's start position
        PosStartPX = 10;  //x coordonate of the PacMan's start position

        break;

    case '2':
        LinkMap = "map2"; //Link of the map file
        MapY = 28;       // map's size
        MapX = 31;       // map's size

        PosStartG1Y = 1; // y coordonate of the start position of the ghost number one
        PosStartG1X = 1; // x coordonate of the start position of the ghost number one

        PosStartG2Y = 26; // y coordonate of the start position of the ghost number two
        PosStartG2X = 1; // x coordonate of the start position of the ghost number two

        PosStartG3Y = 26; // y coordonate of the start position of the ghost number three
        PosStartG3X = 29; // x coordonate of the start position of the ghost number three

        PosStartG4Y = 1;  // y coordonate of the start position of the ghost number four
        PosStartG4X = 29; // x coordonate of the start position of the ghost number four

        PosStartPY = 13;  //y coordonate of the PacMan's start position
        PosStartPX = 14;  //x coordonate of the PacMan's start position

        PosEasterEgg1Y = 11;
        PosEasterEgg1X = 14;

        PosEasterEgg2Y = 26;
        PosEasterEgg2X = 11;

        PosEasterEgg3Y = 4;
        PosEasterEgg3X = 10;

        PosEasterEgg4Y = 1;
        PosEasterEgg4X = 18;

        PosEasterEgg5Y = 23;
        PosEasterEgg5X = 17;

        break;

    case '3':
        LinkMap = "map3"; //Link of the map file
        MapY = 31;       // map's size
        MapX = 28;       // map's size

        PosStartG1Y = 1; // y coordonate of the start position of the ghost number one
        PosStartG1X = 1; // x coordonate of the start position of the ghost number one

        PosStartG2Y = 29; // y coordonate of the start position of the ghost number two
        PosStartG2X = 1; // x coordonate of the start position of the ghost number two

        PosStartG3Y = 29; // y coordonate of the start position of the ghost number three
        PosStartG3X = 26; // x coordonate of the start position of the ghost number three

        PosStartG4Y = 1;  // y coordonate of the start position of the ghost number four
        PosStartG4X = 26; // x coordonate of the start position of the ghost number four

        PosStartPY = 14;  //y coordonate of the PacMan's start position
        PosStartPX = 14;  //x coordonate of the PacMan's start position

        break;

    case '4':
        Clear_Screen();
        Random(); //call the random function
        break;
    }
}
