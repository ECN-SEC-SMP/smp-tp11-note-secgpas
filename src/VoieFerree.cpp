#include <iostream>
#include "VoieFerree.h"

using namespace std;

VoieFerree::VoieFerree(Ville *v1, Ville *v2, int p, Couleur_e couleur) :
    ville1(v1),
    ville2(v2),
    poids(p),
    c(couleur) {
    //proprio = nullptr;
}

// Joueur* VoieFerree::getProprio(){
//     return proprio;
// }
//
// void setProprio(Joueur j){
//     proprio = &j;
// }

int VoieFerree::getPoids() {
    return poids;
}

Ville* VoieFerree::getVille1(){
    return ville1;
}

Ville* VoieFerree::getVille2(){
    return ville2;
}

Couleur_e VoieFerree::getCouleur() {
    return c;
}

// bool estDispo() {
//     return (proprio == nullptr);
// }
