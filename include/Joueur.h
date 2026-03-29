#ifndef SMP_TP8_DAVID_RIANA_VOIEFERREE_H
#define SMP_TP8_DAVID_RIANA_VOIEFERREE_H

#include <iostream>
#include <map>
#include <vector>
#include "fonctionAnnexe.h"
#include "types.h"
#include "Carte.h"
#include "Pioche.h"
#include "Ville.h"

using namespace std;

class Joueur{
    private : 
        Couleur_e couleur;
        map<Couleur_e,int> mainCarte;
        vector<Ticket*> mainTicket;
        int mainWagon;
    public :
        Joueur(Couleur_e);
        int getMainWagon();
        map<Couleur_e,int> getMainCarte();
        void piocher(Pioche& type);
        void poserWagon(Ville* a, Ville* b, Couleur_e c);
        void defausser();
        void afficherMain();
        Ticket rendreVisible();
};

#endif