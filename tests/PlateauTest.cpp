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
    // TODO: Compléter toutes les villes
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


TEST(PlateauTest, AffichagePlateau) {
    Plateau p(MAP_FILE_PATH);
    Joueur joueur_rouge(Couleur_e::Rouge);
    Joueur joueur_bleu(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&joueur_rouge);
    p.getVoieFerrees()[1].setProprio(&joueur_bleu);

    p.affichePlateau();
}