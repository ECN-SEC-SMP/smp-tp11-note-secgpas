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

namespace terminal {
    const std::string RESET  = "\033[0m";
    const std::string RED    = "\033[1;31m";
    const std::string GREEN  = "\033[1;32m";
    const std::string YELLOW = "\033[1;33m";
    const std::string BLUE   = "\033[1;34m";
}

#endif //TP11_NOTE_TYPES_H