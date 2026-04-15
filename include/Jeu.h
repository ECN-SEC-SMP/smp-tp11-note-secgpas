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

/**
 * @brief Classe représentant le jeu de plateau.
 */
class Jeu {
    private:
        /**
         * @brief Vecteur des joueurs participants.
         */
        vector<Joueur> joueurs;
        /**
         * @brief Le plateau de jeu.
         */
        Plateau p;
        /**
         * @brief Pioche des tickets.
         */
        Pioche tickets;
        /**
         * @brief Pioche des cartes train.
         */
        Pioche train;
        /**
         * @brief Nombre de tours joués.
         */
        int nbTour;
        int nbTicketReussis;
    public:
        /**
         * @brief Constructeur de Jeu.
         * @param nbJoueur Nombre de joueurs.
         */
        Jeu(int nbJoueur, int nbTicket);
        /**
         * @brief Vérifie si la partie est finie.
         * @return true si finie, false sinon.
         */
        bool estFinie();
        /**
         * @brief Lance la partie.
         */
        void partie();
        /**
         * @brief Affiche l'état actuel du jeu.
         */
        void afficherEtat() const;
};

#endif