#ifndef SMP_TP8_DAVID_RIANA_VILLE_H
#define SMP_TP8_DAVID_RIANA_VILLE_H

#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief Définition de la classe Ville et des méthodes associées. Crée les sommets du graphe qui servira de plateau
 */
class Ville{
    private:
        string ville_;
        vector<Ville*> villesAdjacentes; //vector d'adjacence du sommet
    public : 
        Ville(int i); //indice de la ville qu'on veut dans vectVille
        Ville(string NomVille): ville_(NomVille) {};
        string getNomVille();
        void afficheAdjacent();
        bool estAdjacent(int i);

        vector<Ville *> &getAdjacent();
        void ajoutVilleAdjacente(Ville* v);
};



#endif