#include <iostream>
#ifndef comptead_h
#define comptead_h 


class joueur : public compte{


protected :
enumCouleur Couleur;
map<enumCouleur,int>;
int mainWagon;
vector<Ticket*> mainTicket;
int nb_ticket_gagne;

public:

void pioche(int nb_a_piocher, pioche type);
void poserWagon(enumVille a, enumVille b, enumCouleur c)
void afficherMain();
};

#endif /* comptead_h */