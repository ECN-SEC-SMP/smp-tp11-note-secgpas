#include "Joueur.h"

using namespace std;



 
// constructeurs
Joueur::Joueur(couleur_e c){// : constructeur, on veut créer l’entiereté du dico avec des valeurs nulles à chaque fois (puisqu’on a pas encore de cartes)
    couleur = c;               
    mainCarte = { {"Locomotive", 0}, {"Jaune", 0}, {"Bleu", 0}, {"Rouge", 0}, {"Vert", 0}, {"Noir", 0}, {"Blanc", 0}  };     
    mainWagon = 20;                    
    nbTicketGagne = 0;                  
}; 


// méthodes

void Joueur::piocher(int nbAPiocher, Pioche& la_pioche){  // : ajoute les cartes piochées à la main du joueur (attention à bien gérer le type de cartes choisies et pour les CTrain utiliser le setteur pour l’ajout ?)
    // objectif : on copie le dernier élément de "la_pioche", puis en fonction du type de pioche on rajoute la carte soit dans dans map<Couleur_e,int> mainCarte vecteur main puis on les supprime de la pioche

    for (int i=0 ; i< (nbAPiocher), ; i++){
        Carte* carte = la_pioche.getDeck().back();                                 // on stocke la valeur de la derniere carte posée sur la pioche type type : 
        if (carte->getType() == 0){                                      // si les cartes de la pioches sont des cartes train
            mainCarte[carte->getCouleur()] ++;}                           // on rajoute +1 au compteur de cartes correspondant à la couleur de la carte qu'on a pioché
        else {
            mainTicket.pushback(carte);
            la_pioche.popLastCarte();}
    }

}; 
void Joueur::poserWagon(VoieFerre& voie){ // : permet à un joueur de poser sa carte (attention à bien vérifier la disponibilité du trajet et le fait qu’il n’ait pas pris l’autre éventuel trajet parallèle)
    if ((voie->poids <= (mainCarte[voie.c] + mainCarte["Locomotive"])) && (voie.estDispo == 1)){       // on check que le joueur a suffisement de cartes train
        if ((voie.getVoiesFerrees().size() == 1) || ( (voie.getVoiesFerrees()[1].getProprio() || voie.getVoiesFerrees()[2].getProprio()) == Joueur )){ // si le joueur n'est pas proprio de l'autre voie
            for (int i ; i < voie.poids ; i++){     // on répète autant de foiq 'uil y a de trains
                if (mainCarte[voie.c] != 0){        // tant que le nombre de cartes train couleur est non nul
                    mainCarte[voie.c] --;               // on les envleve de la main
                    // mettre dans la défausse ???
                }
                else{
                    mainCarte["Locomotive"] --;         // sinon on enlève les locomotives
                    // mettre dans la défausse ???
                }
            }
            voie.setProprio(Joueur);
            nbTicketGagne ++ ;
        }

    }
    else{
        cout << "Vous n'avez pas assez de wagons" << endl;
    }
    

};
void Joueur::defausser(Carte c){ // : méthode qui permet de défausser une carte
    pushDefausse(Carte* c);
    if (c.getType() == 0){                                      // si les cartes de la pioches sont des cartes train
        mainCarte[c.getCouleur()] --;}                           // on enlève 1 au compteur de cartes correspondant à la couleur de la carte
    else {
        mainTicket["c"].pop;};
};


// accesseurs

int Joueur::getMainWagon(){
    return mainWagon;
};
int Joueur::getCouleur(){
    return couleur;
};
int Joueur::getNbTicketGagne(){
    return nbTicketGagne;
};
map<Couleur_e,int> Joueur::getMainCarte(){
    return mainCarte;
};
vector<Ticket*> Joueur::getMainTicket(){
    return mainTicket;
};


vector Joueur::afficherMain(){ // : affiche la main complète d’un joueur (ie. mainCarte, mainTicket, mainWagon)
    cout << "Les cartes de la main du joueur sont les suivantes :" << getMainCarte() << endl;
    cout << "Les tickets sont :" << getMainTicket() << endl;
    cout << "Le nombre de wagons restants à poser est :" << getMainWagon() << endl;
}; 
