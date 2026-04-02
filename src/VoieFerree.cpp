#include <iostream>
#include "VoieFerree.h"
#include "Joueur.h"

using namespace std;

/**
 * @brief Constructeur de la classe VoieFerree qui va permettre de renseigner les informations liées aux arêtes du graphe
 * @param v1 pointeur vers la ville1
 * @param v2 pointeur vers la ville2
 * @param p poids de l'arête (longueur du train)
 * @param couleur couleur associée à la voie
 */
VoieFerree::VoieFerree(Ville *v1, Ville *v2, int p, Couleur_e couleur) :
    ville1(v1),
    ville2(v2),
    poids(p),
    c(couleur) {
    //proprio = nullptr;
}

/**
 * @brief Accesseur au "propriétaire" de la voie. Permet de savoir quel joueur a posé ses wagon sur la voie
 * @return un pointeur vers le joueur ayant posé ses wagons sur la voie ferrée
 */
Joueur* VoieFerree::getProprio(){
    return proprio;
}

/**
 * @brief Mutateur qui permet de modifier l'attribut proprio lorsqu'un joueur pose ses trains
 */
void VoieFerree::setProprio(Joueur* j){
    proprio = j;
}

/**
 * @brief Accesseur vers le poids
 * @return renvoie le poids (nombre de wagons qui composent l'arête)
 */
int VoieFerree::getPoids() {
    return poids;
}

/**
 * @brief Accesseur vers la ville1
 * @return Un pointeur vers la ville1
 */
Ville* VoieFerree::getVille1(){
    return ville1;
}

/**
 * @brief Accesseur vers la ville2
 * @return Un pointeur vers la ville2
 */
Ville* VoieFerree::getVille2(){
    return ville2;
}

/**
 * @brief Accesseur vers la couleur de la voie
 * @return La couleur de la voie ferrée
 */
Couleur_e VoieFerree::getCouleur() {
    return c;
}

/**
 * @brief Teste si la voie ferrée est libre.
 * @return Booléen true si elle est libre false sinon
 */
bool VoieFerree::estDispo() {
    return (proprio == nullptr);
}
