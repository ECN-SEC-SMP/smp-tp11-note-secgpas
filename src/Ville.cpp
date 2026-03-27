#include <iostream>
#include "Ville.h"
#include "fonctionAnnexe.h"


using namespace std;

/**
 * @brief Constructeur de la classe Ville, on paramètre l'attribut nom de la ville.
 * @param i Correspond à l'indice de la ville dans vectVille (vector généré lors de l'ouverture du fichier)
*/
Ville::Ville(int i){
    ville_ = vectVille[i]; 
}

/**
 * @brief Accesseur qui renvoie le nom de la ville sur laquelle est appliquée la méthode.
 * @return Renvoie le nom de la ville sous forme de string
 */
string Ville::getNomVille(){
    return ville_;
}

/**
 * @brief Méthode qui teste si une ville est adjacente à une autre.
 * @param i Indice du sommet avec tester le sommet courant dans le vector généré à l'ouverture du fichier
 * @return Booléen à true si la ville i est adjacente à la ville courante et false sinon 
 */
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
vector<Ville*> Ville::getAdjacent(){
    return villesAdjacentes;
}

/**
 * @brief Mutateur qui permet d'ajouter une ville au vector de pointeurs vers Ville
 * @param v Adresse d'une Ville
 */
void Ville::ajoutVilleAdjacente(Ville* v){
    villesAdjacentes.push_back(v);
}