/**
 * \file EasterEggs.cpp
 * \make all easter eggs
 * \author Adrien Lacroix
 * \version 1.0
 * \date 4 mai 2021
 */
#include <iostream>
#include <vector>
#include "src/pacman/headers/Doc_Prof/type.h"
#include "src/pacman/headers/models.h"
using namespace std;

/**
 * @brief Easter_Eggs Set condition of alls EasterEggs
 * @param PosPlayer1
 * @param PosEasterEgg1
 * @param PosEasterEgg2
 * @param PosEasterEgg3
 * @param PosEasterEgg4
 * @param PosEasterEgg5
 */
void Easter_Eggs (CPosition & PosPlayer1, CPosition & PosEasterEgg1, CPosition & PosEasterEgg2, CPosition & PosEasterEgg3, CPosition & PosEasterEgg4, CPosition & PosEasterEgg5) {

    if (PosPlayer1 == PosEasterEgg1) {
        Colors(PGreen);
        cout << "Félicitation ! Vous avez trouvé un Easter Egg posé par Adrien LACROIX, le principal dévellopeur du jeu !!!!!" << endl <<
                "Vous lui devez tout le fonctionnement des deplacements et le gameplay" << endl <<
                "Pour en savoir Plus sur les autres dévellopeurs du jeu, cherchez les 4 autres Easter Eggs" << endl;
        Colors(KReset);
    }
    if (PosPlayer1 == PosEasterEgg2) {
        Colors(PGreen);
        cout << "Félicitation ! Vous avez trouvé un Easter Egg posé par Adrien LACROIX, le principal dévellopeur du jeu !!!!!" << endl <<
                "Mais il n'a pas travaillé seul ! Il était avec Constant ALBEROLA" << endl <<
                "Vous lui devez tout le fonctionnement du menu et de l'affichage du jeu" << endl <<
                "Pour en savoir Plus sur les autres dévellopeurs du jeu, cherchez les 4 autres Easter Eggs" << endl;
        Colors(KReset);
    }
    if (PosPlayer1 == PosEasterEgg3) {
        Colors(PGreen);
        cout << "Félicitation ! Vous avez trouvé un Easter Egg posé par Adrien LACROIX, le principal dévellopeur du jeu !!!!!" << endl <<
                "Mais il n'a pas travaillé seul ! Il été avec Thomas CELESCHI" << endl <<
                "Vous lui devez le mode labirynthe" << endl <<
                "Pour en savoir Plus sur les autres dévellopeurs du jeu, cherchez les 4 autres Easter Eggs" << endl;
        Colors(KReset);
    }
    if (PosPlayer1 == PosEasterEgg4) {
        Colors(PGreen);
        cout << "Félicitation ! Vous avez trouvé un Easter Egg posé par Adrien LACROIX, le principal dévellopeur du jeu !!!!!" << endl <<
                "Mais il n'a pas travaillé seul ! Il été avec Oussama TALBI" << endl <<
                "Vous lui devez tout le fonctionnement des deplacements aleatoire des bots et le choix des couleurs du jeu" << endl <<
                "Pour en savoir Plus sur les autres dévellopeurs du jeu, cherchez les 4 autres Easter Eggs" << endl;
        Colors(KReset);
    }
    if (PosPlayer1 == PosEasterEgg5) {
        Colors(PGreen);
        cout << "Félicitation ! Vous avez trouvé un Easter Egg posé par Adrien LACROIX, le principal dévellopeur du jeu !!!!!" << endl <<
                "Mais il n'a pas travaillé seul ! Il été avec Julian CAYUELA" << endl <<
                "Vous lui devez le design de toutes les maps" << endl <<
                "Pour en savoir Plus sur les autres dévellopeurs du jeu, cherchez les 4 autres Easter Eggs" << endl;
        Colors(KReset);
    }
}
