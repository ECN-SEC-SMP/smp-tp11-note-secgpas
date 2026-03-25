//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Carte.h"
#include "types.h"
#include <gtest/gtest.h>

TEST(PiocheTest, ShouldCarteTypeBeCorrect) {
    CTrain ct;
    Ticket t;

    EXPECT_EQ(Carte_type_e::Train, ct.getType());
    EXPECT_EQ(Carte_type_e::Ticket, t.getType());
}