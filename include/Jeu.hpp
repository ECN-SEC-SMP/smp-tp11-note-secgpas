#ifndef JEU_HPP
#define JEU_HPP
#include "Pioche.h"
#include "Joueur.h"
#include "Plateau.h"
#include "NoeudVille.h"
#include "VoieFerre.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Jeu {
    private: 
        int nbJoueur;
        vector<Joueur> joueurs;
        Plateau *p;
        Pioche *tickets;
        Pioche *train;
    public:
        Jeu(int nbJoueur);
        bool estFinie();
        void partie();
};

#endif