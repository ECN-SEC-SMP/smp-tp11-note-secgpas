//
// Created by David PROSPÉRIN on 25/03/2026.
//

#include <gtest/gtest.h>
#include "Plateau.h"
#include "config.h"
#include "fonctionAnnexe.h"

TEST(PlateauTest, PlateauInitialisation) {
    Plateau p(MAP_FILE_PATH);

    ASSERT_EQ(p.getVilles().size(), 19);
    ASSERT_EQ(p.getVille(0).getNomVille(), "Seattle");
    ASSERT_EQ(p.getVille(1).getNomVille(), "Calgary");
    ASSERT_EQ(p.getVille(2).getNomVille(), "Helena");
    ASSERT_EQ(p.getVille(3).getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVille(4).getNomVille(), "Los Angeles");
    ASSERT_EQ(p.getVille(5).getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVille(6).getNomVille(), "Albuquerque");
    ASSERT_EQ(p.getVille(7).getNomVille(), "Denver");
    ASSERT_EQ(p.getVille(8).getNomVille(), "Winnipeg");
    ASSERT_EQ(p.getVille(9).getNomVille(), "Duluth");
    ASSERT_EQ(p.getVille(10).getNomVille(), "Kansas City");
    ASSERT_EQ(p.getVille(11).getNomVille(), "Dallas");
    ASSERT_EQ(p.getVille(12).getNomVille(), "New Orleans");
    ASSERT_EQ(p.getVille(13).getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVille(14).getNomVille(), "Miami");
    ASSERT_EQ(p.getVille(15).getNomVille(), "Chicago");
    ASSERT_EQ(p.getVille(16).getNomVille(), "Washington");
    ASSERT_EQ(p.getVille(17).getNomVille(), "Montreal");
    ASSERT_EQ(p.getVille(18).getNomVille(), "New York");
}

