#include "Carte.h"
#include "Plateau.h"
#include <fstream>
#include <sstream>

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

vector<Ticket> Ticket::loadFromCSVFile(Plateau *plateau, const string &nomFichierCSVTicket) {
    vector<Ticket> tickets;
    string ligne;
    ifstream fichier(nomFichierCSVTicket);

    if (fichier.is_open()){
        getline(fichier,ligne);
        while (getline(fichier,ligne)){
            string info;
            vector<string> colonne;
            stringstream ss(ligne);
            while (getline(ss, info, ',')) {
                colonne.push_back(info);
            }
            if (colonne.size() == 3){
                tickets.emplace_back(plateau, colonne[1], colonne[2],  stoi(colonne[0]));
            }

        }
        return tickets;
    }
    else{
        cerr << "fichier contenant les tickets non ouvert" << endl;
        cerr << "Nom du fichier : " << nomFichierCSVTicket << endl;
        exit(EXIT_FAILURE);
    }
}

bool Ticket::estRealise(Joueur *joueur) const {
    // TODO: Prise en charge des chemins plus longs que 1 voie ferrée
    if (joueur == nullptr) {
        cerr << "Erreur : le joueur ne peut pas être nul." << endl;
        exit(EXIT_FAILURE);
    }

    for (VoieFerree voie_ferree : plateau_->getVoieFerrees(*villeA_, *villeB_)) {
        if (voie_ferree.getProprio() == joueur) {
            return true;
        }
    }
    return false;
}
