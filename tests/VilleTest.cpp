#include "Ville.h"
#include "fonctionAnnexe.h"
#include <gtest/gtest.h>
#include <iostream>


TEST(VilleTest,testDesMethodes){
    ouvrirFichierMap("../map.csv");

    //Test de la création d'une ville et de l'ajout du nom
    Ville a = Ville(0);
    EXPECT_EQ("Seattle", a.getNomVille());

    //Test de estAdjacent()
    Ville b = Ville(1);
    Ville c = Ville(7);
    a.ajoutVilleAdjacente(&b);
    EXPECT_EQ(true, a.estAdjacent(1));
    EXPECT_EQ(false, a.estAdjacent(7));

    testing::internal::CaptureStdout();
    a.afficheAdjacent();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Calgary\n", output);
    
    vector<Ville*> attendu = { &b };
    EXPECT_EQ(a.getAdjacent(), attendu);
  

}