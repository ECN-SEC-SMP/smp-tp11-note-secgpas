#include "Jeu.h"
#include "Ville.h"
#include "config.h"

Jeu::Jeu(int nbJoueur) : p(MAP_FILE_PATH), tickets(Pioche_type_e::Ticket), train(Pioche_type_e::CarteW), nbTour(0) {
    for (int i = 0; i < nbJoueur; i++) {
        int couleur;
        cout << "Joueur " << (i+1) << ", quelle couleur ? (0=Rouge 1=Bleu 2=Vert 3=Jaune) : ";
        cin >> couleur;
        joueurs.push_back(Joueur(static_cast<Couleur_e>(couleur)));
    }
}

bool Jeu::estFinie() {
    for (int i = 0; i < (int)joueurs.size(); i++) {
        if (joueurs.at(i).getMainWagon() == 0 || joueurs.at(i).getNbTicketReussis() == 6) {
            cout << "Partie finie ! Gagnant : joueur " << (int)joueurs.at(i).getCouleur() << endl;
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
            for (int j = 0; j < (int)joueurs.size(); j++) {  
                cout << "  Joueur " << j
                     << " | Wagons : "           << joueurs.at(j).getMainWagon()
                     << " | Tickets reussis : "  << joueurs.at(j).getNbTicketReussis()
                     << endl;
            }

            int decision = -1;
            cout << "\nTour du Joueur : " << (int)joueurs.at(i).getCouleur() << endl;            cout << "0 : Piocher | 1 : Poser wagon | 2 : Passer son tour" << endl;
            cin >> decision;

            while (decision < 0 || decision > 2) {
                cout << "Choix invalide, réessaie : ";
                cin >> decision;
            }

            if (decision == 0) {
                joueurs.at(i).piocher(2, train);
                cout << "\n--- Plateau après pioche ---" << endl;
                p.affichePlateau();
            }
            else if (decision == 1) {
                int v1, v2;
                cout << "Ville départ : ";  cin >> v1;
                cout << "Ville arrivée : "; cin >> v2;
                joueurs.at(i).poserWagon((Ville)v1, (Ville)v2, joueurs.at(i).getCouleur(), p); 
                cout << "\n--- Plateau après pose de wagon ---" << endl;
                p.affichePlateau();
            }
            else {
                joueurs.at(i).defausser(tickets);
                cout << "\n--- Plateau après défausse ---" << endl;
                p.affichePlateau();
            }

            if (estFinie()) return;
        }
    }
}

void Jeu::afficherEtat() const {
    cout << "\n===== TOUR " << nbTour << " =====" << endl;
    for (int i = 0; i < (int)joueurs.size(); i++) {
        cout << "  Joueur " << i
             << " | Wagons : "          << joueurs.at(i).getMainWagon()
             << " | Tickets reussis : " << joueurs.at(i).getNbTicketReussis()
             << endl;
    }
}