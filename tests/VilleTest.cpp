#include "Ville.h"
#include "fonctionAnnexe.h"
#include <gtest/gtest.h>
#include <iostream>
#include "config.h"

TEST(VilleTest, testConstructeurValide) {
    Ville v(0);
    EXPECT_FALSE(v.getNomVille().empty());
}

TEST(VilleTest, testConstructeurIndexNegatif) {
    Ville v(-1);
    EXPECT_EQ("",v.getNomVille());
}

TEST(VilleTest, testConstructeurIndexTropGrand) {
    Ville v(9999);
    EXPECT_EQ("",v.getNomVille());
}

TEST(VilleTest, testGetNomVille) {
    Ville a = Ville(0);
    EXPECT_EQ("Seattle", a.getNomVille());
}

//  ==========Test Ville*========================
TEST(VilleTest, testEstAdjacentValide) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    Ville c = Ville(7);
    a.ajoutVilleAdjacente(&b);
    EXPECT_EQ(true, a.estAdjacent(&b));
    EXPECT_EQ(false, a.estAdjacent(&c));
}

TEST(VilleTest, testEstAdjacentFaux) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    Ville c = Ville(7);
    a.ajoutVilleAdjacente(&b);
    EXPECT_EQ(false, a.estAdjacent(&c));
}

TEST(VilleTest, testEstAdjacentAvecLuiMeme) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    EXPECT_EQ(false, a.estAdjacent(&a));
}

TEST(VilleTest, testEstAdjacentAvecRien) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    Ville *c = nullptr;
    EXPECT_EQ(false, a.estAdjacent(c));
}

TEST(VilleTest, testEstAdjacentListeVide) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    EXPECT_FALSE(a.estAdjacent(&b));
}

//  ===========Test paramètre string============

TEST(VilleTest, testEstAdjacentNomValide) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    EXPECT_TRUE(a.estAdjacent(b.getNomVille()));
}

TEST(VilleTest, testEstAdjacentNomInvalide) {
    Ville a = Ville(0);
    EXPECT_FALSE(a.estAdjacent("VilleInexistante"));
}

TEST(VilleTest, testEstAdjacentNomVide) {
    Ville a = Ville(0);
    EXPECT_FALSE(a.estAdjacent(""));
}

//  ============================================

TEST(VilleTest, testAfficheAdj) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    testing::internal::CaptureStdout();
    a.afficheAdjacent();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ("Calgary\n", output);
    
}

TEST(VilleTest, testGetAdjacentVide) {
    Ville a = Ville(0);
    EXPECT_TRUE(a.getAdjacent().empty());
}

TEST(VilleTest, testGetAdjacentNonVide) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    vector<Ville*> attendu = { &b };
    EXPECT_EQ(a.getAdjacent(), attendu);
}

TEST(VilleTest, testAjoutVilleAdjacente) {
    Ville a = Ville(0);
    Ville b = Ville(1);
    a.ajoutVilleAdjacente(&b);
    vector<Ville*> attendu = { &b };
    EXPECT_EQ(a.getAdjacent(), attendu);
}

TEST(VilleTest, testAjoutVilleAdjacenteNulle) {
    Ville a = Ville(0);
    a.ajoutVilleAdjacente(nullptr);
    EXPECT_TRUE(a.getAdjacent().empty());
}
