//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_TYPES_H
#define TP11_NOTE_TYPES_H
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Énumération des couleurs utilisées dans le jeu.
 */
enum class Couleur_e {
    Locomotive, /**< Carte locomotive */
    Jaune,      /**< Couleur jaune */
    Bleu,       /**< Couleur bleue */
    Rouge,      /**< Couleur rouge */
    Vert,       /**< Couleur verte */
    Noir,       /**< Couleur noire */
    Blanc,      /**< Couleur blanche */
    Orange      /**< Couleur orange */
};

/**
 * @brief Énumération des types de cartes.
 */
enum class Carte_type_e {
    Train,  /**< Carte train */
    Ticket  /**< Ticket */
};

/**
 * @brief Énumération des types de pioche.
 */
enum class Pioche_type_e {
    CarteW, /**< Pioche de cartes wagon */
    Ticket  /**< Pioche de tickets */
};

/**
 * @brief Type alias pour une liste de noms de villes.
 */
using listeVille_t     = vector<string>;
/**
 * @brief Type alias pour une liste de voies ferrées.
 */
using listeVoieFerre_t = vector<vector<string>>;

/**
 * @brief Espace de noms pour les couleurs de terminal.
 */
namespace terminal {
    const std::string RESET  = "\033[0m";   /**< Réinitialise la couleur */
    const std::string RED    = "\033[1;31m"; /**< Couleur rouge */
    const std::string GREEN  = "\033[1;32m"; /**< Couleur verte */
    const std::string YELLOW = "\033[1;33m"; /**< Couleur jaune */
    const std::string BLUE   = "\033[1;34m"; /**< Couleur bleue */
}

#endif //TP11_NOTE_TYPES_H