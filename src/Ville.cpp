#include <iostream>
#include "Ville.h"
#include "fonctionAnnexe.h"


using namespace std;

/**
 * @brief constructeur de la classe Ville, on paramètre l'attribut nom de la ville.
 * @param i correspond à l'indice de la ville dans vectVille (vector généré lors de l'ouverture du fichier)
*/
Ville::Ville(int i){
    ville_ = vectVille[i]; 
}

/**
 * @brief accesseur qui renvoie le nom de la ville sur laquelle est appliquée la méthode.
 * @return renvoie le nom de la ville sous forme de string
 */
string Ville::getNomVille(){
    return ville_;
}

/**
 * @brief méthode qui teste si une ville est adjacente à une autre.
 * @param i indice du sommet avec tester le sommet courant dans le vector généré à l'ouverture du fichier
 * @return booléen à true si la ville i est adjacente à la ville courante et false sinon 
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
 * @brief méthode qui permet d'afficher les sommets adjacents au sommet courant en parcourant le vector villesAdjacentes
 */
void Ville::afficheAdjacent(){
    for (int i = 0; i < villesAdjacentes.size(); i++){
        cout << villesAdjacentes[i]->ville_ << endl;
    }
}

/**
 * @brief accesseur qui permet de d'obtenir le vector contenant les pointeurs vers les villes adjacentes à la ville courante
 * @return renvoie le vector de pointeurs vers les villes adjacentes 
 */
vector<Ville*> Ville::getAdjacent(){
    return villesAdjacentes;
}

/**
 * @brief mutateur qui permet d'ajouter une ville au vector de pointeurs vers Ville
 * @param v adresse d'une Ville
 */
void Ville::ajoutVilleAdjacente(Ville* v){
    villesAdjacentes.push_back(v);
}