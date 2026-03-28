#ifndef SMP_TP8_DAVID_RIANA_VOIEFERREE_H
#define SMP_TP8_DAVID_RIANA_VOIEFERREE_H

#include "types.h"
#include "Ville.h"
//#include "Joueur.h"

using namespace std;

class VoieFerree{
        Ville *ville1;
        Ville *ville2;
        //Joueur* proprio;
        int poids;
        Couleur_e c;
    public:
        VoieFerree(Ville *v1, Ville *v2, int p, Couleur_e c);
        //Joueur* getProprio();
        //void setProprio(Joueur j);
        int getPoids();
        Couleur_e getCouleur();        
        bool estDispo();

        Ville* getVille1() const {
            return ville1;
        };

        Ville* getVille2() const {
            return ville2;
        }

};


#endif