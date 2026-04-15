//
// Created by David PROSPÉRIN on 22/03/2026.
//

#ifndef TP11_NOTE_PIOCHE_H
#define TP11_NOTE_PIOCHE_H

#include <vector>
#include "Carte.h"
#include "types.h"
using namespace std;

/**
 * @brief Classe représentant une pioche de cartes dans le jeu.
 */
class Pioche {
    /**
     * @brief Deck de cartes de la pioche.
     */
    vector<Carte*> deck_;
    /**
     * @brief Pile de défausse.
     */
    vector<Carte*> defausse_;
    /**
     * @brief Type de la pioche (CarteW ou Ticket).
     */
    Pioche_type_e type_;

    public:
    /**
     * @brief Créer une pioche de type CarteW ou Ticket.
     * La pioche de type CarteW contient 10 cartes de chaque couleur (Jaune, Bleu, Rouge, Vert, Noir, Blanc)
     * et 12 cartes Locomotive.
     * La pioche de tickets contient 32 tickets.
     * Puis mélange les cartes de la pioche.
     * @param type Le type de la pioche (CarteW ou Ticket)
     */
    Pioche(Pioche_type_e type);

    /**
     * @brief Mélange aléatoirement les cartes du deck.
     */
    void melanger();
    /**
     * @brief Vérifie si la pioche est vide.
     * @return true si la pioche est vide, false sinon.
     */
    bool estPiocheVide() const;

    /**
     * @brief Retourne le type de la pioche.
     * @return Le type de la pioche.
     */
    Pioche_type_e getPiocheType() const {
        return type_;
    };

    /**
     * @brief Retourne le deck de cartes.
     * @return Référence vers le vecteur du deck.
     */
    vector<Carte*> & getDeck() {
        return deck_;
    }

    /**
     * @brief Retourne la pile de défausse.
     * @return Référence vers le vecteur de défausse.
     */
    vector<Carte*> & getDefausse() {
        return defausse_;
    }

    /**
     * @brief Retire la dernière carte du deck.
     */
    void popLastCarte() {
        if (!deck_.empty()) {
            deck_.pop_back();
        }
    }

    /**
     * @brief Ajoute une carte à la défausse.
     * @param carte Pointeur vers la carte à ajouter.
     */
    void pushDefausse(Carte* carte) {
        defausse_.push_back(carte);
    }
};

#endif //TP11_NOTE_PIOCHE_H