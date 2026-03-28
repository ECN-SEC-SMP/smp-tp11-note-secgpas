#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(Couleur_e c){
    couleur = c;
    for (int i = 0; i < 7; i++){
        mainCarte.emplace(static_cast<Couleur_e>(i), 0);
    }
    mainWagon = 20;
}

int Joueur::getMainWagon(){
    return mainWagon;
}

map<Couleur_e,int> Joueur::getMainCarte(){
    return mainCarte;
}

void Joueur::piocher(Pioche& type){
    if (! type.estPiocheVide()){
        switch (type.getPiocheType())
    {
    case Pioche_type_e::CarteW :
        for (int i = 0; i < 2; i++){
            CTrain* carte = dynamic_cast<CTrain*>(type.getDeck().back()); //polymorphisme sur Carte et CTrain
            type.getDeck().pop_back(); //retire la carte de la pioche
            mainCarte[carte->getCouleur()] ++ ; //ajoute 1 au nombre de carte possédées par le joueur
        }
        break;

    case Pioche_type_e::Ticket :
        for (int i = 0; i < 2; i++){
            Ticket* carte1 = dynamic_cast<Ticket*>(type.getDeck().back()); //polymorphisme sur Carte et Ticket
            type.getDeck().pop_back(); //retire la carte de la pioche
            mainTicket.push_back(carte1);
        }
    default:
        break;
    }
    }
    
}

// void Joueur::poserWagon(Ville* a, Ville* b, Couleur_e c){

// }

void Joueur::defausser(){
    mainTicket.pop_back();
    mainTicket.pop_back();
    piocher(/*pioche qui stocke le deck ticket*/ );
}

void Joueur::afficherMain(){
    for(map<Couleur_e, int>::iterator it = mainCarte.begin(); it != mainCarte.end(); ++it){
        switch(it->first) {
            case Couleur_e::Jaune: 
                cout << "Jaune : " << it->second << endl;
                break;
            case Couleur_e::Bleu: 
                cout << "Bleu : " << it->second << endl;
                break;
            case Couleur_e::Rouge: 
                cout << "Rouge : " << it->second << endl;
                break;
            case Couleur_e::Vert: 
                cout << "Vert : " << it->second << endl;
                break;
            case Couleur_e::Noir: 
                cout << "Noir : " << it->second << endl;
                break;
            case Couleur_e::Blanc: 
                cout << "Blanc : " << it->second << endl;
                break;
            case Couleur_e::Locomotive: 
                cout << "Locomotive : " << it->second << endl;
                break;
            default: 
                cout << "Inconnu" << endl;
                break;
        }
    }
}