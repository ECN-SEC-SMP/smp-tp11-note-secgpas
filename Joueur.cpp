#include "Joueur.h"

using namespace std;



 
// constructeurs
Joueur::Joueur(int coul){// : constructeur, on veut créer l’entiereté du dico avec des valeurs nulles à chaque fois (puisqu’on a pas encore de cartes)
    coul = Couleur;               
    // jsp map<enumCouleur,int> mainCarte;     
    mainWagon = 20;                    
    // jsp comment faire vector <Ticket*> mainTicket;         
    nbticketgagne = 0;                  

}; 


// méthodes

void Joueur::piocher(Pioche la_pioche){  // : ajoute les cartes piochées à la main du joueur (attention à bien gérer le type de cartes choisies et pour les CTrain utiliser le setteur pour l’ajout ?)
    // objectif : on copie le dernier élément de "la_pioche", puis en fonction du type de pioche on rajoute la carte soit dans dans map<Couleur_e,int> mainCarte vecteur main puis on les supprime de la pioche

    for (int i=0 ; i<2 ; i++){
        Carte* carte = la_pioche.getDeck().back();                                 // on stocke la valeur de la derniere carte posée sur la pioche type type : 
        if (carte->getType() == 0){                                      // si les cartes de la pioches sont des cartes train
            mainCarte[carte->getCouleur()] ++;}                           // on rajoute +1 au compteur de cartes correspondant à la couleur de la carte qu'on a pioché
        else {
            mainTicket.pushback(carte);
            la_pioche.deleteBack();}
    }

}; 
void Joueur::poserWagon(enumVille a, enumVille b, enumCouleur c){ // : permet à un jour de poser sa carte (attention à bien vérifier la disponibilité du trajet et le fait qu’il n’ait pas pris l’autre éventuel trajet parallèle)


};
void Joueur::defausserCarte(Carte c){ // : méthode qui permet de défausser une carte
        // on supprime c de notre main
        // on ajoute c à la défausse
};


// accesseurs

int Joueur::get_mainWagon(){
    return mainWagon;
};
int Joueur::get_couleur(){
    return couleur;
};
int Joueur::get_nbticketgagne(){
    return nbticketgagne;
};
map<Couleur_e,int> Joueur::get_mainCarte(){
    return mainCarte;
};
vector<Ticket*> Joueur::get_mainTicket(){
    return mainTicket;
};


vector Joueur::afficherMain(){ // : affiche la main complète d’un joueur (ie. mainCarte, mainTicket, mainWagon)
    cout << "Les cartes de la main du joueur sont les suivantes :" << get_mainCarte() << endl;
    cout << "Les tickets sont :" << get_mainTicket() << endl;
    cout << "Le nombre de wagons restants à poser est :" << get_mainWagon() << endl;
}; 
