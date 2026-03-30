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

vector<VoieFerree> Plateau::getVoiesFerrees(const Ville & villeA, const Ville & villeB) const {
    vector<VoieFerree> trouvees;

    for (VoieFerree voie_ferree : voie_ferrees_) {
        if ((voie_ferree.getVille1()->getNomVille() == villeA.getNomVille() && voie_ferree.getVille2()->getNomVille() == villeB.getNomVille()) ||
            (voie_ferree.getVille1()->getNomVille() == villeB.getNomVille() && voie_ferree.getVille2()->getNomVille() == villeA.getNomVille())) {
            trouvees.push_back(voie_ferree);
        }
    }

    return trouvees;
}

/**
 * Affiche le plateau de jeu en affichant les villes et les voies ferrées dans le flux standard de sortie.
 * Un joueur (max 4) possède une couleur parmi : bleu, jaune, vert et rouge.
 * La sortie prend la forme de matrice d'adjacence où chaque case représente une ou plusieurs voies ferrées entre deux villes.
 * Lorsqu'un joueur possède une voie ferrée, le texte de cette voie prend la couleur du joueur.
 *
 * Avec les villes suivantes : Seattle, Calgary et Helena
 * et les voies ferrées suivantes :
 * Seattle-Calgary (bleu)  poid  : 2
 * Seattle-Calgary (rouge) poids : 4
 *
 * Seattle-Helena (rouge)  poids : 1
 * Seattle-Helena (vert)   poids : 2
 *
 * Calgary-Helena (vert)   poids : 3
 *
 * Voici un exemple de sortie possible :
 *
 * ----------=== Plateau de jeu ===----------
 *          Seattle    Calgary     Helena       (Ville A)
 *         ------------------------------------
 * Seattle | X         | 2 (bleu) | 1 (rouge) |
 * Calgary | 4 (rouge) | X        | 3 (vert)  |
 * Helena  | 2 (vert)  | X        | X         |
 *         ------------------------------------
 * (Ville B)
 */
void Plateau::affichePlateau() const {
    // TODO: Finir l'implémentation de la méthode affichePlateau
    std::ostringstream header_villeA;
    cout << "----------=== Plateau de jeu ===----------" << endl;

    cout << "         ";
    for (Ville ville : villes_) {
        header_villeA << setw(14) << left << ville.getNomVille() << " ";
    }
    cout << header_villeA.str() << endl;
    cout << "         ";
    cout << string(header_villeA.str().size(), '-') << endl;

    for (Ville villeB : villes_) {
        cout << villeB.getNomVille();

        for (Ville villeA : villes_) {
            if (villeA.getNomVille() == villeB.getNomVille()) {
                cout << " | X         ";
            } else {
                vector<VoieFerree> voies_ferrees = getVoiesFerrees(villeA, villeB);

                if (voies_ferrees.empty()) {
                    cout << " | X         ";
                } else {
                    stringstream ss;
                    for (VoieFerree voie_ferree : voies_ferrees) {
                        ss << voie_ferree.getPoids();
                        // << " (" << getCouleurString(voie_ferree.getCouleur()) << ") ";
                    }
                    cout << " | " << setw(11) << left << ss.str();
                }
            }
        }
        cout << endl;
    }
}