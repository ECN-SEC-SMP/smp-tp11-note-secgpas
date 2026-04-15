//
// Created by David PROSPÉRIN on 03/04/2026.
//

#include "config.h"
#include "fonctionAnnexe.h"
#include <gtest/gtest.h>

TEST(fonctionAnnexeTest, MapFileShouldBeNotLoaded) {
    listeVoieFerre_t listeVoieFerre;
    listeVille_t listeVille;

    testing::internal::CaptureStderr();
    ASSERT_FALSE(ouvrirFichierMap("fichier_non_existant.csv", listeVoieFerre, listeVille));
    std::string err_message = testing::internal::GetCapturedStderr();

    ASSERT_EQ(err_message, "Erreur de chargement du fichier carte : fichier_non_existant.csv\n");
    ASSERT_EQ(listeVille.size(), 0);
    ASSERT_EQ(listeVoieFerre.size(), 0);
}

TEST(fonctionAnnexeTest, MapFileShouldBeLoaded) {
    listeVoieFerre_t listeVoieFerre;
    listeVille_t listeVille;

    ASSERT_TRUE(ouvrirFichierMap(MAP_FILE_PATH, listeVoieFerre, listeVille));
    ASSERT_EQ(listeVille.size(), 19);
    ASSERT_EQ(listeVoieFerre.size(), 39);

    // Vérifier toutes les villes
    ASSERT_EQ(listeVille[0], "Seattle");
    ASSERT_EQ(listeVille[1], "Calgary");
    ASSERT_EQ(listeVille[2], "Helena");
    ASSERT_EQ(listeVille[3], "San Francisco");
    ASSERT_EQ(listeVille[4], "Los Angeles");
    ASSERT_EQ(listeVille[5], "Salt Lake City");
    ASSERT_EQ(listeVille[6], "Albuquerque");
    ASSERT_EQ(listeVille[7], "Denver");
    ASSERT_EQ(listeVille[8], "Winnipeg");
    ASSERT_EQ(listeVille[9], "Duluth");
    ASSERT_EQ(listeVille[10], "Kansas City");
    ASSERT_EQ(listeVille[11], "Dallas");
    ASSERT_EQ(listeVille[12], "New Orleans");
    ASSERT_EQ(listeVille[13], "Atlanta");
    ASSERT_EQ(listeVille[14], "Miami");
    ASSERT_EQ(listeVille[15], "Chicago");
    ASSERT_EQ(listeVille[16], "Washington");
    ASSERT_EQ(listeVille[17], "Montreal");
    ASSERT_EQ(listeVille[18], "New York");

    // Vérifier toutes les voies ferrées
    ASSERT_EQ(listeVoieFerre[0][0], "Seattle");
    ASSERT_EQ(listeVoieFerre[0][1], "Calgary");
    ASSERT_EQ(listeVoieFerre[0][2], "black");
    ASSERT_EQ(listeVoieFerre[0][3], "4");

    ASSERT_EQ(listeVoieFerre[1][0], "Seattle");
    ASSERT_EQ(listeVoieFerre[1][1], "Calgary");
    ASSERT_EQ(listeVoieFerre[1][2], "red");
    ASSERT_EQ(listeVoieFerre[1][3], "4");

    ASSERT_EQ(listeVoieFerre[2][0], "Seattle");
    ASSERT_EQ(listeVoieFerre[2][1], "Helena");
    ASSERT_EQ(listeVoieFerre[2][2], "yellow");
    ASSERT_EQ(listeVoieFerre[2][3], "4");

    ASSERT_EQ(listeVoieFerre[3][0], "Seattle");
    ASSERT_EQ(listeVoieFerre[3][1], "San Francisco");
    ASSERT_EQ(listeVoieFerre[3][2], "blue");
    ASSERT_EQ(listeVoieFerre[3][3], "5");

    ASSERT_EQ(listeVoieFerre[4][0], "San Francisco");
    ASSERT_EQ(listeVoieFerre[4][1], "Los Angeles");
    ASSERT_EQ(listeVoieFerre[4][2], "yellow");
    ASSERT_EQ(listeVoieFerre[4][3], "3");

    ASSERT_EQ(listeVoieFerre[5][0], "San Francisco");
    ASSERT_EQ(listeVoieFerre[5][1], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[5][2], "orange");
    ASSERT_EQ(listeVoieFerre[5][3], "3");

    ASSERT_EQ(listeVoieFerre[6][0], "San Francisco");
    ASSERT_EQ(listeVoieFerre[6][1], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[6][2], "green");
    ASSERT_EQ(listeVoieFerre[6][3], "3");

    ASSERT_EQ(listeVoieFerre[7][0], "Los Angeles");
    ASSERT_EQ(listeVoieFerre[7][1], "Albuquerque");
    ASSERT_EQ(listeVoieFerre[7][2], "blue");
    ASSERT_EQ(listeVoieFerre[7][3], "4");

    ASSERT_EQ(listeVoieFerre[8][0], "Los Angeles");
    ASSERT_EQ(listeVoieFerre[8][1], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[8][2], "red");
    ASSERT_EQ(listeVoieFerre[8][3], "3");

    ASSERT_EQ(listeVoieFerre[9][0], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[9][1], "Helena");
    ASSERT_EQ(listeVoieFerre[9][2], "yellow");
    ASSERT_EQ(listeVoieFerre[9][3], "3");

    ASSERT_EQ(listeVoieFerre[10][0], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[10][1], "Denver");
    ASSERT_EQ(listeVoieFerre[10][2], "blue");
    ASSERT_EQ(listeVoieFerre[10][3], "3");

    ASSERT_EQ(listeVoieFerre[11][0], "Salt Lake City");
    ASSERT_EQ(listeVoieFerre[11][1], "Denver");
    ASSERT_EQ(listeVoieFerre[11][2], "black");
    ASSERT_EQ(listeVoieFerre[11][3], "3");

    ASSERT_EQ(listeVoieFerre[12][0], "Calgary");
    ASSERT_EQ(listeVoieFerre[12][1], "Winnipeg");
    ASSERT_EQ(listeVoieFerre[12][2], "yellow");
    ASSERT_EQ(listeVoieFerre[12][3], "4");

    ASSERT_EQ(listeVoieFerre[13][0], "Calgary");
    ASSERT_EQ(listeVoieFerre[13][1], "Winnipeg");
    ASSERT_EQ(listeVoieFerre[13][2], "green");
    ASSERT_EQ(listeVoieFerre[13][3], "4");

    ASSERT_EQ(listeVoieFerre[14][0], "Winnipeg");
    ASSERT_EQ(listeVoieFerre[14][1], "Duluth");
    ASSERT_EQ(listeVoieFerre[14][2], "black");
    ASSERT_EQ(listeVoieFerre[14][3], "3");

    ASSERT_EQ(listeVoieFerre[15][0], "Winnipeg");
    ASSERT_EQ(listeVoieFerre[15][1], "Duluth");
    ASSERT_EQ(listeVoieFerre[15][2], "red");
    ASSERT_EQ(listeVoieFerre[15][3], "3");

    ASSERT_EQ(listeVoieFerre[16][0], "Helena");
    ASSERT_EQ(listeVoieFerre[16][1], "Denver");
    ASSERT_EQ(listeVoieFerre[16][2], "green");
    ASSERT_EQ(listeVoieFerre[16][3], "3");

    ASSERT_EQ(listeVoieFerre[17][0], "Helena");
    ASSERT_EQ(listeVoieFerre[17][1], "Kansas City");
    ASSERT_EQ(listeVoieFerre[17][2], "black");
    ASSERT_EQ(listeVoieFerre[17][3], "5");

    ASSERT_EQ(listeVoieFerre[18][0], "Denver");
    ASSERT_EQ(listeVoieFerre[18][1], "Kansas City");
    ASSERT_EQ(listeVoieFerre[18][2], "green");
    ASSERT_EQ(listeVoieFerre[18][3], "4");

    ASSERT_EQ(listeVoieFerre[19][0], "Denver");
    ASSERT_EQ(listeVoieFerre[19][1], "Dallas");
    ASSERT_EQ(listeVoieFerre[19][2], "yellow");
    ASSERT_EQ(listeVoieFerre[19][3], "3");

    ASSERT_EQ(listeVoieFerre[20][0], "Denver");
    ASSERT_EQ(listeVoieFerre[20][1], "Albuquerque");
    ASSERT_EQ(listeVoieFerre[20][2], "red");
    ASSERT_EQ(listeVoieFerre[20][3], "2");

    ASSERT_EQ(listeVoieFerre[21][0], "Albuquerque");
    ASSERT_EQ(listeVoieFerre[21][1], "Dallas");
    ASSERT_EQ(listeVoieFerre[21][2], "green");
    ASSERT_EQ(listeVoieFerre[21][3], "3");

    ASSERT_EQ(listeVoieFerre[22][0], "Dallas");
    ASSERT_EQ(listeVoieFerre[22][1], "New Orleans");
    ASSERT_EQ(listeVoieFerre[22][2], "red");
    ASSERT_EQ(listeVoieFerre[22][3], "3");

    ASSERT_EQ(listeVoieFerre[23][0], "Dallas");
    ASSERT_EQ(listeVoieFerre[23][1], "Atlanta");
    ASSERT_EQ(listeVoieFerre[23][2], "blue");
    ASSERT_EQ(listeVoieFerre[23][3], "3");

    ASSERT_EQ(listeVoieFerre[24][0], "New Orleans");
    ASSERT_EQ(listeVoieFerre[24][1], "Atlanta");
    ASSERT_EQ(listeVoieFerre[24][2], "yellow");
    ASSERT_EQ(listeVoieFerre[24][3], "4");

    ASSERT_EQ(listeVoieFerre[25][0], "New Orleans");
    ASSERT_EQ(listeVoieFerre[25][1], "Miami");
    ASSERT_EQ(listeVoieFerre[25][2], "white");
    ASSERT_EQ(listeVoieFerre[25][3], "6");

    ASSERT_EQ(listeVoieFerre[26][0], "Atlanta");
    ASSERT_EQ(listeVoieFerre[26][1], "Miami");
    ASSERT_EQ(listeVoieFerre[26][2], "green");
    ASSERT_EQ(listeVoieFerre[26][3], "5");

    ASSERT_EQ(listeVoieFerre[27][0], "Atlanta");
    ASSERT_EQ(listeVoieFerre[27][1], "Chicago");
    ASSERT_EQ(listeVoieFerre[27][2], "blue");
    ASSERT_EQ(listeVoieFerre[27][3], "4");

    ASSERT_EQ(listeVoieFerre[28][0], "Kansas City");
    ASSERT_EQ(listeVoieFerre[28][1], "Chicago");
    ASSERT_EQ(listeVoieFerre[28][2], "black");
    ASSERT_EQ(listeVoieFerre[28][3], "4");

    ASSERT_EQ(listeVoieFerre[29][0], "Kansas City");
    ASSERT_EQ(listeVoieFerre[29][1], "Chicago");
    ASSERT_EQ(listeVoieFerre[29][2], "white");
    ASSERT_EQ(listeVoieFerre[29][3], "4");

    ASSERT_EQ(listeVoieFerre[30][0], "Chicago");
    ASSERT_EQ(listeVoieFerre[30][1], "Washington");
    ASSERT_EQ(listeVoieFerre[30][2], "black");
    ASSERT_EQ(listeVoieFerre[30][3], "4");

    ASSERT_EQ(listeVoieFerre[31][0], "Chicago");
    ASSERT_EQ(listeVoieFerre[31][1], "Duluth");
    ASSERT_EQ(listeVoieFerre[31][2], "red");
    ASSERT_EQ(listeVoieFerre[31][3], "3");

    ASSERT_EQ(listeVoieFerre[32][0], "Duluth");
    ASSERT_EQ(listeVoieFerre[32][1], "Montreal");
    ASSERT_EQ(listeVoieFerre[32][2], "blue");
    ASSERT_EQ(listeVoieFerre[32][3], "4");

    ASSERT_EQ(listeVoieFerre[33][0], "Duluth");
    ASSERT_EQ(listeVoieFerre[33][1], "Chicago");
    ASSERT_EQ(listeVoieFerre[33][2], "white");
    ASSERT_EQ(listeVoieFerre[33][3], "3");

    ASSERT_EQ(listeVoieFerre[34][0], "Montreal");
    ASSERT_EQ(listeVoieFerre[34][1], "New York");
    ASSERT_EQ(listeVoieFerre[34][2], "blue");
    ASSERT_EQ(listeVoieFerre[34][3], "3");

    ASSERT_EQ(listeVoieFerre[35][0], "Montreal");
    ASSERT_EQ(listeVoieFerre[35][1], "New York");
    ASSERT_EQ(listeVoieFerre[35][2], "green");
    ASSERT_EQ(listeVoieFerre[35][3], "3");

    ASSERT_EQ(listeVoieFerre[36][0], "Washington");
    ASSERT_EQ(listeVoieFerre[36][1], "New York");
    ASSERT_EQ(listeVoieFerre[36][2], "red");
    ASSERT_EQ(listeVoieFerre[36][3], "3");

    ASSERT_EQ(listeVoieFerre[37][0], "Washington");
    ASSERT_EQ(listeVoieFerre[37][1], "New York");
    ASSERT_EQ(listeVoieFerre[37][2], "white");
    ASSERT_EQ(listeVoieFerre[37][3], "3");

    ASSERT_EQ(listeVoieFerre[38][0], "Washington");
    ASSERT_EQ(listeVoieFerre[38][1], "Atlanta");
    ASSERT_EQ(listeVoieFerre[38][2], "yellow");
    ASSERT_EQ(listeVoieFerre[38][3], "3");
}

TEST(fonctionAnnexeTest, GetCouleurShouldReturnCorrectEnum) {
    ASSERT_EQ(getCouleur("red"), Couleur_e::Rouge);
    ASSERT_EQ(getCouleur("green"), Couleur_e::Vert);
    ASSERT_EQ(getCouleur("blue"), Couleur_e::Bleu);
    ASSERT_EQ(getCouleur("yellow"), Couleur_e::Jaune);
    ASSERT_EQ(getCouleur("black"), Couleur_e::Noir);
    ASSERT_EQ(getCouleur("white"), Couleur_e::Blanc);
    ASSERT_EQ(getCouleur("orange"), Couleur_e::Orange);
    ASSERT_EQ(getCouleur("locomotive"), Couleur_e::Locomotive);
}
TEST(fonctionAnnexeTest, GetCouleurShouldReturnInconnueForUnknownColor) {
    testing::internal::CaptureStderr();
    ASSERT_EQ(getCouleur("purple"), Couleur_e::Inconnue);
    std::string err_message = testing::internal::GetCapturedStderr();

    ASSERT_EQ(err_message, "Couleur non reconnue : purple\n");
}