TEST(PlateauTest, VoiesFerreesInitialisation) {
    Plateau p(MAP_FILE_PATH);

    ASSERT_EQ(p.getVoieFerrees().size(), 39);
    ASSERT_EQ(p.getVoieFerrees()[0].getVille1()->getNomVille(), "Seattle");
    ASSERT_EQ(p.getVoieFerrees()[0].getVille2()->getNomVille(), "Calgary");
    ASSERT_EQ(p.getVoieFerrees()[0].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[0].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[1].getVille1()->getNomVille(), "Seattle");
    ASSERT_EQ(p.getVoieFerrees()[1].getVille2()->getNomVille(), "Calgary");
    ASSERT_EQ(p.getVoieFerrees()[1].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[1].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[2].getVille1()->getNomVille(), "Seattle");
    ASSERT_EQ(p.getVoieFerrees()[2].getVille2()->getNomVille(), "Helena");
    ASSERT_EQ(p.getVoieFerrees()[2].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[2].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[3].getVille1()->getNomVille(), "Seattle");
    ASSERT_EQ(p.getVoieFerrees()[3].getVille2()->getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVoieFerrees()[3].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[3].getPoids(), 5);

    ASSERT_EQ(p.getVoieFerrees()[4].getVille1()->getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVoieFerrees()[4].getVille2()->getNomVille(), "Los Angeles");
    ASSERT_EQ(p.getVoieFerrees()[4].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[4].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[5].getVille1()->getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVoieFerrees()[5].getVille2()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[5].getCouleur(), Couleur_e::Orange);
    ASSERT_EQ(p.getVoieFerrees()[5].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[6].getVille1()->getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVoieFerrees()[6].getVille2()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[6].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[6].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[7].getVille1()->getNomVille(), "Los Angeles");
    ASSERT_EQ(p.getVoieFerrees()[7].getVille2()->getNomVille(), "Albuquerque");
    ASSERT_EQ(p.getVoieFerrees()[7].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[7].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[8].getVille1()->getNomVille(), "Los Angeles");
    ASSERT_EQ(p.getVoieFerrees()[8].getVille2()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[8].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[8].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[9].getVille1()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[9].getVille2()->getNomVille(), "Helena");
    ASSERT_EQ(p.getVoieFerrees()[9].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[9].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[10].getVille1()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[10].getVille2()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[10].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[10].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[11].getVille1()->getNomVille(), "Salt Lake City");
    ASSERT_EQ(p.getVoieFerrees()[11].getVille2()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[11].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[11].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[12].getVille1()->getNomVille(), "Calgary");
    ASSERT_EQ(p.getVoieFerrees()[12].getVille2()->getNomVille(), "Winnipeg");
    ASSERT_EQ(p.getVoieFerrees()[12].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[12].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[13].getVille1()->getNomVille(), "Calgary");
    ASSERT_EQ(p.getVoieFerrees()[13].getVille2()->getNomVille(), "Winnipeg");
    ASSERT_EQ(p.getVoieFerrees()[13].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[13].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[14].getVille1()->getNomVille(), "Winnipeg");
    ASSERT_EQ(p.getVoieFerrees()[14].getVille2()->getNomVille(), "Duluth");
    ASSERT_EQ(p.getVoieFerrees()[14].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[14].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[15].getVille1()->getNomVille(), "Winnipeg");
    ASSERT_EQ(p.getVoieFerrees()[15].getVille2()->getNomVille(), "Duluth");
    ASSERT_EQ(p.getVoieFerrees()[15].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[15].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[16].getVille1()->getNomVille(), "Helena");
    ASSERT_EQ(p.getVoieFerrees()[16].getVille2()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[16].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[16].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[17].getVille1()->getNomVille(), "Helena");
    ASSERT_EQ(p.getVoieFerrees()[17].getVille2()->getNomVille(), "Kansas City");
    ASSERT_EQ(p.getVoieFerrees()[17].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[17].getPoids(), 5);

    ASSERT_EQ(p.getVoieFerrees()[18].getVille1()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[18].getVille2()->getNomVille(), "Kansas City");
    ASSERT_EQ(p.getVoieFerrees()[18].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[18].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[19].getVille1()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[19].getVille2()->getNomVille(), "Dallas");
    ASSERT_EQ(p.getVoieFerrees()[19].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[19].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[20].getVille1()->getNomVille(), "Denver");
    ASSERT_EQ(p.getVoieFerrees()[20].getVille2()->getNomVille(), "Albuquerque");
    ASSERT_EQ(p.getVoieFerrees()[20].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[20].getPoids(), 2);

    ASSERT_EQ(p.getVoieFerrees()[21].getVille1()->getNomVille(), "Albuquerque");
    ASSERT_EQ(p.getVoieFerrees()[21].getVille2()->getNomVille(), "Dallas");
    ASSERT_EQ(p.getVoieFerrees()[21].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[21].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[22].getVille1()->getNomVille(), "Dallas");
    ASSERT_EQ(p.getVoieFerrees()[22].getVille2()->getNomVille(), "New Orleans");
    ASSERT_EQ(p.getVoieFerrees()[22].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[22].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[23].getVille1()->getNomVille(), "Dallas");
    ASSERT_EQ(p.getVoieFerrees()[23].getVille2()->getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVoieFerrees()[23].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[23].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[24].getVille1()->getNomVille(), "New Orleans");
    ASSERT_EQ(p.getVoieFerrees()[24].getVille2()->getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVoieFerrees()[24].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[24].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[25].getVille1()->getNomVille(), "New Orleans");
    ASSERT_EQ(p.getVoieFerrees()[25].getVille2()->getNomVille(), "Miami");
    ASSERT_EQ(p.getVoieFerrees()[25].getCouleur(), Couleur_e::Blanc);
    ASSERT_EQ(p.getVoieFerrees()[25].getPoids(), 6);

    ASSERT_EQ(p.getVoieFerrees()[26].getVille1()->getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVoieFerrees()[26].getVille2()->getNomVille(), "Miami");
    ASSERT_EQ(p.getVoieFerrees()[26].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[26].getPoids(), 5);

    ASSERT_EQ(p.getVoieFerrees()[27].getVille1()->getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVoieFerrees()[27].getVille2()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[27].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[27].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[28].getVille1()->getNomVille(), "Kansas City");
    ASSERT_EQ(p.getVoieFerrees()[28].getVille2()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[28].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[28].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[29].getVille1()->getNomVille(), "Kansas City");
    ASSERT_EQ(p.getVoieFerrees()[29].getVille2()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[29].getCouleur(), Couleur_e::Blanc);
    ASSERT_EQ(p.getVoieFerrees()[29].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[30].getVille1()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[30].getVille2()->getNomVille(), "Washington");
    ASSERT_EQ(p.getVoieFerrees()[30].getCouleur(), Couleur_e::Noir);
    ASSERT_EQ(p.getVoieFerrees()[30].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[31].getVille1()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[31].getVille2()->getNomVille(), "Duluth");
    ASSERT_EQ(p.getVoieFerrees()[31].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[31].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[32].getVille1()->getNomVille(), "Duluth");
    ASSERT_EQ(p.getVoieFerrees()[32].getVille2()->getNomVille(), "Montreal");
    ASSERT_EQ(p.getVoieFerrees()[32].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[32].getPoids(), 4);

    ASSERT_EQ(p.getVoieFerrees()[33].getVille1()->getNomVille(), "Duluth");
    ASSERT_EQ(p.getVoieFerrees()[33].getVille2()->getNomVille(), "Chicago");
    ASSERT_EQ(p.getVoieFerrees()[33].getCouleur(), Couleur_e::Blanc);
    ASSERT_EQ(p.getVoieFerrees()[33].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[34].getVille1()->getNomVille(), "Montreal");
    ASSERT_EQ(p.getVoieFerrees()[34].getVille2()->getNomVille(), "New York");
    ASSERT_EQ(p.getVoieFerrees()[34].getCouleur(), Couleur_e::Bleu);
    ASSERT_EQ(p.getVoieFerrees()[34].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[35].getVille1()->getNomVille(), "Montreal");
    ASSERT_EQ(p.getVoieFerrees()[35].getVille2()->getNomVille(), "New York");
    ASSERT_EQ(p.getVoieFerrees()[35].getCouleur(), Couleur_e::Vert);
    ASSERT_EQ(p.getVoieFerrees()[35].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[36].getVille1()->getNomVille(), "Washington");
    ASSERT_EQ(p.getVoieFerrees()[36].getVille2()->getNomVille(), "New York");
    ASSERT_EQ(p.getVoieFerrees()[36].getCouleur(), Couleur_e::Rouge);
    ASSERT_EQ(p.getVoieFerrees()[36].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[37].getVille1()->getNomVille(), "Washington");
    ASSERT_EQ(p.getVoieFerrees()[37].getVille2()->getNomVille(), "New York");
    ASSERT_EQ(p.getVoieFerrees()[37].getCouleur(), Couleur_e::Blanc);
    ASSERT_EQ(p.getVoieFerrees()[37].getPoids(), 3);

    ASSERT_EQ(p.getVoieFerrees()[38].getVille1()->getNomVille(), "Washington");
    ASSERT_EQ(p.getVoieFerrees()[38].getVille2()->getNomVille(), "Atlanta");
    ASSERT_EQ(p.getVoieFerrees()[38].getCouleur(), Couleur_e::Jaune);
    ASSERT_EQ(p.getVoieFerrees()[38].getPoids(), 3);
}

