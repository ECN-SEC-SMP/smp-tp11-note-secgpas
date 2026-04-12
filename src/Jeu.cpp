#include "Jeu.h"
#include "Ville.h"
#include "config.h"
#include <limits>

Jeu::Jeu(int nbJoueur) : p(MAP_FILE_PATH), tickets(Pioche_type_e::Ticket), train(Pioche_type_e::CarteW), nbTour(0) {

    const vector<Couleur_e> available = {Couleur_e::Rouge, Couleur_e::Bleu, Couleur_e::Vert, Couleur_e::Jaune};
    auto colorName = [](Couleur_e c) -> string {
        switch (c) {
            case Couleur_e::Rouge: return "Rouge";
            case Couleur_e::Bleu:  return "Bleu";
            case Couleur_e::Vert:  return "Vert";
            case Couleur_e::Jaune: return "Jaune";
            default:               return "Inconnue";
        }
    };

    // Correction : taken n'est plus static, il vit le temps du constructeur
    vector<bool> taken(available.size(), false);

    for (int i = 0; i < nbJoueur; i++) {
        int choix = -1;
        while (true) {
            cout << "Joueur " << (i + 1) << ", quelle couleur ?" << endl;
            for (size_t idx = 0; idx < available.size(); ++idx) {
                cout << "  " << idx << " = " << colorName(available[idx]);
                if (taken[idx]) cout << " (pris)";
                cout << endl;
            }
            cout << "Choisissez un indice de couleur : ";
            if (!(cin >> choix)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrée invalide, veuillez saisir un entier." << endl;
                continue;
            }
            if (choix < 0 || static_cast<size_t>(choix) >= available.size()) {
                cout << "Indice hors plage, réessayez." << endl;
                continue;
            }
            if (taken[choix]) {
                cout << "Couleur déjà prise, choisissez-en une autre." << endl;
                continue;
            }
            taken[choix] = true;
            joueurs.push_back(Joueur(available[choix]));
            break;
        }
    }

    // Correction : distribution initiale APRÈS que tous les joueurs sont créés
    for (size_t i = 0; i < joueurs.size(); ++i) {
        joueurs.at(i).piocher(4, train);
    }

    // Pioche de tickets : reconstruire le deck avec le plateau `p` pour
    // éviter que des Ticket* ne pointent vers un Plateau temporaire créé
    // à l'intérieur de Pioche (qui provoquerait des pointeurs pendants).
    // 1) Supprimer tout ce qui est actuellement dans tickets.getDeck()
    for (auto c : tickets.getDeck()) {
        delete c;
    }
    tickets.getDeck().clear();

    // 2) Charger depuis le CSV en utilisant `p` et remplir la pioche
    vector<Ticket> fileTickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);
    for (size_t k = 0; k < fileTickets.size(); ++k) {
        tickets.getDeck().push_back(new Ticket(fileTickets[k]));
    }
    tickets.melanger();

    // 3) Distribuer 2 tickets par joueur
    for (size_t i = 0; i < joueurs.size(); ++i) {
        joueurs.at(i).piocher(2, tickets);
    }
}

