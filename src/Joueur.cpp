#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(Couleur_e c){
    couleur = c;
    for (int i = 0; i < 7; i++){
        mainCarte.emplace(static_cast<Couleur_e>(i), 0);
    }
    mainWagon = 20;
}



