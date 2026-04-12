#include <iostream>
#include <limits>
#include "Jeu.h"

using namespace std;

int main() {
    int nbJoueurs = 0;
    cout << "Bienvenue dans les Aventuriers du Rail !" << endl;

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