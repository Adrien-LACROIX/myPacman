/*!
 * \file models.h
 * \brief Declare all variable and constant, set colors identifiers
 * \author Adrien Lacroix
 * \author Constant Alberola
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 1.1
 * \date 4 mai 2018
 */

#ifndef COLORANDMODELS_H
#define COLORANDMODELS_H

#pragma once

#include <iostream>
#include <string>
#include "src/pacman/headers/Doc_Prof/type.h"
#define models(condition) models(condition, #condition, __FILE__, __LINE__, __func__);

const char Pacman = 'O';

const char Ghost1 = 'X';
const char Ghost2 = 'C';
const char Ghost3 = 'V';
const char Ghost4 = 'B';

const char Kwall = '*';
const char FalseWall = ',';
const char KPoint = '.';
const char None = 'r';
const char EasterEgg1 = 'L';
const char EasterEgg2 = 'N';
const char EasterEgg3 = 'T';
const char EasterEgg4 = 'S';
const char EasterEgg5 = 'J';
const char Finish = 'A';


unsigned PosStartG1Y;    // coordonate Y of the start position of the Ghost
unsigned PosStartG1X;
unsigned PosStartG2Y;    // coordonate Y of the start position of the Ghost
unsigned PosStartG2X;
unsigned PosStartG3Y;    // coordonate Y of the start position of the Ghost
unsigned PosStartG3X;
unsigned PosStartG4Y;    // coordonate Y of the start position of the Ghost
unsigned PosStartG4X;    // coordonate X of the start position of the Ghost
unsigned PosStartPY;
unsigned PosStartPX;
unsigned PosEasterEgg1Y;
unsigned PosEasterEgg1X;
unsigned PosEasterEgg2Y;
unsigned PosEasterEgg2X;
unsigned PosEasterEgg3Y;
unsigned PosEasterEgg3X;
unsigned PosEasterEgg4Y;
unsigned PosEasterEgg4X;
unsigned PosEasterEgg5Y;
unsigned PosEasterEgg5X;
unsigned PosFinishY;
unsigned PosFinishX;

// map setting declard
unsigned MapY ;         // declared string for size of matrix
unsigned MapX ;         // declared string for size of matrix

using namespace std;

//Set colors identifiers
const string KReset   {"0"};
const string PBlack   {"30"};
const string PRed     {"31"};
const string PGreen   {"32"};
const string PYellow  {"33"};
const string PBlue    {"34"};
const string PMagenta {"35"};
const string PCyan    {"36"};
const string PWhite   {"37"};
const string BBlack   {"40"};
const string BRed     {"41"};
const string BGreen   {"42"};
const string BYellow  {"43"};
const string BBlue    {"44"};
const string BMagenta {"45"};
const string BCyan    {"46"};
const string BWhite   {"47"};


/**
 * @brief Colors use the permission to print colors in the terminal
 * @param coul
 */
void Colors (const string & coul)
{
    cout << "\033[" << coul <<"m";
}


#endif // COLORANDMODELS_H
