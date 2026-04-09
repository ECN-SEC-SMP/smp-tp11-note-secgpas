#include <iostream>
#include "Jeu.h"

using namespace std;

int main() {
    int nbJoueurs;
    cout << "Bienvenue dans les Aventuriers du Rail !" << endl;
    cout << "Combien de joueurs ? (2-4) : ";
    cin >> nbJoueurs;

    while (nbJoueurs < 2 || nbJoueurs > 4) {
        cout << "Nombre de joueurs invalide, réessaie (2-4) : ";
        cin >> nbJoueurs;
    }

    Jeu jeu(nbJoueurs);
    jeu.partie();
    jeu.afficherEtat();

    return 0;
}