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

    // 3. Création du graphe
    for (VoieFerree voie_ferree : voie_ferrees_) {
        auto ville1 = voie_ferree.getVille1();
        auto ville2 = voie_ferree.getVille2();

        if (ville1 != nullptr && ville2 != nullptr) {
            if (std::count(ville1->getAdjacent().begin(), ville1->getAdjacent().end(), ville2) == 0) {
                ville1->ajoutVilleAdjacente(ville2);
            }

            if (std::count(ville2->getAdjacent().begin(), ville2->getAdjacent().end(), ville1) == 0) {
                ville2->ajoutVilleAdjacente(ville1);
            }
        }
    }

    if (!villes_.empty()) {
        graphe_ville_ = &villes_[0];
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

void Plateau::affichePlateau() const {
    cout << "=== Plateau de jeu ===" << endl;

}
