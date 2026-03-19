#include "Jeu.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>

Jeu::Jeu(int nbJoueur){
    for(int i = 1; i <= nbJoueur; i++){
        int couleur;
        cout << "Quelle couleur choisis-tu ?" << endl;
        cin >> couleur >> endl;
        Joueur *j = new Joueur(couleur);
        this->joueurs.push_back(j);//add au vecteur 
    }
    this->p = Plateau();
    this->tickets = Pioche(); //tickets //444
    this->train = Pioche(); //train //444
}

bool Jeu::estFinie(){
    for(int i = 0; i <= (joueurs.size()-1); i++){
        if(joueurs.at(i)->mainWagon == 0){
            return true;
        }
        if(joueurs.at(i)->nbTicketReussis == 6){
            return true
        }
    }
    return false;
}

void Jeu::partie(){
    int decision;
    cout << "0 : Pioche" << endl;
    cout << "1 : Poser Wagon" << endl;
    cout << "2 : Passer son Tour" << endl;
    cin << decision << endl;
    if(decision == 0){

    }
    if(decision == 1){

    }else{

    }
    this->estFinie();
    
}