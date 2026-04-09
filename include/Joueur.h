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

/**
 * @brief Classe représentant un joueur dans le jeu.
 */
class Joueur {
    private:
        /**
         * @brief Couleur du joueur.
         */
        Couleur_e couleur;
        /**
         * @brief Main des cartes du joueur, mappée par couleur.
         */
        map<Couleur_e, int> mainCarte;
        /**
         * @brief Main des tickets du joueur.
         */
        vector<Ticket*> mainTicket;
        /**
         * @brief Nombre de wagons restants du joueur.
         */
        int mainWagon;

    public:
        /**
         * @brief Constructeur de Joueur.
         * @param c La couleur du joueur.
         */
        Joueur(Couleur_e c);

        /**
         * @brief Retourne le nombre de wagons restants.
         * @return Le nombre de wagons.
         */
        int getMainWagon() const;
        /**
         * @brief Retourne la couleur du joueur.
         * @return La couleur.
         */
        Couleur_e getCouleur() const;
        /**
         * @brief Retourne la main des cartes.
         * @return La map des cartes par couleur.
         */
        map<Couleur_e, int> getMainCarte() const;
        /**
         * @brief Retourne la main des tickets.
         * @return Le vecteur des tickets.
         */
        vector<Ticket*> getMainTicket() const;
        /**
         * @brief Retourne le nombre de tickets réussis.
         * @return Le nombre de tickets réussis.
         */
        int getNbTicketReussis() const;

        /**
         * @brief Permet au joueur de piocher des cartes.
         * @param nbAPiocher Nombre de cartes à piocher.
         * @param type La pioche depuis laquelle piocher.
         */
        void piocher(int nbAPiocher, Pioche& type);
        /**
         * @brief Permet au joueur de poser des wagons sur une voie.
         * @param a Ville de départ.
         * @param b Ville d'arrivée.
         * @param c Couleur de la voie.
         * @param plateau Le plateau de jeu.
         */
        void poserWagon(Ville a, Ville b, Couleur_e c, Plateau& plateau);
        /**
         * @brief Permet au joueur de défausser des tickets et d'en piocher de nouveaux.
         * @param piocheTicket La pioche de tickets.
         */
        void defausser(Pioche& piocheTicket);
        /**
         * @brief Affiche la main du joueur.
         */
        void afficherMain() const;
};

#endif