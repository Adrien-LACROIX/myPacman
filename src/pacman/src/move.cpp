
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

void checkIfLastPosIsAPoint(CMat & Mat, char car, CPosition & Pos) {
    switch (car) {
    case 'x':
        if (GhostXPointPos) {
            Mat [Pos.first][Pos.second] = KPoint;
        }
        GhostXPointPos = PointUnderGhost;
        break;
    case 'c':
        if (GhostCPointPos) {
            Mat [Pos.first][Pos.second] = KPoint;
        }
        GhostCPointPos = PointUnderGhost;
        break;
    case 'v':
        if (GhostVPointPos) {
            Mat [Pos.first][Pos.second] = KPoint;
        }
        GhostVPointPos = PointUnderGhost;
        break;
    case 'b':
        if (GhostBPointPos) {
            Mat [Pos.first][Pos.second] = KPoint;
        }
        GhostBPointPos = PointUnderGhost;
        break;
    }
}

bool moveUp(CMat & Mat, char car, CPosition & Pos) {
    if (Pos.first == 0) {
        if (Mat[Pos.second].size()-1 == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            if (Mat [MapY-1][Pos.second] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [MapY-1][Pos.second] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
            return true;
        }
    }
    else {
        if (Mat[Pos.first-1][Pos.second] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            if (Mat [Pos.first-1][Pos.second] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [Pos.first-1][Pos.second] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
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
            if (Mat [0][Pos.second] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [0][Pos.second] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
            return true;
        }
    } else {
        if (Mat[Pos.first+1][Pos.second] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        } else {
            if (Mat [Pos.first+1][Pos.second] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [Pos.first+1][Pos.second] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
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
                if (Mat [Pos.first][MapX-1] == KPoint) {
                    PointUnderGhost = true;
                } else {
                    PointUnderGhost = false;
                }
                Mat [Pos.first][MapX-1] = car;
                checkIfLastPosIsAPoint(Mat, car, Pos);
                return true;
            }
        }
        else {
            if (Mat[Pos.first][Pos.second-1] == Kwall) {
                Mat [Pos.first][Pos.second] = car;
                return false;
            }
            else {
                if (Mat [Pos.first][Pos.second-1] == KPoint) {
                    PointUnderGhost = true;
                } else {
                    PointUnderGhost = false;
                }
                Mat [Pos.first][Pos.second-1] = car;
                checkIfLastPosIsAPoint(Mat, car, Pos);
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
            if (Mat [Pos.first][0] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [Pos.first][0] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
            return true;
        }
    } else {
        if (Mat[Pos.first][Pos.second+1] == Kwall) {
            Mat [Pos.first][Pos.second] = car;
            return false;
        }
        else {
            if (Mat [Pos.first][Pos.second+1] == KPoint) {
                PointUnderGhost = true;
            } else {
                PointUnderGhost = false;
            }
            Mat [Pos.first][Pos.second+1] = car;
            checkIfLastPosIsAPoint(Mat, car, Pos);
            return true;
        }
    }
}

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

    bool success;
    car = Mat [Pos.first][Pos.second];
    srand(time(0));

    switch (botchoice) { //choose a direction
    case MOVEVERTICAL: //vertical direction
        cout << "Try vertical mouvement" << endl;
        if(Pos.first > Posplayer1.first){ //up
            cout << "Ghost want to move up" << endl;
            success = moveUp(Mat, car, Pos);
            switch (car) {
            case 'x':
                if (success && GhostXPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostXPointPos = PointUnderGhost;
                break;
            case 'c':
                if (success && GhostCPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostCPointPos = PointUnderGhost;
                break;
            case 'v':
                if (success && GhostVPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostVPointPos = PointUnderGhost;
                break;
            case 'b':
                if (success && GhostBPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostBPointPos = PointUnderGhost;
                break;
            }
            return success;
            break;
          }
        else if (Pos.first < Posplayer1.first){ //down
            cout << "Ghost want to move down" << endl;
            success = moveDown(Mat, car, Pos);
            switch (car) {
            case 'x':
                if (success && GhostXPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostXPointPos = PointUnderGhost;
                break;
            case 'c':
                if (success && GhostCPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostCPointPos = PointUnderGhost;
                break;
            case 'v':
                if (success && GhostVPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostVPointPos = PointUnderGhost;
                break;
            case 'b':
                if (success && GhostBPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostBPointPos = PointUnderGhost;
                break;
            }
            return success;
            break;
        } else {
            srand(time(0));
            unsigned mouv = rand() % 2;
            switch (mouv){
            case 0:
                success = moveUp(Mat, car, Pos);
                switch (car) {
                case 'x':
                    if (success && GhostXPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostXPointPos = PointUnderGhost;
                    break;
                case 'c':
                    if (success && GhostCPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostCPointPos = PointUnderGhost;
                    break;
                case 'v':
                    if (success && GhostVPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostVPointPos = PointUnderGhost;
                    break;
                case 'b':
                    if (success && GhostBPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostBPointPos = PointUnderGhost;
                    break;
                }
                return success;
                break;

            case 1:
                success = moveDown(Mat, car, Pos);
                switch (car) {
                case 'x':
                    if (success && GhostXPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostXPointPos = PointUnderGhost;
                    break;
                case 'c':
                    if (success && GhostCPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostCPointPos = PointUnderGhost;
                    break;
                case 'v':
                    if (success && GhostVPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostVPointPos = PointUnderGhost;
                    break;
                case 'b':
                    if (success && GhostBPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostBPointPos = PointUnderGhost;
                    break;
                }
                return success;
                break;
            }
            break;
        }
        break;

    case MOVEHONRIZONTAL://horizontal direction
        cout << "Try horizontal mouvement" << endl;
        if (Pos.second > Posplayer1.second ) { //left
            cout << "Ghost want to move left" << endl;
            success = moveLeft(Mat, car, Pos);
            switch (car) {
            case 'x':
                if (success && GhostXPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostXPointPos = PointUnderGhost;
                break;
            case 'c':
                if (success && GhostCPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostCPointPos = PointUnderGhost;
                break;
            case 'v':
                if (success && GhostVPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostVPointPos = PointUnderGhost;
                break;
            case 'b':
                if (success && GhostBPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostBPointPos = PointUnderGhost;
                break;
            }
            return success;
            break;
        }
        else if (Pos.second < Posplayer1.first ) { //right
            cout << "Ghost want to move right" << endl;
            success = moveRight(Mat, car, Pos);
            switch (car) {
            case 'x':
                if (success && GhostXPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostXPointPos = PointUnderGhost;
                break;
            case 'c':
                if (success && GhostCPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostCPointPos = PointUnderGhost;
                break;
            case 'v':
                if (success && GhostVPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostVPointPos = PointUnderGhost;
                break;
            case 'b':
                if (success && GhostBPointPos) {
                    Mat [Pos.first][Pos.second] = KPoint;
                }
                GhostBPointPos = PointUnderGhost;
                break;
            }
            return success;
            break;
        } else {
            srand(time(0));
            unsigned mouv = rand() % 2;
            switch (mouv){
            case 0:
                success = moveLeft(Mat, car, Pos);
                switch (car) {
                case 'x':
                    if (success && GhostXPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostXPointPos = PointUnderGhost;
                    break;
                case 'c':
                    if (success && GhostCPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostCPointPos = PointUnderGhost;
                    break;
                case 'v':
                    if (success && GhostVPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostVPointPos = PointUnderGhost;
                    break;
                case 'b':
                    if (success && GhostBPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostBPointPos = PointUnderGhost;
                    break;
                }
                return success;
                break;

            case 1:
                success = moveRight(Mat, car, Pos);
                switch (car) {
                case 'x':
                    if (success && GhostXPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostXPointPos = PointUnderGhost;
                    break;
                case 'c':
                    if (success && GhostCPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostCPointPos = PointUnderGhost;
                    break;
                case 'v':
                    if (success && GhostVPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostVPointPos = PointUnderGhost;
                    break;
                case 'b':
                    if (success && GhostBPointPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    GhostBPointPos = PointUnderGhost;
                    break;
                }
                return success;
                break;
            }
            break;
        }
        break;
    }
    Mat [Pos.first][Pos.second] = car;
    return 0;
}
