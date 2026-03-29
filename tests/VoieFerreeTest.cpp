#include "Ville.h"
#include "VoieFerree.h"
#include "fonctionAnnexe.h"
#include "types.h"
#include <gtest/gtest.h>
#include <iostream>



TEST(VoieFerreeTest,testDesMethodes){
    ouvrirFichierMap("/home/riana/Documents/smp-tp11-note-secgpas/map.csv");

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    Ville* v_1 = l1.getVille1();
    EXPECT_EQ("Seattle",v_1->getNomVille());
    EXPECT_EQ(Couleur_e::Noir, l1.getCouleur());
    EXPECT_EQ(4, l1.getPoids());
    
}

