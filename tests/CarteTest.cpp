//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Plateau.h"
#include "Carte.h"
#include "types.h"
#include <gtest/gtest.h>

TEST(CarteTest, ShouldCarteTypeBeCorrect) {
    CTrain ct(Couleur_e::Rouge);
    //Ticket t;

    EXPECT_EQ(Carte_type_e::Train, ct.getType());
    //EXPECT_EQ(Carte_type_e::Ticket, t.getType());
}

TEST(CarteTest, ShouldCreateTicketsFromCSV) {
    Plateau p("../map.csv");
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, "../ticket.csv");

    EXPECT_EQ(32, tickets.size());
}