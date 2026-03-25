#include <iostream>
#include "Ville.h"
#include "fonctionAnnexe.h"


using namespace std;

Ville::Ville(int i){
    ville_ = vectVille[i]; 
}

string Ville::getNomVille(){
    return ville_;
}

bool Ville::estAdjacent(int i){
    if (i > vectVille.size() || i < 0){
        return false;
    }
    for (int k = 0; k < villesAdjacentes.size(); k++){
        if (vectVille[i] == villesAdjacentes[k]->ville_){ 
            return true;
        }
    }
    return false;
}


void Ville::afficheAdjacent(){
    for (int i = 0; i < villesAdjacentes.size(); i++){
        cout << villesAdjacentes[i]->ville_ << endl;
    }
}

vector<Ville*> Ville::getAdjacent(){
    return villesAdjacentes;
}

void Ville::ajoutVilleAdjacente(Ville* v){
    villesAdjacentes.push_back(v);
}