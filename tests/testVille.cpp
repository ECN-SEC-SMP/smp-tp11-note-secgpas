#include "Ville.h"
#include "fonctionAnnexe.h"
#include <gtest/gtest.h>
#include <iostream>


TEST(VilleTest,testDesMethodes){
    ouvrirFichierMap("/home/riana/Documents/smp-tp11-note-secgpas/map.csv");

    //Test de la création d'une ville et de l'ajout du nom
    Ville a = Ville(0);
    EXPECT_EQ("Seattle", a.getNomVille());

    //Test de estAdjacent()
    Ville b = Ville(1);
    
}