bool Jeu::estFinie() {
    for (int i = 0; i < (int)joueurs.size(); i++) {
        if (joueurs.at(i).getMainWagon() == 0) {
            cout << "Partie finie ! Joueur " << i << " n'a plus de wagons !" << endl;
            return true;
        }
        if (joueurs.at(i).getNbTicketReussis() >= 6) {
            cout << "Partie finie ! Joueur " << i << " a réussi 6 tickets !" << endl;
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
                     << " | Wagons : "            << joueurs.at(j).getMainWagon()
                     << " | Tickets en main : "   << joueurs.at(j).getMainTicket().size()
                     << " | Tickets réussis : "   << joueurs.at(j).getNbTicketReussis()
                     << endl;
            }

            int decision = -1;
            cout << "\nTour du Joueur " << i << endl;
            cout << "0 : Piocher 2 cartes train" << endl;
            cout << "1 : Poser wagons sur une voie" << endl;
            cout << "2 : Passer son tour (défausser 2 tickets et en reprendre 2)" << endl;
            cout << "3 : Afficher le plateau" << endl;
            cout << "4 : Afficher ma main" << endl;
            cout << "Votre choix : ";
            cin >> decision;

            while (decision < 0 || decision > 4) {
                cout << "Choix invalide, réessaie : ";
                cin >> decision;
            }

            // Option afficher plateau / afficher main : on redemande l'action ensuite
            while (decision == 3 || decision == 4) {
                if (decision == 3) {
                    p.affichePlateau();
                } else {
                    joueurs.at(i).afficherMain();
                }
                cout << "\nChoisissez une action : 0:Piocher | 1:Poser wagon | 2:Passer | 3:Plateau | 4:Main" << endl;
                cin >> decision;
                while (decision < 0 || decision > 4) {
                    cout << "Choix invalide, réessaie : ";
                    cin >> decision;
                }
            }

            if (decision == 0) {
                // Piocher 2 cartes train
                joueurs.at(i).piocher(2, train);
                cout << "Vous avez pioché 2 cartes train." << endl;
            }
            else if (decision == 1) {
                // Poser wagons : choisir villes et couleur de voie
                auto& villes = p.getVilles();
                cout << "Villes disponibles :" << endl;
                for (size_t idx = 0; idx < villes.size(); ++idx) {
                    cout << "  " << idx << " : " << villes[idx].getNomVille() << endl;
                }

                int v1 = -1, v2 = -1;
                while (true) {
                    cout << "Ville départ (index) : ";
                    if (!(cin >> v1)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Entrée invalide." << endl; continue;
                    }
                    if (v1 < 0 || static_cast<size_t>(v1) >= villes.size()) {
                        cout << "Indice hors plage." << endl; continue;
                    }
                    break;
                }
                while (true) {
                    cout << "Ville arrivée (index) : ";
                    if (!(cin >> v2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Entrée invalide." << endl; continue;
                    }
                    if (v2 < 0 || static_cast<size_t>(v2) >= villes.size()) {
                        cout << "Indice hors plage." << endl; continue;
                    }
                    break;
                }

                // Afficher les voies disponibles entre ces deux villes
                Ville& va = p.getVille(v1);
                Ville& vb = p.getVille(v2);
                vector<VoieFerree> voiesDispo = p.getVoieFerrees(va, vb);

                if (voiesDispo.empty()) {
                    cout << "Aucune voie ferrée entre ces deux villes." << endl;
                }
                else {
                    cout << "Voies disponibles :" << endl;
                    for (size_t k = 0; k < voiesDispo.size(); ++k) {
                        cout << "  " << k << " : couleur=" << static_cast<int>(voiesDispo[k].getCouleur())
                             << " poids=" << voiesDispo[k].getPoids()
                             << (voiesDispo[k].estDispo() ? "" : " [PRISE]") << endl;
                    }

                    // Demander la couleur de la voie à prendre
                    cout << "Entrez la couleur de la voie (0=Loco,1=Jaune,2=Bleu,3=Rouge,4=Vert,5=Noir,6=Blanc,7=Orange) : ";
                    int couleurInt = -1;
                    cin >> couleurInt;
                    if (couleurInt < 0 || couleurInt > 7) {
                        cout << "Couleur invalide." << endl;
                    } else {
                        Couleur_e couleurVoie = static_cast<Couleur_e>(couleurInt);
                        joueurs.at(i).poserWagon(va, vb, couleurVoie, p);
                    }
                }
            }
            else if (decision == 2) {
                // Passer son tour : défausser 2 tickets et en reprendre 2
                joueurs.at(i).defausser(tickets);
                cout << "Vous avez défaussé vos tickets et pioché de nouveaux." << endl;
            }

            if (estFinie()) return;
        }
    }
}

void Jeu::afficherEtat() const {
    cout << "\n===== ÉTAT FINAL - TOUR " << nbTour << " =====" << endl;
    for (int i = 0; i < (int)joueurs.size(); i++) {
        cout << "  Joueur " << i
             << " | Wagons restants : "   << joueurs.at(i).getMainWagon()
             << " | Tickets réussis : "   << joueurs.at(i).getNbTicketReussis()
             << " | Tickets en main : "   << joueurs.at(i).getMainTicket().size()
             << endl;
    }
}