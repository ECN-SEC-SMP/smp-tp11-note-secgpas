//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_TYPES_H
#define TP11_NOTE_TYPES_H
#include <vector>

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

using listeVille_t     = std::vector<std::string>;
using listeVoieFerre_t = std::vector<std::vector<std::string>>;

#endif //TP11_NOTE_TYPES_H