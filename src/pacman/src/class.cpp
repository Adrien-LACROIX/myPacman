/**
 * \file class.cpp
 * \define all classes
 * \author Adrien Lacroix
 * \version 1.0
 * \date 30th January 2026
 */

 #include "src/pacman/headers/Doc_Prof/type.h"
#include <iostream>
#include <vector>
#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"


class Player {
    public:
        const char car
        CPosition Pos
        int cpt;

        bool Move (CMat & Mat, char Move, CPosition  & Pos) {
            char car = Mat[Pos.first][Pos.second]; //declare the variable car and set his value at the player one's position

            switch (Move) {
            case 'Z':       //if the case 'Z' is enter
                success = moveUp(Mat, car, Pos);
                if (Pos.first == MapY-1) { //if the player is at the map's top
                    Mat [0][Pos.second] = KEmpty;
                } else {
                    Mat [Pos.First+1][Pos.second] = KEmpty;
                }
                break;

            case 'Q':       //if the case 'Q' is enter
                success = moveLeft(Mat, car, Pos);
                if (Pos.first == MapX-1) { //if the player is at the map's top
                    Mat [Pos.First][0] = KEmpty;
                } else {
                    Mat [Pos.First][Pos.second+1] = KEmpty;
                }
                break;

            case 'S':
                success = moveDown(Mat, car, Pos);
                if (Pos.first == 0) { //if the player is at the map's top
                    Mat [MapY-1][Pos.second] = KEmpty;
                } else {
                    Mat [Pos.First-1][Pos.second] = KEmpty;
                }
                break;

            case 'D':
                success = moveRight(Mat, car, Pos);
                if (Pos.first == 0) { //if the player is at the map's top
                    Mat [Pos.First][MapX-1] = KEmpty;
                } else {
                    Mat [Pos.First][Pos.second-1] = KEmpty;
                }
                break;
            }
            Mat [Posplayer1.first][Posplayer1.second] = car;

            return 0;
        }
}

class Ghost {
    public:
        const char car
        CPosition Pos
        bool pointOnPos

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
                    if (success && pointOnPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    return true;
                    break;
                }
                else if (Pos.first < Posplayer1.first){ //down
                    cout << "Ghost want to move down" << endl;
                    success = moveDown(Mat, car, Pos);
                    if (success && pointOnPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    return true;
                    break;
                } else {
                    return false;
                    break;
                }

            case MOVEHONRIZONTAL://horizontal direction
                cout << "Try horizontal mouvement" << endl;
                if (Pos.second > Posplayer1.second ) { //left
                    cout << "Ghost want to move left" << endl;
                    success = moveLeft(Mat, car, Pos);
                    if (success && pointOnPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    return true;
                    break;
                }
                else if (Pos.second < Posplayer1.first ) { //right
                    cout << "Ghost want to move right" << endl;
                    success = moveRight(Mat, car, Pos);
                    if (success && pointOnPos) {
                        Mat [Pos.first][Pos.second] = KPoint;
                    }
                    return true;
                    break;
                } else {
                    return false;
                    break;
                }
            }
            Mat [Pos.first][Pos.second] = car;
            return 0;
        }

}