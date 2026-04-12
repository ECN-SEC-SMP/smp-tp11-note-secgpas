#include <iostream>
#include <limits>
#include "Jeu.h"

using namespace std;

int main() {
    int nbJoueurs = 0;
    cout << "Bienvenue dans les Aventuriers du Rail !" << endl;
    cout << "\n--- Règles rapides (récapitulatif) ---" << endl;
    cout << "- Chaque joueur commence avec 20 wagons." << endl;
    cout << "- Mélanger les cartes Train et distribuer 4 cartes à chaque joueur (main cachée)." << endl;
    cout << "- Former la pioche face cachée avec les cartes restantes." << endl;
    cout << "- Mélanger les Tickets et distribuer 2 tickets à chaque joueur (tickets cachés)." << endl;
    cout << "- Les cartes et tickets des joueurs restent secrets." << endl;
    cout << "- Au tour d'un joueur, choisir : 0 Piocher | 1 Poser wagon | 2 Passer (défausse tickets)" << endl;
    cout << "- Vous pouvez afficher le plateau ou votre main via les options prévues." << endl;
    cout << "--------------------------------------\n" << endl;

    // Demande et validation robuste du nombre de joueurs (entier entre 2 et 4)
    while (true) {
        cout << "Combien de joueurs ? (2-4) : ";
        if (!(cin >> nbJoueurs)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Entrée invalide, veuillez saisir un entier." << endl;
            continue;
        }
        if (nbJoueurs < 2 || nbJoueurs > 4) {
            cout << "Nombre de joueurs invalide, réessaie (2-4)." << endl;
            continue;
        }
        break;
    }

    Jeu jeu(nbJoueurs);
    jeu.partie();
    jeu.afficherEtat();

    return 0;
}