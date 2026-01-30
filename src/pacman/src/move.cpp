
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
bool PointUnderGhost;
bool GhostXPointPos;
bool GhostCPointPos;
bool GhostVPointPos;
bool GhostBPointPos;

bool PointOnNextPos (CMat & Mat, char car, CPosition & Pos) {
    if Mat[Pos.first][Pos.second] = KPoint {
        return true;
    } else {
        return false
    }
}

bool moveUp(CMat & Mat, char car, CPosition & Pos) {
    if (Pos.first == 0) {
        if (Mat[Pos.second].size()-1 == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            Pos.first = MapY-1;
            Mat [MapY-1][Pos.second] = car;
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
            Mat [Pos.first-1][Pos.second] = car;
            return true;
        }
    }
}

bool moveDown(CMat & Mat, char car, CPosition & Pos) {
    if (Pos.first == MapY-1) {
        if (Mat[Pos.second][0] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        } else {
            Pos.first = 0;
            Mat [0][Pos.second] = car;
            return true;
        }
    } else {
        if (Mat[Pos.first+1][Pos.second] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        } else {
            ++Pos.first
            Mat [Pos.first+1][Pos.second] = car;
            return true;
        }
    }
}

bool moveLeft(CMat & Mat, char car, CPosition & Pos) {
        if (Pos.second == 0) {
            if (Mat[Pos.first].size()-1 == Kwall) {
                Mat [Pos.first][Pos.second] = car;
                return false;
            }
            else {
                Pos.second = MapX-1;
                Mat [Pos.first][MapX-1] = car;
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
                Mat [Pos.first][Pos.second-1] = car;
                return true;
            }
        }
}

bool moveRight(CMat & Mat, char car, CPosition & Pos) {
    if (Pos.second == Mat[Pos.first].size()-1) {
        if (Mat[Pos.first][0] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            Pos.second = 0;
            Mat [Pos.first][0] = car;
            return true;
        }
    } else {
        if (Mat[Pos.first][Pos.second+1] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            ++Pos.second.
            Mat [Pos.first][Pos.second+1] = car;
            return true;
        }
    }
}