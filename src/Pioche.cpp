//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Pioche.h"
#include "Plateau.h"
#include <algorithm>
#include <random>
#include <vector>
#include "config.h"
using namespace std;

/**
 * Mélange aléatoirement les cartes du deck.
 */
void Pioche::melanger() {
    if (!TRUE_RANDOM) {
        std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine());
    } else {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck_.begin(), deck_.end(), g);
    }
}

/**
 * Vérifie si la pioche est vide.
 * @return true si la pioche est vide, false sinon.
 */
bool Pioche::estPiocheVide() const {
    return deck_.empty();
}

Pioche::Pioche(Pioche_type_e type) {
    type_ = type;

    if (type == Pioche_type_e::CarteW) {
        for (int i = 0; i < NB_CTRAIN_PAR_COULEUR; i++) {
            deck_.push_back(new CTrain(Couleur_e::Jaune));
            deck_.push_back(new CTrain(Couleur_e::Bleu));
            deck_.push_back(new CTrain(Couleur_e::Rouge));
            deck_.push_back(new CTrain(Couleur_e::Vert));
            deck_.push_back(new CTrain(Couleur_e::Noir));
            deck_.push_back(new CTrain(Couleur_e::Blanc));
        }

        for (int i = 0; i < NB_CTRAIN_LOCOMOTIVE; i++) {
            deck_.push_back(new CTrain(Couleur_e::Locomotive));
        }
    } else if (type == Pioche_type_e::Ticket) {
        Plateau p(MAP_FILE_PATH);
        Ticket::loadFromCSVFile(&p, deck_, TICKET_FILE_PATH);
    }

    melanger();
};