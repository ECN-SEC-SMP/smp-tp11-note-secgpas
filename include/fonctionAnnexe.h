#ifndef SMP_TP8_DAVID_RIANA_ANNEXE_H
#define SMP_TP8_DAVID_RIANA_ANNEXE_H

#include <iostream>
#include <vector>

using namespace std; 
using listeVille_t     = vector<string>;
using listeVoieFerre_t = vector<vector<string>>;

extern listeVille_t vectVille;
extern listeVoieFerre_t vectVoieFerree; 

void ouvrirFichierMap(const string nomFichier);
void afficheVectVille(vector<string> v);
void afficheVectVoieFerree(vector<string> v);


#endif