//
// Created by David PROSPÉRIN on 22/03/2026.
//

#ifndef TP11_NOTE_PIOCHE_H
#define TP11_NOTE_PIOCHE_H

#include <vector>
#include "Carte.h"
#include "types.h"
using namespace std;

class Pioche {
    vector<Carte*> deck_;
    vector<Carte*> defausse_;
    Pioche_type_e type_;

    public:
    /**
     * Créer une pioche de type CarteW ou Ticket.
     * La pioche de type CarteW contient 10 cartes de chaque couleur (Jaune, Bleu, Rouge, Vert, Noir, Blanc)
     * et 12 cartes Locomotive.
     * La pioche de tickets contient 32 tickets.
     * Puis mélange les cartes de la pioche.
     * @param type Le type de la pioche (CarteW ou Ticket)
     */
    Pioche(Pioche_type_e type);

    void melanger();
    bool estPiocheVide() const;

    Pioche_type_e getPiocheType() const {
        return type_;
    };

    vector<Carte*> & getDeck() {
        return deck_;
    }

    vector<Carte*> & getDefausse() {
        return defausse_;
    }

    void popLastCarte() {
        if (!deck_.empty()) {
            deck_.pop_back();
        }
    }

    void pushDefausse(Carte* carte) {
        defausse_.push_back(carte);
    }
};

#endif //TP11_NOTE_PIOCHE_H