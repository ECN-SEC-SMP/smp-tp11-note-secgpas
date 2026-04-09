//
// Created by David PROSPÉRIN on 25/03/2026.
//

#include "Plateau.h"
#include "VoieFerree.h"
#include "fonctionAnnexe.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

Plateau::Plateau(const string & nomFichierMap) {
    graphe_ville_ = nullptr;
    listeVille_t vectVille;
    listeVoieFerre_t vectVoieFerrees;

    if (!ouvrirFichierMap(nomFichierMap,vectVoieFerrees, vectVille))
        cerr << "Plateau non chargé" << endl;

    // 1. Créer toutes les villes
    for (string nomVille : vectVille) {
        villes_.push_back(Ville(nomVille));
    }
    // 2. Créer toutes les voies ferrées
    // TODO : Ne pas ajouter les doublons
    for (vector<string> voieFerre : vectVoieFerrees) {
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

vector<VoieFerree> Plateau::getVoieFerrees(const Ville & villeA, const Ville & villeB) const {
    vector<VoieFerree> trouvees;

    for (VoieFerree voie_ferree : voie_ferrees_) {
        if ((voie_ferree.getVille1()->getNomVille() == villeA.getNomVille() && voie_ferree.getVille2()->getNomVille() == villeB.getNomVille()) ||
            (voie_ferree.getVille1()->getNomVille() == villeB.getNomVille() && voie_ferree.getVille2()->getNomVille() == villeA.getNomVille())) {
            trouvees.push_back(voie_ferree);
        }
    }

    return trouvees;
}

void Plateau::affichePlateau() const {
    // TODO: Largeur de colonne dynamique en fonction du nom de la ville et du poids des voies ferrées
    std::ostringstream header_villeA;
    cout << "----------=== Plateau de jeu ===----------" << endl;

    cout << string(15, ' ');
    for (Ville ville : villes_) {
        header_villeA << setw(14) << left << ville.getNomVille();
    }
    cout << header_villeA.str() << endl;
    cout << string(14, ' ') << string(header_villeA.str().size(), '-') << endl;

    for (Ville villeB : villes_) {
        cout << setw(14) << left << villeB.getNomVille();

        for (Ville villeA : villes_) {
            if (villeA.getNomVille() == villeB.getNomVille()) {
                cout << setw(14) << " | X";
            } else {
                vector<VoieFerree> voies_ferrees = getVoieFerrees(villeA, villeB);

                if (voies_ferrees.empty()) {
                    cout << setw(14) << left << " | X";
                } else {
                    stringstream ss;

                    bool color_applied = false;

                    for (size_t i = 0; i < voies_ferrees.size(); i++) {
                        color_applied = false;
                        if (voies_ferrees[i].getProprio() == nullptr) {
                            ss << voies_ferrees[i].getPoids();
                        } else {
                            ss << applyPlayerColor(to_string(voies_ferrees[i].getPoids()), voies_ferrees[i].getProprio());
                            color_applied = true;
                        }

                        if (i < voies_ferrees.size() - 1) {
                            ss << ", ";
                        }
                    }
                    cout << " | ";

                    if (color_applied) {
                        cout << setw(33);
                    } else {
                        cout << setw(11);
                    }
                    cout << left << ss.str();
                }
            }
        }
        cout << endl;
    }
}