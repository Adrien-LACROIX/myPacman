/*!
 * \file models.h
 * \brief Declare all variable and constant, set colors identifiers
 * \author Adrien Lacroix
 * \author Constant Alberola
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 1.2
 * \date 1st February 2026
 */

#ifndef COLORANDMODELS_H
#define COLORANDMODELS_H

#pragma once

#include <iostream>
using namespace std;
#include <string>
#include "include/type.h"
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
void Colors (const string & coul) {
    cout << "\033[" << coul <<"m";
}


#endif // COLORANDMODELS_H
