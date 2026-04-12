#include "Ville.h"
#include "VoieFerree.h"
#include "Joueur.h"
#include "fonctionAnnexe.h"
#include "types.h"
#include <gtest/gtest.h>
#include <iostream>
#include "config.h"


TEST(VoieFerreeTest, testConstructeur) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_EQ(&a,l1.getVille1());
}

TEST(VoieFerreeTest, testGetVilleFonctionnel) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_EQ(&a,l1.getVille1());
    EXPECT_EQ(&b,l1.getVille2());
}

TEST(VoieFerreeTest, testGetVillePasFonctionnel) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_NE(&b,l1.getVille1());
    EXPECT_NE(&a,l1.getVille2());
}

TEST(VoieFerreeTest, testDisponibiliteTrue) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);

    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    EXPECT_EQ(true,l1.estDispo());
}

TEST(VoieFerreeTest, testDisponibiliteFalse) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(false,l1.estDispo());
}


TEST(VoieFerreeTest, testSetProprioPremier) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(&j1,l1.getProprio());
}

TEST(VoieFerreeTest, testSetProprioDeuxieme) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    l1.setProprio(&j2); //ne dois pas changer
    EXPECT_EQ(&j1,l1.getProprio());
}

TEST(VoieFerreeTest, testGetProprioVide) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(nullptr,l1.getProprio());
}

TEST(VoieFerreeTest, testGetProprio) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(&j1,l1.getProprio());
}

TEST(VoieFerreeTest, testGetProprioMauvais) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    l1.setProprio(&j2);
    EXPECT_NE(&j2,l1.getProprio());
}

TEST(VoieFerreeTest, testGetCouleur) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(Couleur_e::Noir, l1.getCouleur());
}

TEST(VoieFerreeTest, testGetPoids) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(4, l1.getPoids());
}