#include "Carte.h"
#include "Plateau.h"

Ticket::Ticket(Plateau *plateau, const string & nomVilleA, const string & nomVilleB, const int id) {
    Ville* villeA = nullptr;
    Ville* villeB = nullptr;

    if (plateau == nullptr) {
        cerr << "Erreur : le plateau ne peut pas être nul." << endl;
        exit(EXIT_FAILURE);
    }

    id_      = id;
    plateau_ = plateau;

    villeA = plateau_->getVille(nomVilleA);
    villeB = plateau_->getVille(nomVilleB);

    if (villeA != nullptr) {
        villeA_ = villeA;
    } else {
        cerr << "Erreur : la ville " << nomVilleA << " n'existe pas sur le plateau." << endl;
        exit(EXIT_FAILURE);
    }

    if (villeB != nullptr) {
        villeB_ = villeB;
    } else {
        cerr << "Erreur : la ville " << nomVilleB << " n'existe pas sur le plateau." << endl;
        exit(EXIT_FAILURE);
    }
}