#include "joueur.h"
using namespace std;



 

// méthodes
void joueur::piocher(int nbAPiocher, Pioche la_pioche){  // : ajoute les cartes piochées à la main du joueur (attention à bien gérer le type de cartes choisies et pour les CTrain utiliser le setteur pour l’ajout ?)
    // objectif : on veut prend n cartes dans la picohe choisie, on les copie dans notre main puis on les supprime de la pioche
    // for i in (nbAPiocher) :
    //     carte = Pioche->deck_c.back()                  // on stocke la valeur de la derniere carte posée sur la pioche type type : 
    //     if la_pioche->cartes->type = 0:                // si les cartes de la pioches sont des cartes train
    //          mainCarte[carte.getCouleur()] +=1           // on rajoute +1 au compteur de cartes correspondant à la couleur de la carte qu'on a pioché
    //     else :
    //          on rajoute ticket dans main ticket (jsp comment faire)
    //     

}; 
void joueur::poserWagon(enumVille a, enumVille b, enumCouleur c){ // : permet à un jour de poser sa carte (attention à bien vérifier la disponibilité du trajet et le fait qu’il n’ait pas pris l’autre éventuel trajet parallèle)


};
void joueur::defausserCarte(Carte c){ // : méthode qui permet de défausser une carte

};


// accesseurs

int joueur::get_mainWagon(){
    return mainWagon;
};
int joueur::get_couleur(){
    return couleur;
};
int joueur::get_nbticketgagne(){
    return nbticketgagne;
};
map<Couleur_e,int> joueur::get_mainCarte(){
    return mainCarte;
};
vector<Ticket*> joueur::get_mainTicket(){
    return mainTicket;
};


vector joueur::afficherMain(){ // : affiche la main complète d’un joueur (ie. mainCarte, mainTicket, mainWagon)
    cout << "Les cartes de la main du joueur sont les suivantes :" << get_mainCarte() << endl;
    cout << "Les tickets sont :" << get_mainTicket() << endl;
    cout << "Le nombre de wagons restants à poser est :" << get_mainWagon() << endl;
}; 

// constructeurs
joueur::joueur(int Couleur){// : constructeur, on veut créer l’entiereté du dico avec des valeurs nulles à chaque fois (puisqu’on a pas encore de cartes)
    couleur = Couleur;               
    // jsp map<enumCouleur,int> mainCarte;     
    mainWagon = 20;                    
    // jsp comment faire vector <Ticket*> mainTicket;         
    nbticketgagne = 0;                  

}; 
