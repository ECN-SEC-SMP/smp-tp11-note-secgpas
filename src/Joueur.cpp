#include <iostream>
#include "Joueur.h"
#include "Plateau.h"
#include "VoieFerree.h"

using namespace std;

Joueur::Joueur(Couleur_e c) {
    couleur = c;
    for (int i = 0; i < 8; i++) {
        mainCarte.emplace(static_cast<Couleur_e>(i), 0);
    }
    mainWagon = 20;
}

int Joueur::getMainWagon() const {
    return mainWagon;
}

map<Couleur_e, int> Joueur::getMainCarte() const {
    return mainCarte;
}

vector<Ticket*> Joueur::getMainTicket() const {
    return mainTicket;
}

/**
 * @brief Compte les tickets effectivement réussis pour ce joueur.
 * Parcourt tous les tickets en main et appelle estRealise() sur chacun.
 * @return Le nombre de tickets réussis.
 */
int Joueur::getNbTicketReussis() const {
    int count = 0;
    for (Ticket* t : mainTicket) {
        if (t != nullptr && t->estRealise(const_cast<Joueur*>(this))) {
            count++;
        }
    }
    return count;
}

/**
 * @brief Pioche nbAPiocher cartes depuis la pioche donnée.
 * Si la pioche se vide en cours de route, on s'arrête sans crash.
 */
void Joueur::piocher(int nbAPiocher, Pioche& type) {
    for (int i = 0; i < nbAPiocher; i++) {
        if (type.estPiocheVide()) {
            // Recycler la défausse si possible
            if (!type.getDefausse().empty()) {
                for (Carte* c : type.getDefausse()) {
                    type.getDeck().push_back(c);
                }
                type.getDefausse().clear();
                type.melanger();
            } else {
                cout << "La pioche est vide, impossible de piocher davantage." << endl;
                break;
            }
        }

        switch (type.getPiocheType()) {
            case Pioche_type_e::CarteW: {
                CTrain* carte = dynamic_cast<CTrain*>(type.getDeck().back());
                type.getDeck().pop_back();
                if (carte != nullptr) {
                    mainCarte[carte->getCouleur()]++;
                }
                break;
            }
            case Pioche_type_e::Ticket: {
                Ticket* carte1 = dynamic_cast<Ticket*>(type.getDeck().back());
                type.getDeck().pop_back();
                if (carte1 != nullptr) {
                    mainTicket.push_back(carte1);
                }
                break;
            }
            default:
                break;
        }
    }
}

/**
 * @brief Tente de poser des wagons sur la voie entre a et b.
 * Vérifie que le joueur possède assez de cartes (couleur + locomotives comme jokers),
 * défausse les cartes utilisées, pose les wagons et vérifie les tickets.
 */
