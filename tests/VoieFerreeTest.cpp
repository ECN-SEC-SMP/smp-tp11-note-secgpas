#include "Ville.h"
#include "VoieFerree.h"
#include "/home/riana/Documents/smp-tp11-note-secgpas/include/Joueur.h"
#include "fonctionAnnexe.h"
#include "types.h"
#include <gtest/gtest.h>
#include <iostream>
#include "config.h"


TEST(VoieFerreeTest, testDesMethodes) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    Ville* v_1 = l1.getVille1();
    Ville* v_2 = l1.getVille2();
    Joueur j1 = Joueur(Couleur_e::Vert);
    EXPECT_EQ(true,l1.estDispo());
    l1.setProprio(&j1);
    EXPECT_EQ("Seattle",v_1->getNomVille());
    EXPECT_EQ("Calgary",v_2->getNomVille()); 
    EXPECT_EQ(false,l1.estDispo());
    EXPECT_EQ(&j1,l1.getProprio());
    EXPECT_EQ(Couleur_e::Noir, l1.getCouleur());
    EXPECT_EQ(4, l1.getPoids());
    
}

