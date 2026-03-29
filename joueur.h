#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <map>
#ifndef joueur_h
#define joueur_h 
using namespace std;


class joueur {


protected :

Couleur_e couleur;                // c'est une liste qui attribue à chaque couleur possible un numéro
map<Couleur_e,int> mainCarte;     // c'est une liste qui répertorie notre main en indiquant chaque couleur par son numéro et le nombre d'occurence de celle-ci dans notre main
int mainWagon;                      // nombre de wagons possédés par le joueur
vector<Ticket*> mainTicket;         // répertorie les tickets possédés par le joueur
int nbticketgagne;                // nombre de tickets gagnés par le joueur



public:

// méthodes
void piocher(int nbAPiocher, Pioche type); // : ajoute les cartes piochées à la main du joueur (attention à bien gérer le type de cartes choisies et pour les CTrain utiliser le setteur pour l’ajout ?)
void poserWagon(enumVille a, enumVille b, enumCouleur c); // : permet à un jour de poser sa carte (attention à bien vérifier la disponibilité du trajet et le fait qu’il n’ait pas pris l’autre éventuel trajet parallèle)
void defausserCarte(Carte c); // : méthode qui permet de défausser une carte


// accesseurs
int get_mainWagon();
int get_couleur();
int get_nbticketgagne();
map<Couleur_e,int> get_mainCarte();
vector<Ticket*> get_mainTicket();
// jsp vector afficherMain(); // : affiche la main complète d’un joueur (ie. mainCarte, mainTicket, mainWagon)

// constructeurs
joueur(int couleur); // : constructeur, on veut créer l’entiereté du dico avec des valeurs nulles à chaque fois (puisqu’on a pas encore de cartes)




};

#endif /* joueur_h */