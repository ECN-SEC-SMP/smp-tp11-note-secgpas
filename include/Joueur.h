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
        /** @brief Couleur du joueur. */
        Couleur_e couleur;
        /** @brief Main des cartes train du joueur, mappée par couleur. */
        map<Couleur_e, int> mainCarte;
        /** @brief Main des tickets du joueur. */
        vector<Ticket*> mainTicket;
        /** @brief Nombre de wagons restants du joueur. */
        int mainWagon;

    public:
        /**
         * @brief Constructeur de Joueur.
         * @param c La couleur du joueur.
         */
        Joueur(Couleur_e c);

        /** @brief Retourne le nombre de wagons restants. */
        int getMainWagon() const;
        /** @brief Retourne la couleur du joueur. */
        Couleur_e getCouleur() const;
        /** @brief Retourne la main des cartes train. */
        map<Couleur_e, int> getMainCarte() const;
        /** @brief Retourne la main des tickets. */
        vector<Ticket*> getMainTicket() const;

        /**
         * @brief Retourne le nombre de tickets effectivement réussis.
         * Appelle estRealise() sur chaque ticket de la main.
         * @return Le nombre de tickets réussis.
         */
        int getNbTicketReussis() const;

        /**
         * @brief Permet au joueur de piocher des cartes.
         * Gère le recyclage de la défausse si la pioche est vide.
         * @param nbAPiocher Nombre de cartes à piocher.
         * @param type La pioche depuis laquelle piocher.
         */
        void piocher(int nbAPiocher, Pioche& type);

        /**
         * @brief Tente de poser des wagons sur la voie entre a et b.
         * Vérifie les ressources, défausse les cartes utilisées (avec gestion
         * des locomotives comme jokers) et appelle verifierTickets().
         * @param a Ville de départ.
         * @param b Ville d'arrivée.
         * @param couleurVoie Couleur de la voie à prendre.
         * @param plateau Le plateau de jeu.
         * @return true si la pose a réussi, false sinon.
         */
        bool poserWagon(Ville a, Ville b, Couleur_e couleurVoie, Plateau& plateau);

        /**
         * @brief Vérifie tous les tickets en main et annonce les tickets réussis.
         */
        void verifierTickets();

        /**
         * @brief Défausse jusqu'à 2 tickets dans la défausse de la pioche et en pioche de nouveaux.
         * @param piocheTicket La pioche de tickets.
         */
        void defausser(Pioche& piocheTicket);

        /** @brief Affiche la main du joueur (cartes + tickets avec statut). */
        void afficherMain() const;
};

#endif