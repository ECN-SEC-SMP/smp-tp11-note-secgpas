#include "Ville.h"
#include "VoieFerree.h"
#include "fonctionAnnexe.h"
#include "types.h"
#include <gtest/gtest.h>
#include <iostream>
#include "config.h"


TEST(VoieFerreeTest, testDesMethodes) {
    ouvrirFichierMap(MAP_FILE_PATH, TODO);

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    Ville* v_1 = l1.getVille1();
    EXPECT_EQ("Seattle",v_1->getNomVille());
    EXPECT_EQ(Couleur_e::Noir, l1.getCouleur());
    EXPECT_EQ(4, l1.getPoids());
    
}

