#ifndef SMP_TP8_DAVID_RIANA_ANNEXE_H
#define SMP_TP8_DAVID_RIANA_ANNEXE_H

#include <iostream>
#include <vector>
#include "types.h"

using namespace std;

/**
 * @brief Ouvre le fichier map et charge les villes et les voies ferrées dans les vecteurs correspondants.
 * @param nomFichier Nom du fichier map.
 * @param listeVoieFerre Vecteur qui contient les voies ferrées du jeu
 * @param listeVille Vecteur qui contient les villes du jeu
 * @return true si réussi, false sinon.
 */
bool ouvrirFichierMap(string nomFichier, listeVoieFerre_t &listeVoieFerre, listeVille_t &listeVille);
/**
 * @brief Affiche le vecteur des villes.
 * @param v Vecteur des villes.
 */
void afficheVectVille(listeVille_t v);
/**
 * @brief Affiche le vecteur des voies ferrées.
 * @param v Vecteur des voies ferrées.
 */
void afficheVectVoieFerree(listeVoieFerre_t v);
/**
 * @brief Retourne la couleur correspondante à la chaîne.
 * @param couleur Chaîne représentant la couleur.
 * @return La couleur énumérée.
 */
Couleur_e getCouleur(const string &couleur);


#endif