#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include "fonctionAnnexe.h"
#include "Joueur.h"

using namespace std;

bool ouvrirFichierMap(const string nomFichier, listeVoieFerre_t &listeVoieFerre, listeVille_t &listeVille){
    string ligne;
    ifstream fichier(nomFichier);

    if (fichier.is_open()){
        //LES DEUX GETLINE SONT POUR NE PAS RÉCUPÉRER LES DEUX PREMIÈRES VALEURS
        getline(fichier,ligne);
        while (getline(fichier,ligne)){
            string info;
            vector<string> colonne;
            stringstream ss(ligne); //on transforme chaque ligne du csv en flux pour pouvoir parser plus facilement
            while (getline(ss, info, ',')) {
                colonne.push_back(info);
            }
            //Gestion des villes
            //Vérification de la présence d'au moins 2 élements par colonnes
            if (colonne.size() >= 2){
                for (int i = 0; i < 2; i++){ //Les villes concernées sont les deux premiers éléments d'une ligne
                    if (find(listeVille.begin(),listeVille.end(),colonne[i]) == listeVille.end()){
                        listeVille.push_back(colonne[i]);
                    }
                }
                listeVoieFerre.push_back(colonne);
            }
            
        }
        return true;
    }
    else{
        cerr << "Erreur de chargement du fichier carte : " << nomFichier << endl;
        return false;
    }
}

void afficheVectVille(const listeVille_t v){
    for (int i = 0; i < v.size(); i++){
        cout << i << " " << v[i] << endl;
    }
}

Couleur_e getCouleur(const string &couleur) {
   if (couleur == "red") {
       return Couleur_e::Rouge;
   }

   if (couleur == "green") {
       return Couleur_e::Vert;
   }

   if (couleur == "blue") {
       return Couleur_e::Bleu;
   }

   if (couleur == "yellow") {
       return Couleur_e::Jaune;
   }

   if (couleur == "black") {
       return Couleur_e::Noir;
   }

   if (couleur == "white") {
       return Couleur_e::Blanc;
   }

   if (couleur == "orange") {
       return Couleur_e::Orange;
   }

   if (couleur == "locomotive") {
         return Couleur_e::Locomotive;
   }
   cerr << "Couleur non reconnue : " << couleur << endl;
   return Couleur_e::Inconnue;
}

void afficheVectVoieFerree(const listeVoieFerre_t v){
    for (int i = 0; i < v.size(); i++){
        cout << "[";
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

string applyPlayerColor(const string &text, Joueur* joueur) {
    switch (joueur->getCouleur()) {
        case Couleur_e::Rouge:
            return terminal::RED + text + terminal::RESET;
        case Couleur_e::Vert:
            return terminal::GREEN + text + terminal::RESET;
        case Couleur_e::Bleu:
            return terminal::BLUE + text + terminal::RESET;
        case Couleur_e::Jaune:
            return terminal::YELLOW + text + terminal::RESET;
        default:
            return text;
    }
}
