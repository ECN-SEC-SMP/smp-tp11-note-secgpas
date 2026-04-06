#include <iostream>
#include "Ville.h"
#include "fonctionAnnexe.h"


using namespace std;

/**
 * @brief Accesseur qui renvoie le nom de la ville sur laquelle est appliquée la méthode.
 * @return Renvoie le nom de la ville sous forme de string
 */
string Ville::getNomVille() const {
    return ville_;
}

/**
 * @brief Méthode qui teste si une ville est adjacente à une autre.
 * @param ville Pointeur vers une ville à tester
 * @return Booléen à true si la ville i est adjacente à la ville courante et false sinon 
 */
bool Ville::estAdjacent(Ville *ville){
    if (ville == nullptr){
        return false;
    }
    for (auto & villesAdjacente : villesAdjacentes){
        if (villesAdjacente == ville){
            return true;
        }
    }
    return false;
}

/**
 * @brief Méthode qui teste si une ville est adjacente à une autre.
 * @param nomVille Nom de la ville à tester
 * @return Booléen à true si la ville i est adjacente à la ville courante et false sinon
 */
bool Ville::estAdjacent(const string & nomVille){
    if (nomVille.empty()){
        return false;
    }
    for (auto & villesAdjacente : villesAdjacentes){
        if (villesAdjacente->getNomVille() == nomVille){
            return true;
        }
    }
    return false;
}

/**
 * @brief Méthode qui permet d'afficher les sommets adjacents au sommet courant en parcourant le vector villesAdjacentes
 */
void Ville::afficheAdjacent(){
    for (int i = 0; i < villesAdjacentes.size(); i++){
        cout << villesAdjacentes[i]->ville_ << endl;
    }
}

/**
 * @brief Accesseur qui permet de d'obtenir le vector contenant les pointeurs vers les villes adjacentes à la ville courante
 * @return Renvoie le vector de pointeurs vers les villes adjacentes 
 */
vector<Ville*> &Ville::getAdjacent(){
    return villesAdjacentes;
}

/**
 * @brief Mutateur qui permet d'ajouter une ville au vector de pointeurs vers Ville
 * @param v Adresse d'une Ville
 */
void Ville::ajoutVilleAdjacente(Ville* v){
    villesAdjacentes.push_back(v);
}