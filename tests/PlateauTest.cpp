//
// Created by David PROSPÉRIN on 25/03/2026.
//

#include <gtest/gtest.h>
#include "Plateau.h"

TEST(PlateauTest, PlateauInitialisation) {
    Plateau p("../map.csv");

    ASSERT_EQ(p.getVilles().size(), 19);
    ASSERT_EQ(p.getVille(0).getNomVille(), "Seattle");
    ASSERT_EQ(p.getVille(1).getNomVille(), "Calgary");
    ASSERT_EQ(p.getVille(2).getNomVille(), "Helena");
    ASSERT_EQ(p.getVille(3).getNomVille(), "San Francisco");
    ASSERT_EQ(p.getVille(4).getNomVille(), "Los Angeles");
    // TODO: Compléter toutes les villes
}