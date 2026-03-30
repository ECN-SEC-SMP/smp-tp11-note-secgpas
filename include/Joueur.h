#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <map>
#include <vector>
#include "types.h"
#include "Carte.h"
#include "Pioche.h"
#include "Ville.h"

class Plateau; 

using namespace std;

class Joueur {
    private:
        Couleur_e couleur;
        map<Couleur_e, int> mainCarte;
        vector<Ticket*> mainTicket;
        int mainWagon;

    public:
        Joueur(Couleur_e c);

        // Getteurs
        int getMainWagon() const;
        Couleur_e getCouleur() const;
        map<Couleur_e, int> getMainCarte() const;
        vector<Ticket*> getMainTicket() const;
        int getNbTicketReussis() const;

        // Méthodes principales
        void piocher(int nbAPiocher, Pioche& type);
        void poserWagon(Ville a, Ville b, Couleur_e c, Plateau& plateau);
        void defausser(Pioche& piocheTicket);                    
        void afficherMain() const;
};

#endif