TEST(PlateauTest, AffichePlateauSansProprietaire)
{
    Plateau p(MAP_FILE_PATH);

    testing::internal::CaptureStdout();
    p.affichePlateau();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "----------=== Plateau de jeu ===----------\n"
"               Seattle       Calgary       Helena        San Francisco Los Angeles   Salt Lake CityAlbuquerque   Denver        Winnipeg      Duluth        Kansas City   Dallas        New Orleans   Atlanta       Miami         Chicago       Washington    Montreal      New York      \n"
"              --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
"Seattle        | X           | 4, 4        | 4           | 5           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Calgary        | 4, 4        | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Helena         | 4           | X           | X           | X           | X           | 3           | X           | 3           | X           | X           | 5           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"San Francisco  | 5           | X           | X           | X           | 3           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Los Angeles    | X           | X           | X           | 3           | X           | 3           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Salt Lake City | X           | X           | 3           | 3, 3        | 3           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Albuquerque    | X           | X           | X           | X           | 4           | X           | X           | 2           | X           | X           | X           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Denver         | X           | X           | 3           | X           | X           | 3, 3        | 2           | X           | X           | X           | 4           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Winnipeg       | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Duluth         | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | 3, 3        | X           | 4           | X          \n"
"Kansas City    | X           | X           | 5           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X          \n"
"Dallas         | X           | X           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | X          \n"
"New Orleans    | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | 6           | X           | X           | X           | X          \n"
"Atlanta        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | 4           | X           | 5           | 4           | 3           | X           | X          \n"
"Miami          | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 6           | 5           | X           | X           | X           | X           | X          \n"
"Chicago        | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 4, 4        | X           | X           | 4           | X           | X           | 4           | X           | X          \n"
"Washington     | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | X           | X           | 3, 3       \n"
"Montreal       | X           | X           | X           | X           | X           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3       \n"
"New York       | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 3, 3        | X          \n";

    EXPECT_EQ(expected_output, output);
}


