#include "Ville.h"
#include "VoieFerree.h"
#include "Joueur.h"
#include "fonctionAnnexe.h"
#include "types.h"
#include <gtest/gtest.h>
#include <iostream>
#include "config.h"


TEST(VoieFerreeTest, testConstructeur) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_EQ(&a,l1.getVille1());
}

TEST(VoieFerreeTest, testGetVilleFonctionnel) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_EQ(&a,l1.getVille1());
    EXPECT_EQ(&b,l1.getVille2());
}

TEST(VoieFerreeTest, testGetVillePasFonctionnel) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));

    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    EXPECT_NE(&b,l1.getVille1());
    EXPECT_NE(&a,l1.getVille2());
}

TEST(VoieFerreeTest, testDisponibiliteTrue) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);

    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    EXPECT_EQ(true,l1.estDispo());
}

TEST(VoieFerreeTest, testDisponibiliteFalse) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(false,l1.estDispo());
}


TEST(VoieFerreeTest, testSetProprioPremier) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(&j1,l1.getProprio());
}

TEST(VoieFerreeTest, testSetProprioDeuxieme) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
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
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(nullptr,l1.getProprio());
}

TEST(VoieFerreeTest, testGetProprio) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    Joueur j1 = Joueur(Couleur_e::Vert);
    Joueur j2 = Joueur(Couleur_e::Blanc);
    l1.setProprio(&j1);
    EXPECT_EQ(&j1,l1.getProprio());
}

TEST(VoieFerreeTest, testGetProprioMauvais) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
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
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(Couleur_e::Noir, l1.getCouleur());
}

TEST(VoieFerreeTest, testGetPoids) {
    listeVoieFerre_t voies;
    listeVille_t villes;
    EXPECT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, voies, villes));
    Ville a = Ville(0);
    Ville b = Ville(1);
    VoieFerree l1 = VoieFerree(&a, &b, 4, Couleur_e::Noir);
    
    EXPECT_EQ(4, l1.getPoids());
}