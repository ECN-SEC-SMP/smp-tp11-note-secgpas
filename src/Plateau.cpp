//
// Created by David PROSPÉRIN on 25/03/2026.
//

#include "Plateau.h"
#include "VoieFerree.h"
#include "fonctionAnnexe.h"

Plateau::Plateau(const string & nomFichierMap) {
    graphe_ville_ = nullptr;

    if (!ouvrirFichierMap(nomFichierMap))
        cerr << "Plateau non chargé" << endl;

    // 1. Créer toutes les villes
    for (string nomVille : vectVille) {
        villes_.push_back(Ville(nomVille));
    }
    // 2. Créer toutes les voies ferrées
    // TODO : Ne pas ajouter les doublons
    for (vector<string> voieFerre : vectVoieFerree) {
        Ville* villeA = getVille(voieFerre[0]);
        Ville* villeB = getVille(voieFerre[1]);

        if (villeA != nullptr && villeB != nullptr) {
            voie_ferrees_.push_back(VoieFerree(villeA, villeB, stoi(voieFerre[3]), getCouleur(voieFerre[2])));
        } else {
            cerr << "Erreur lors de la création de la voie ferrée entre ";

            if (villeA != nullptr) {
                cerr << voieFerre[0];
            } else {
                cerr << "<Pas de VilleA>";
            }

            cerr << " et ";

            if (villeB != nullptr) {
                cerr << voieFerre[1];
            } else {
                cerr << "<Pas de VilleB>";
            }

            cerr << endl;
        }
    }
}

Ville* Plateau::getVille(const string &nomVille) {
    // TODO: on peut faire mieux que O(n) en utilisant une map ou un unordered_map pour stocker les villes
    // NOTE: la variable locale ville est une référence & sinon le pointeur retourné
    // pointerait sur une variable locale qui serait détruite à la fin de la fonction
    for (Ville& ville : villes_) {
        if (ville.getNomVille() == nomVille) {
            return &ville;
        }
    }
    return nullptr;
}
