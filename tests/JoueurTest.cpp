#include "Carte.h"
#include "types.h"
#include "Joueur.h"
#include <gtest/gtest.h>

TEST(JoueurTest, testDesMethodes) {
    //Test de la création d'un Joueur
    Joueur j1 = Joueur(Couleur_e::Bleu);
    EXPECT_EQ(20, j1.getMainWagon());

    //Test de la méthode piocher
    Pioche pw(Pioche_type_e::CarteW);
    j1.piocher(pw);
    int compt = 0;
    for (map<Couleur_e, int>::iterator it = (j1.getMainCarte()).begin(); it != (j1.getMainCarte()).end(); ++it){
        compt = compt + it->second;
    }
    EXPECT_EQ(3, compt);

}