TEST(PlateauTest, AffichagePlateau2Joueurs) {
    Plateau p(MAP_FILE_PATH);
    Joueur joueur_rouge(Couleur_e::Rouge);
    Joueur joueur_bleu(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&joueur_rouge);
    p.getVoieFerrees()[1].setProprio(&joueur_bleu);

    testing::internal::CaptureStdout();
    p.affichePlateau();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "----------=== Plateau de jeu ===----------\n"
"               Seattle       Calgary       Helena        San Francisco Los Angeles   Salt Lake CityAlbuquerque   Denver        Winnipeg      Duluth        Kansas City   Dallas        New Orleans   Atlanta       Miami         Chicago       Washington    Montreal      New York      \n"
"              --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
"Seattle        | X           | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | 4           | 5           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Calgary        | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Helena         | 4           | X           | X           | X           | X           | 3           | X           | 3           | X           | X           | 5           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"San Francisco  | 5           | X           | X           | X           | 3           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Los Angeles    | X           | X           | X           | 3           | X           | 3           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Salt Lake City | X           | X           | 3           | 3, 3        | 3           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Albuquerque    | X           | X           | X           | X           | 4           | X           | X           | 2           | X           | X           | X           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Denver         | X           | X           | 3           | X           | X           | 3, 3        | 2           | X           | X           | X           | 4           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Winnipeg       | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Duluth         | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | 3, 3        | X           | 4           | X          \n"
"Kansas City    | X           | X           | 5           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X          \n"
"Dallas         | X           | X           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | X          \n"
"New Orleans    | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | 6           | X           | X           | X           | X          \n"
"Atlanta        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | 4           | X           | 5           | 4           | 3           | X           | X          \n"
"Miami          | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 6           | 5           | X           | X           | X           | X           | X          \n"
"Chicago        | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 4, 4        | X           | X           | 4           | X           | X           | 4           | X           | X          \n"
"Washington     | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | X           | X           | 3, 3       \n"
"Montreal       | X           | X           | X           | X           | X           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3       \n"
"New York       | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 3, 3        | X          \n";

    EXPECT_EQ(expected_output, output);
}

TEST(PlateauTest, AffichagePlateau3Joueurs) {
    Plateau p(MAP_FILE_PATH);
    Joueur joueur_rouge(Couleur_e::Rouge);
    Joueur joueur_bleu(Couleur_e::Bleu);
    Joueur joueur_vert(Couleur_e::Vert);

    p.getVoieFerrees()[0].setProprio(&joueur_rouge);
    p.getVoieFerrees()[1].setProprio(&joueur_bleu);
    p.getVoieFerrees()[2].setProprio(&joueur_vert);

    testing::internal::CaptureStdout();
    p.affichePlateau();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "----------=== Plateau de jeu ===----------\n"
"               Seattle       Calgary       Helena        San Francisco Los Angeles   Salt Lake CityAlbuquerque   Denver        Winnipeg      Duluth        Kansas City   Dallas        New Orleans   Atlanta       Miami         Chicago       Washington    Montreal      New York      \n"
"              --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
"Seattle        | X           | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | \x1B[1;32m4\x1B[0m           | 5           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Calgary        | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Helena         | \x1B[1;32m4\x1B[0m           | X           | X           | X           | X           | 3           | X           | 3           | X           | X           | 5           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"San Francisco  | 5           | X           | X           | X           | 3           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Los Angeles    | X           | X           | X           | 3           | X           | 3           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Salt Lake City | X           | X           | 3           | 3, 3        | 3           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Albuquerque    | X           | X           | X           | X           | 4           | X           | X           | 2           | X           | X           | X           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Denver         | X           | X           | 3           | X           | X           | 3, 3        | 2           | X           | X           | X           | 4           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Winnipeg       | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Duluth         | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | 3, 3        | X           | 4           | X          \n"
"Kansas City    | X           | X           | 5           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X          \n"
"Dallas         | X           | X           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | X          \n"
"New Orleans    | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | 6           | X           | X           | X           | X          \n"
"Atlanta        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | 4           | X           | 5           | 4           | 3           | X           | X          \n"
"Miami          | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 6           | 5           | X           | X           | X           | X           | X          \n"
"Chicago        | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 4, 4        | X           | X           | 4           | X           | X           | 4           | X           | X          \n"
"Washington     | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | X           | X           | 3, 3       \n"
"Montreal       | X           | X           | X           | X           | X           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3       \n"
"New York       | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 3, 3        | X          \n";

    EXPECT_EQ(expected_output, output);
}

