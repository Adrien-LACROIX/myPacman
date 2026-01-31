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
#include <fstream>
#include <string>
#include <ctime> // pour avoir le time() [pas sûr que ce soit obligatoire]
#include <cstdlib> // pour avoir le rand()

#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"
#include "src/pacman/src/class.cpp"
#include "src/pacman/src/matrix.cpp"


using namespace std;
char choice ; // declare char choice

/**
 * @brief Menu print the menu
 */
void  Menu() {
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
MapSettings Random() {
    MapSettings mapSettings;
    srand(time(NULL)); // pas sûr qque ce soit obligatoire
    int mapchoice = rand()%3 + 1; // mapchoice prend une valeur aléatoire entre 1 et 3
    switch (mapchoice)
    {
        case 1 :
            mapSettings.linkMap = "map4"; //Link of the map file
            mapSettings.lignes = 21;       // map's size
            mapSettings.columns = 30;       // map's size

            mapSettings.player.first = 0;  //y coordonate of the PacMan's start position
            mapSettings.player.second = 28;  //x coordonate of the PacMan's start position

            mapSettings.finish.first = 20;    //y coordonate of the Finish point's position
            mapSettings.finish.second = 3;     //x coordonate of the Finish point's position
            break;

        case 2 :
            mapSettings.linkMap = "map5"; //Link of the map file
            mapSettings.lignes = 37;       //map's size
            mapSettings.columns = 34;        //map's size

            mapSettings.player.first = 36;  //y coordonate of the PacMan's start position
            mapSettings.player.second = 17;  //x coordonate of the PacMan's start position

            mapSettings.finish.first = 0;     //y coordonate of the Finish point's position
            mapSettings.finish.second = 1;     //x coordonate of the Finish point's position
            break ;

        case 3 :
            mapSettings.linkMap = "map6"; //Link of the map file
            mapSettings.lignes = 46;       // map's size
            mapSettings.columns = 58;       // map's size

            mapSettings.player.first = 0;  //y coordonate of the PacMan's start position
            mapSettings.player.second = 26; //x coordonate of the PacMan's start position

            mapSettings.finish.first = 45;    //y coordonate of the Finish point's position
            mapSettings.finish.second = 1;     //x coordonate of the Finish point's position
            break ;
    }
    return tokens;
}

/**
 * @brief ChoixMenu let the user choose the level and the game mode
 */
MapSettings ChoiceMenu(){
    MapSettings mapSettings;
    cout << "choisissez une map" << endl; // ask chose a map or change setting
    cin >> choice ; // enter choix value

    switch(choice)
    {
    case '1':
        mapSettings.linkMap = "map1"; //Link of the map file
        mapSettings.lignes = 15;       // map's size
        mapSettings.columns = 21;       // map's size

        mapSettings.ghost1.first = 1; // y coordonate of the start position of the ghost number one
        mapSettings.ghost1.second = 1; // x coordonate of the start position of the ghost number one

        mapSettings.ghost2.first = 13; // y coordonate of the start position of the ghost number two
        mapSettings.ghost2.second = 1; // x coordonate of the start position of the ghost number two

        mapSettings.ghost3.first = 13; // y coordonate of the start position of the ghost number three
        mapSettings.ghost3.second = 19; // x coordonate of the start position of the ghost number three

        mapSettings.ghost4.first = 1; // y coordonate of the start position of the ghost number four
        mapSettings.ghost4.second = 19; // x coordonate of the start position of the ghost number four

        mapSettings.player.first = 7;  //y coordonate of the PacMan's start position
        mapSettings.player.second = 10;  //x coordonate of the PacMan's start position

        break;

    case '2':
        mapSettings.linkMap = "map2"; //Link of the map file
        mapSettings.lignes = 28;       // map's size
        mapSettings.columns = 31;       // map's size

        mapSettings.ghost1.first = 1; // y coordonate of the start position of the ghost number one
        mapSettings.ghost1.second = 1; // x coordonate of the start position of the ghost number one

        mapSettings.ghost2.first = 26; // y coordonate of the start position of the ghost number two
        mapSettings.ghost2.second = 1; // x coordonate of the start position of the ghost number two

        mapSettings.ghost3.first = 26; // y coordonate of the start position of the ghost number three
        mapSettings.ghost3.second = 29; // x coordonate of the start position of the ghost number three

        mapSettings.ghost4.first = 1;  // y coordonate of the start position of the ghost number four
        mapSettings.ghost4.second = 29; // x coordonate of the start position of the ghost number four

        mapSettings.player.first = 13;  //y coordonate of the PacMan's start position
        mapSettings.player.second = 14;  //x coordonate of the PacMan's start position

        mapSettings.eggs.egg1.first = 11;
        mapSettings.eggs.egg1.second = 14;

        mapSettings.eggs.egg2.first = 26;
        mapSettings.eggs.egg2.second = 11;

        mapSettings.eggs.egg3.first = 4;
        mapSettings.eggs.egg3.second = 10;

        mapSettings.eggs.egg4.first = 1;
        mapSettings.eggs.egg4.second = 18;

        mapSettings.eggs.egg5.first = 23;
        mapSettings.eggs.egg5.second = 17;

        break;

    case '3':
        mapSettings.linkMap = "map3"; //Link of the map file
        mapSettings.lignes = 31;       // map's size
        mapSettings.columns = 28;       // map's size

        mapSettings.ghost1.first = 1; // y coordonate of the start position of the ghost number one
        mapSettings.ghost1.second = 1; // x coordonate of the start position of the ghost number one

        mapSettings.ghost2.first = 29; // y coordonate of the start position of the ghost number two
        mapSettings.ghost2.second = 1; // x coordonate of the start position of the ghost number two

        mapSettings.ghost3.first = 29; // y coordonate of the start position of the ghost number three
        mapSettings.ghost3.second = 26; // x coordonate of the start position of the ghost number three

        mapSettings.ghost4.first = 1;  // y coordonate of the start position of the ghost number four
        mapSettings.ghost4.second = 26; // x coordonate of the start position of the ghost number four

        mapSettings.player.first = 14;  //y coordonate of the PacMan's start position
        mapSettings.player.second = 14;  //x coordonate of the PacMan's start position

        break;

    case '4':
        Clear_Screen();
        Random(); //call the random function
        break;
    }
    return tokens;
}
