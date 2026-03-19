//
#ifndef SMP_TP8_DAVID_RIANA_VOIEFERREE_H
#define SMP_TP8_DAVID_RIANA_VOIEFERREE_H

#include <iostream>
#include<array>
#include "Joueur.h"

using namespace std;

class VoieFerree{
    private:
        Ville_e ville1;
        Ville_e ville2;
        Joueur* proprio;
        int poids;
        Couleur_e c;
    public:
        VoieFerree(Ville_e v1, Ville_e v2,int p,Couleur_e c);
        Joueur* getProprio();
        int getPoids();
        Couleur_e getCouleur();        
        bool estDispo();

};


#endif