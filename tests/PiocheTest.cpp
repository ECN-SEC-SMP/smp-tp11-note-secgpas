//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Pioche.h"
#include <gtest/gtest.h>

TEST(PiocheTest, ShouldPiocheCarteWBeNotEmpty) {
    Pioche pw(Pioche_type_e::CarteW);

    EXPECT_EQ(false, pw.estPiocheVide());

}

TEST(PiocheTest, ShouldPiocheTicketBeEmpty) {
    Pioche pt(Pioche_type_e::Ticket);

    EXPECT_EQ(true, pt.estPiocheVide());
}