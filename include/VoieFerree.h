#ifndef SMP_TP8_DAVID_RIANA_VOIEFERREE_H
#define SMP_TP8_DAVID_RIANA_VOIEFERREE_H

#include "types.h"
#include "Ville.h"
#include "Joueur.h"

using namespace std;

/**
 * @brief Classe représentant une voie ferrée reliant deux villes.
 */
class VoieFerree{
    /**
     * @brief Pointeur vers la première ville.
     */
    Ville *ville1;
    /**
     * @brief Pointeur vers la deuxième ville.
     */
    Ville *ville2;
    /**
     * @brief Pointeur vers le joueur propriétaire de la voie.
     */
    Joueur* proprio;
    /**
     * @brief Poids de la voie (longueur).
     */
    int poids;
    /**
     * @brief Couleur de la voie.
     */
    Couleur_e c;
    public:
    /**
     * @brief Constructeur de VoieFerree.
     * @param v1 Pointeur vers la ville 1.
     * @param v2 Pointeur vers la ville 2.
     * @param p Poids de la voie.
     * @param c Couleur de la voie.
     */
    VoieFerree(Ville *v1, Ville *v2, int p, Couleur_e c);
    /**
     * @brief Retourne le propriétaire de la voie.
     * @return Pointeur vers le joueur propriétaire.
     */
    Joueur* getProprio();
    /**
     * @brief Définit le propriétaire de la voie.
     * @param j Pointeur vers le joueur.
     */
    void setProprio(Joueur* j);
    /**
     * @brief Retourne le poids de la voie.
     * @return Le poids.
     */
    int getPoids();
    /**
     * @brief Retourne la couleur de la voie.
     * @return La couleur.
     */
    Couleur_e getCouleur();
    /**
     * @brief Vérifie si la voie est disponible (sans propriétaire).
     * @return true si disponible, false sinon.
     */
    bool estDispo();
    /**
     * @brief Retourne la première ville.
     * @return Pointeur vers la ville 1.
     */
    Ville* getVille1();
    /**
     * @brief Retourne la deuxième ville.
     * @return Pointeur vers la ville 2.
     */
    Ville* getVille2();

    /**
     * @brief Retourne la première ville (version const).
     * @return Pointeur vers la ville 1.
     */
    Ville* getVille1() const {
        return ville1;
    };

    /**
     * @brief Retourne la deuxième ville (version const).
     * @return Pointeur vers la ville 2.
     */
    Ville* getVille2() const {
        return ville2;
    }

};


#endif