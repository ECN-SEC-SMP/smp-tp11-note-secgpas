#include <iostream>
#include<array>

#include "VoieFerree.h"
using namespace std;

VoieFerree::VoieFerree(Ville_e v1, Ville_e v2,int p,Couleur_e couleur){
    ville1 = v1;
    ville2 = v2;
    proprio = nullptr;
    poids = p;
    c = couleur;
}

Joueur* VoieFerree::getProprio(){
    return proprio;
}

void setProprio(Joueur j){
    proprio = &j;
}

int VoieFerree::getPoids(){
    return poids;
}

Couleur_e VoieFerree::getCouleur(){
    return c;
}       

bool estDispo(){
    return (proprio == nullptr);
}

