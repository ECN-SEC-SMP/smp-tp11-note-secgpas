//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Pioche.h"
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

/**
 * Mélange aléatoirement les cartes du deck.
 */
void Pioche::melanger() {
    std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine());
}

/**
 * Vérifie si la pioche est vide.
 * @return true si la pioche est vide, false sinon.
 */
bool Pioche::estPiocheVide() const {
    return deck_.empty();
}