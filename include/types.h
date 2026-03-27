//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_TYPES_H
#define TP11_NOTE_TYPES_H
#include <vector>
#include <iostream>

using namespace std;

enum class Couleur_e {
    Locomotive,
    Jaune,
    Bleu,
    Rouge,
    Vert,
    Noir,
    Blanc,
    Orange
};

enum class Carte_type_e {
    Train,
    Ticket
};

enum class Pioche_type_e {
    CarteW,
    Ticket
};

using listeVille_t     = vector<string>;
using listeVoieFerre_t = vector<vector<string>>;

#endif //TP11_NOTE_TYPES_H