#ifndef SMP_TP8_DAVID_RIANA_ANNEXE_H
#define SMP_TP8_DAVID_RIANA_ANNEXE_H

#include <iostream>
#include <vector>
#include "types.h"

using namespace std;

/**
 * @brief Vecteur global des noms de villes.
 */
extern listeVille_t vectVille;
/**
 * @brief Vecteur global des voies ferrées.
 */
extern listeVoieFerre_t vectVoieFerree;

/**
 * @brief Ouvre le fichier map et charge les données.
 * @param nomFichier Nom du fichier map.
 * @return true si réussi, false sinon.
 */
bool ouvrirFichierMap(const string nomFichier);
/**
 * @brief Affiche le vecteur des villes.
 * @param v Vecteur des villes.
 */
void afficheVectVille(vector<string> v);
/**
 * @brief Affiche le vecteur des voies ferrées.
 * @param v Vecteur des voies ferrées.
 */
void afficheVectVoieFerree(vector<string> v);
/**
 * @brief Retourne la couleur correspondante à la chaîne.
 * @param couleur Chaîne représentant la couleur.
 * @return La couleur énumérée.
 */
Couleur_e getCouleur(const string &couleur);


#endif