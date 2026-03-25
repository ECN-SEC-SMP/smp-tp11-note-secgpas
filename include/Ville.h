#ifndef SMP_TP8_DAVID_RIANA_VILLE_H
#define SMP_TP8_DAVID_RIANA_VILLE_H

#include<iostream>
#include <map>
#include<vector>

using namespace std;


class Ville{
    private:
        string ville_;
        vector<Ville*> villesAdjacentes; //vector d'adjacence du sommet
    public : 
        Ville(int i); //indice de la ville qu'on veut dans vectVille
        string getNomVille();
        //void afficheListeVille(); //c'est ptete pas hyper malin de mettre ca en methode
        void afficheAdjacent();
        bool estAdjacent(int i);
        vector<Ville*> getAdjacent();
        void ajoutVilleAdjacente(Ville* v);
};



#endif