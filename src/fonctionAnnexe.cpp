#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include "fonctionAnnexe.h"

using namespace std;

listeVille_t vectVille;
listeVoieFerre_t vectVoieFerree;

void ouvrirFichierMap(const string nomFichier){  
    string ligne;
    ifstream fichier(nomFichier);

    if (fichier.is_open()){
        //LES DEUX GETLINE SONT POUR NE PAS RÉCUPÉRER LES DEUX PREMIÈRES VALEURS
        getline(fichier,ligne);
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
                    if (find(vectVille.begin(),vectVille.end(),colonne[i]) == vectVille.end()){
                        vectVille.push_back(colonne[i]);
                    }
                }
                vectVoieFerree.push_back(colonne);
            }
            
        }
    }
    else{
        cout << "fichier non ouvert" << endl; 
    }
}

void afficheVectVille(vector<string> v){
    for (int i = 0; i < v.size(); i++){
        cout << i << " " << v[i] << endl;
    }
}

void afficheVectVoieFerree(vector<vector<string>> v){
    for (int i = 0; i < v.size(); i++){
        cout << "[";
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

// int main(){
//     cout << "hello" << endl;
//     ouvrirFichierMap("/home/riana/Documents/smp-tp11-note-secgpas/map.csv");
//     afficheVectVille(vectVille);
//     afficheVectVoieFerree(vectVoieFerree);
//     return 0;
// }