
/**
 * \file move.cpp
 * \make the mouvements
 * \author Adrien Lacroix
 * \author Constant Lacroix
 * \author Oussama Talbi
 * \author Thomas Celeschi
 * \author Julian Cayuela
 * \version 2.0
 * \date 31th January 2026
 */

#include "include/type.h"
#include "include/models.h"

using namespace std;

class Movement {
    public :
        bool success, pointOnPos;
}

bool PointOnNextPos (CMat & Mat, CPosition & Pos) {
    if Mat[Pos.first][Pos.second] = KPoint {
        return true;
    } else {
        return false
    }
}

Movement moveUp(CMat & Mat, char car, CPosition & Pos) {
    bool pointOnNextPos;
    if (Pos.first == 0) {
        if (Mat[Pos.second].size()-1 == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            Pos.first = MapY-1;
            Mat [MapY-1][Pos.second] = car;
            return Movement(true, pointOnNextPos);
        }
    }
    else {
        if (Mat[Pos.first-1][Pos.second] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            --Pos.first;
            Mat [Pos.first-1][Pos.second] = car;
            return Movement(true, pointOnNextPos);
        }
    }
}

Movement moveDown(CMat & Mat, char car, CPosition & Pos) {
    bool pointOnNextPos;
    if (Pos.first == MapY-1) {
        if (Mat[Pos.second][0] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        } else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            Pos.first = 0;
            Mat [0][Pos.second] = car;
            return Movement(true, pointOnNextPos);
        }
    } else {
        if (Mat[Pos.first+1][Pos.second] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        } else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            ++Pos.first
            Mat [Pos.first+1][Pos.second] = car;
            return Movement(true, pointOnNextPos);
        }
    }
}

Movement moveLeft(CMat & Mat, char car, CPosition & Pos) {
    bool pointOnNextPos;
    if (Pos.second == 0) {
        if (Mat[Pos.first].size()-1 == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            Pos.second = MapX-1;
            Mat [Pos.first][MapX-1] = car;
            return Movement(true, pointOnNextPos);
        }
    }
    else {
        if (Mat[Pos.first][Pos.second-1] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            --Pos.second;
            Mat [Pos.first][Pos.second-1] = car;
            return Movement(true, pointOnNextPos);
        }
    }
}

Movement moveRight(CMat & Mat, char car, CPosition & Pos) {
    bool pointOnNextPos;
    if (Pos.second == Mat[Pos.first].size()-1) {
        if (Mat[Pos.first][0] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            Pos.second = 0;
            Mat [Pos.first][0] = car;
            return Movement(true, pointOnNextPos);
        }
    } else {
        if (Mat[Pos.first][Pos.second+1] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return Movement(false, false);
        }
        else {
            pointOnNextPos = PointOnNextPos(Mat, Pos);
            ++Pos.second.
            Mat [Pos.first][Pos.second+1] = car;
            return Movement(true, pointOnNextPos);
        }
    }
}