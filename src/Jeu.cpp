#include "Jeu.hpp"
Jeu::Jeu(int nbJoueur) : nbTour(0) {   // initialiser nbTour proprement
    for (int i = 0; i < nbJoueur; i++) {  // i=0, pas i=1
        int couleur;
        cout << "Joueur " << (i+1) << ", quelle couleur ? (0=Rouge 1=Bleu 2=Vert 3=Jaune) : ";
        cin >> couleur;
        joueurs.push_back(Joueur(couleur));  // Joueur par valeur, pas new
    }
    p       = Plateau();
    tickets = Pioche();
    train   = Pioche();
}

bool Jeu::estFinie() {
    for (int i = 0; i < (int)joueurs.size(); i++) {
        if (joueurs.at(i).mainWagon == 0 || joueurs.at(i).nbTicketReussis == 6) {
            cout << "Partie finie ! Gagnant : joueur " << joueurs.at(i).couleur << endl;
            return true;
        }
    }
    return false;
}

void Jeu::partie() {
    while (!estFinie()) {
        nbTour++;
        for (int i = 0; i < (int)joueurs.size(); i++) {

            cout << "\n===== TOUR " << nbTour << " =====" << endl;
            for (int i = 0; i < (int)joueurs.size(); i++) {
                cout << "  Joueur " << i << " | Wagons : "          << joueurs.at(i).mainWagon << " | Tickets reussis : " << joueurs.at(i).nbTicketReussis << endl;
            }

            int decision = -1;
            cout << "\nTour du Joueur : " << joueurs.at(i).couleur << endl;
            cout << "0 : Piocher | 1 : Poser wagon | 2 : Passer son tour" << endl;
            cin >> decision;

            while (decision < 0 || decision > 2) {
                cout << "Choix invalide, réessaie : ";
                cin >> decision;
            }

            if (decision == 0) {
                joueurs.at(i).piocher(2, train);         // . car Joueur (valeur)
            }
            else if (decision == 1) {                    // else if, pas if séparé
                int v1, v2;
                cout << "Ville départ : ";  cin >> v1;
                cout << "Ville arrivée : "; cin >> v2;
                joueurs.at(i).poserWagon((Ville_e)v1, (Ville_e)v2, joueurs.at(i).couleur);
            }
            else {                                       // decision == 2 seulement
                joueurs.at(i).passerTour();
            }

            if (estFinie()) return;   // sortir immédiatement si fin en cours de tour
        }
    }
}

void Jeu::afficherEtat() const {
    cout << "\n===== TOUR " << nbTour << " =====" << endl;
    for (int i = 0; i < (int)joueurs.size(); i++) {
        cout << "  Joueur " << i
             << " | Wagons : "          << joueurs.at(i).mainWagon
             << " | Tickets reussis : " << joueurs.at(i).nbTicketReussis
             << endl;
    }
}