TEST(PlateauTest, AffichagePlateau4Joueurs) {
    Plateau p(MAP_FILE_PATH);
    Joueur joueur_rouge(Couleur_e::Rouge);
    Joueur joueur_bleu(Couleur_e::Bleu);
    Joueur joueur_vert(Couleur_e::Vert);
    Joueur joueur_jaune(Couleur_e::Jaune);

    p.getVoieFerrees()[0].setProprio(&joueur_rouge);
    p.getVoieFerrees()[1].setProprio(&joueur_bleu);
    p.getVoieFerrees()[2].setProprio(&joueur_vert);
    p.getVoieFerrees()[3].setProprio(&joueur_jaune);

    testing::internal::CaptureStdout();
    p.affichePlateau();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "----------=== Plateau de jeu ===----------\n"
"               Seattle       Calgary       Helena        San Francisco Los Angeles   Salt Lake CityAlbuquerque   Denver        Winnipeg      Duluth        Kansas City   Dallas        New Orleans   Atlanta       Miami         Chicago       Washington    Montreal      New York      \n"
"              --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
"Seattle        | X           | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | \x1B[1;32m4\x1B[0m           | \x1B[1;33m5\x1B[0m           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Calgary        | \x1B[1;31m4\x1B[0m, \x1B[1;34m4\x1B[0m        | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Helena         | \x1B[1;32m4\x1B[0m           | X           | X           | X           | X           | 3           | X           | 3           | X           | X           | 5           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"San Francisco  | \x1B[1;33m5\x1B[0m           | X           | X           | X           | 3           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Los Angeles    | X           | X           | X           | 3           | X           | 3           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Salt Lake City | X           | X           | 3           | 3, 3        | 3           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Albuquerque    | X           | X           | X           | X           | 4           | X           | X           | 2           | X           | X           | X           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Denver         | X           | X           | 3           | X           | X           | 3, 3        | 2           | X           | X           | X           | 4           | 3           | X           | X           | X           | X           | X           | X           | X          \n"
"Winnipeg       | X           | 4, 4        | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | X           | X           | X          \n"
"Duluth         | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | X           | X           | X           | X           | X           | X           | 3, 3        | X           | 4           | X          \n"
"Kansas City    | X           | X           | 5           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | 4, 4        | X           | X           | X          \n"
"Dallas         | X           | X           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | 3           | 3           | X           | X           | X           | X           | X          \n"
"New Orleans    | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | 6           | X           | X           | X           | X          \n"
"Atlanta        | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | 4           | X           | 5           | 4           | 3           | X           | X          \n"
"Miami          | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 6           | 5           | X           | X           | X           | X           | X          \n"
"Chicago        | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 4, 4        | X           | X           | 4           | X           | X           | 4           | X           | X          \n"
"Washington     | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3           | X           | 4           | X           | X           | 3, 3       \n"
"Montreal       | X           | X           | X           | X           | X           | X           | X           | X           | X           | 4           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3       \n"
"New York       | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | X           | 3, 3        | 3, 3        | X          \n";

    EXPECT_EQ(expected_output, output);
}