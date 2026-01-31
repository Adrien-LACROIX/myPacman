/**
 * \file class.cpp
 * \define all classes
 * \author Adrien Lacroix
 * \version 1.0
 * \date 30th January 2026
 */

#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"
#include "src/pacman/src/move.cpp"


class Player {
    public:
        const char car;
        CPosition Pos;
        CPosition lastPos;
        int cpt;

        bool Move (CMat & Mat, char nextMove, CPosition  & Pos) {
            Movement movement;
            bool returnValue;

            lastPos = Pos;
            car = Mat[Pos.first][Pos.second]; //set his value at the player one's position

            switch (nextMove) {
            case 'Z':       //if the case 'Z' is enter
                movement = moveUp(Mat, car, Pos);
                if (movement.success) {
                    if (movement.pointOnPos) {
                        ++cpt;
                        Mat [lastPos.first][lastPos.second] = KEmpty;
                    }
                    returnValue = true;
                } else {
                    returnValue = false:
                } 
                break;

            case 'Q':       //if the case 'Q' is enter
                movement = moveLeft(Mat, car, Pos);
                if (movement.success) {
                    if (movement.pointOnPos) {
                        cpt++;
                        Mat [lastPos.first][lastPos.second] = KEmpty;
                    }
                    returnValue = true;
                } else {
                    returnValue = false:
                } 
                break;

            case 'S':
                movement = moveDown(Mat, car, Pos);
                if (movement.success) {
                    if (movement.pointOnPos) {
                        cpt++;
                        Mat [lastPos.first][lastPos.second] = KEmpty;
                    }
                    returnValue = true;
                } else {
                    returnValue = false:
                } 
                break;

            case 'D':
                movement = moveRight(Mat, car, Pos);
                if (movement.success) {
                    if (movement.pointOnPos) {
                        cpt++;
                        Mat [lastPos.first][lastPos.second] = KEmpty;
                    }
                    returnValue = true;
                } else {
                    returnValue = false:
                } 
                break;
            }
            Mat [Posplayer1.first][Posplayer1.second] = car;

            return 0;
        }
}

class Ghost {
    public:
        const char car;
        CPosition Pos;
        CPosition lastPos;
        bool pointOnPos;
        

        bool MoveBot (CMat & Mat, char botchoice, CPosition & Posplayer1){

            # define MOVEVERTICAL       0
            # define MOVEHONRIZONTAL    1
            # define NBCOMMAND          2

            lastPos = Pos;
            bool returnValue;
            Movement movement;
            car = Mat [Pos.first][Pos.second];
            srand(time(0));

            switch (botchoice) { //choose a direction
            case MOVEVERTICAL: //vertical direction
                cout << "Try vertical mouvement" << endl;
                if(Pos.first > Posplayer1.first){ //up
                    cout << "Ghost want to move up" << endl;
                    movement = moveUp(Mat, car, Pos);
                    if (movement.success) {
                        if (movement.pointOnPos) {
                            Mat [lastPos.first][lastPos.second] = KPoint;
                        }
                        returnValue = true;
                    }
                }
                else if (Pos.first < Posplayer1.first){ //down
                    cout << "Ghost want to move down" << endl;
                    movement = moveDown(Mat, car, Pos);
                    if (movement.success) {
                        if (movement.pointOnPos) {
                            Mat [lastPos.first][lastPos.second] = KPoint;
                        }
                        returnValue = true;
                    }
                } else {
                    returnValue = false;
                }
                break;

            case MOVEHONRIZONTAL://horizontal direction
                cout << "Try horizontal mouvement" << endl;
                if (Pos.second > Posplayer1.second ) { //left
                    cout << "Ghost want to move left" << endl;
                    success = moveLeft(Mat, car, Pos);
                    if (movement.success) {
                        if (movement.pointOnPos) {
                            Mat [lastPos.first][lastPos.second] = KPoint;
                        }
                        returnValue = true;
                    }
                }
                else if (Pos.second < Posplayer1.first ) { //right
                    cout << "Ghost want to move right" << endl;
                    success = moveRight(Mat, car, Pos);
                    if (movement.success) {
                        if (movement.pointOnPos) {
                            Mat [lastPos.first][lastPos.second] = KPoint;
                        }
                        returnValue = true;
                    }
                } else {
                    returnValue = false;
                }
                break;
            }
            Mat [Pos.first][Pos.second] = car;
            return returnValue;
        }

}

class EasterEggs {
    public :
        CPosition egg1;
        CPosition egg2;
        CPosition egg3;
        CPosition egg4;
        CPosition egg5;
}

class MapSettings {
    private :
        CPosition player;
        CPosition ghost1;
        CPosition ghost2;
        CPosition ghost3;
        CPosition ghost4;
        CPosition finish;
        EasterEggs eggs;

    public :
        unsigned lignes, columns;
        string  linkMap;
}