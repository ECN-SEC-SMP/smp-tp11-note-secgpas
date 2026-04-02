#ifndef JEU_HPP
#define JEU_HPP
#include "Pioche.h"
#include "Joueur.h"
#include "Plateau.h"
#include "VoieFerree.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Jeu {
    private: 
        vector<Joueur> joueurs;
        Plateau p;
        Pioche tickets;
        Pioche train;
        int nbTour;
    public:
        Jeu(int nbJoueur);
        bool estFinie();
        void partie();
        void afficherEtat() const;
};

#endif