void Joueur::poserWagon(Ville a, Ville b, Couleur_e couleurVoie, Plateau& plateau) {
    vector<VoieFerree>& voies = plateau.getVoieFerrees();

    for (int i = 0; i < (int)voies.size(); i++) {
        VoieFerree& voie = voies[i];

        bool bonneVille = (voie.getVille1()->getNomVille() == a.getNomVille() &&
                           voie.getVille2()->getNomVille() == b.getNomVille()) ||
                          (voie.getVille1()->getNomVille() == b.getNomVille() &&
                           voie.getVille2()->getNomVille() == a.getNomVille());

        bool bonneCouleur = (voie.getCouleur() == couleurVoie);

        if (!bonneVille || !bonneCouleur) continue;
        if (!voie.estDispo()) {
            cout << "Cette voie est déjà prise !" << endl;
            continue;
        }

        int poids = voie.getPoids();

        // Vérifier wagons disponibles
        if (mainWagon < poids) {
            cout << "Pas assez de wagons (il en faut " << poids << ", vous en avez " << mainWagon << ")." << endl;
            return;
        }

        // Calculer cartes disponibles : cartes de la couleur + locomotives (jokers)
        int cartesColor = mainCarte.count(couleurVoie) ? mainCarte[couleurVoie] : 0;
        int locos       = mainCarte.count(Couleur_e::Locomotive) ? mainCarte[Couleur_e::Locomotive] : 0;

        if (cartesColor + locos < poids) {
            cout << "Pas assez de cartes (couleur=" << cartesColor
                 << " + locos=" << locos << " < " << poids << " nécessaires)." << endl;
            return;
        }

        // Utiliser d'abord les cartes de la couleur, compléter avec des locomotives
        int aUtiliserColor = min(cartesColor, poids);
        int aUtiliserLoco  = poids - aUtiliserColor;

        mainCarte[couleurVoie]          -= aUtiliserColor;
        mainCarte[Couleur_e::Locomotive] -= aUtiliserLoco;

        // Poser les wagons
        mainWagon -= poids;
        voie.setProprio(this);

        cout << "Wagons posés entre " << a.getNomVille()
             << " et " << b.getNomVille()
             << " (couleur voie=" << static_cast<int>(couleurVoie)
             << ", poids=" << poids << ")." << endl;

        // Vérifier si un ticket est réussi après la pose
        verifierTickets();
        return;
    }

    cout << "Aucune voie disponible trouvée entre " << a.getNomVille()
         << " et " << b.getNomVille()
         << " avec la couleur demandée." << endl;
}

/**
 * @brief Vérifie tous les tickets en main et annonce ceux qui sont réussis.
 */
void Joueur::verifierTickets() {
    for (Ticket* t : mainTicket) {
        if (t != nullptr && t->estRealise(this)) {
            cout << "TICKET ! Chemin réussi entre "
                 << t->getVilleA()->getNomVille()
                 << " et " << t->getVilleB()->getNomVille() << " !" << endl;
        }
    }
}

/**
 * @brief Défausse jusqu'à 2 tickets et en pioche de nouveaux.
 */
void Joueur::defausser(Pioche& piocheTicket) {
    int nbDefausse = min((int)mainTicket.size(), 2);
    for (int i = 0; i < nbDefausse; i++) {
        // Remettre dans la défausse de la pioche
        piocheTicket.pushDefausse(mainTicket.back());
        mainTicket.pop_back();
    }
    piocher(2, piocheTicket);
}

Couleur_e Joueur::getCouleur() const {
    return couleur;
}

/**
 * @brief Affiche la main du joueur (cartes train + tickets).
 */
void Joueur::afficherMain() const {
    cout << "--- Cartes Train ---" << endl;
    for (auto it = mainCarte.begin(); it != mainCarte.end(); ++it) {
        if (it->second == 0) continue;
        switch (it->first) {
            case Couleur_e::Jaune:      cout << "Jaune : "      << it->second << endl; break;
            case Couleur_e::Bleu:       cout << "Bleu : "       << it->second << endl; break;
            case Couleur_e::Rouge:      cout << "Rouge : "      << it->second << endl; break;
            case Couleur_e::Vert:       cout << "Vert : "       << it->second << endl; break;
            case Couleur_e::Noir:       cout << "Noir : "       << it->second << endl; break;
            case Couleur_e::Blanc:      cout << "Blanc : "      << it->second << endl; break;
            case Couleur_e::Locomotive: cout << "Locomotive : " << it->second << endl; break;
            default:                    break;
        }
    }
    cout << "--- Tickets ---" << endl;
    for (Ticket* t : mainTicket) {
        if (t == nullptr) continue;
        auto a = t->getVilleA();
        auto b = t->getVilleB();
        if (a == nullptr || b == nullptr) continue; 
        cout << "  " << a->getNomVille()
             << " -> " << b->getNomVille(); 
        if (t->estRealise(const_cast<Joueur*>(this))) {
            cout << " [RÉUSSI]";
        }
        cout << endl;
    }
}