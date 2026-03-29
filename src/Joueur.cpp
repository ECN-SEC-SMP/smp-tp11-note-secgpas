#include <iostream>
#include "Joueur.h"
#include "Plateau.h"
#include "VoieFerree.h"

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

void Joueur::piocher(int nbAPiocher, Pioche& type){
    if (! type.estPiocheVide()){
        switch (type.getPiocheType())
    {
    case Pioche_type_e::CarteW :
        for (int i = 0; i < nbAPiocher; i++){
            CTrain* carte = dynamic_cast<CTrain*>(type.getDeck().back());
            type.getDeck().pop_back();
            mainCarte[carte->getCouleur()]++;
        }
        break;

    case Pioche_type_e::Ticket :
        for (int i = 0; i < nbAPiocher; i++){
            Ticket* carte1 = dynamic_cast<Ticket*>(type.getDeck().back());
            type.getDeck().pop_back();
            mainTicket.push_back(carte1);
        }
        break;

    default:
        break;
    }
    }
}

void Joueur::poserWagon(Ville* a, Ville* b, Couleur_e c, Plateau& plateau){
    for (int i = 0; i < plateau.getVoieFerree().size(); i++){
        if (((plateau.getVoieFerree()[i].getVille1() == a && plateau.getVoieFerree()[i].getVille2() == b) ||(plateau.getVoieFerree()[i].getVille1() == b && plateau.getVoieFerree()[i].getVille2() == a)) && (plateau.getVoieFerree()[i].getCouleur() == c)){
            if (plateau.getVoieFerree()[i].estDispo()){
                mainWagon = mainWagon - plateau.getVoieFerree()[i].getPoids();
                plateau.getVoieFerree()[i].setProprio(this); 
            }
        }
    }
}

void Joueur::defausser(Pioche& piocheTicket){
    mainTicket.pop_back();
    mainTicket.pop_back();
    piocher(2, piocheTicket);
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