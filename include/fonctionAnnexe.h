#ifndef SMP_TP8_DAVID_RIANA_ANNEXE_H
#define SMP_TP8_DAVID_RIANA_ANNEXE_H

#include <iostream>
#include <vector>
#include "types.h"

using namespace std;

extern listeVille_t vectVille;
extern listeVoieFerre_t vectVoieFerree;

bool ouvrirFichierMap(const string nomFichier);
void afficheVectVille(vector<string> v);
void afficheVectVoieFerree(vector<string> v);
Couleur_e getCouleur(const string &couleur);


#endif