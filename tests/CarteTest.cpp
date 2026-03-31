//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Plateau.h"
#include "Carte.h"
#include "types.h"
#include <gtest/gtest.h>
#include "config.h"

// ============== CTrain Tests ==============

TEST(CarteTest, ShouldCarteTypeBeCorrect) {
    CTrain ct(Couleur_e::Rouge);
    EXPECT_EQ(Carte_type_e::Train, ct.getType());
}

TEST(CarteTest, CTrainShouldHaveCorrectColor) {
    CTrain ctRed(Couleur_e::Rouge);
    CTrain ctBlue(Couleur_e::Bleu);
    CTrain ctGreen(Couleur_e::Vert);
    CTrain ctYellow(Couleur_e::Jaune);

    EXPECT_EQ(Couleur_e::Rouge, ctRed.getCouleur());
    EXPECT_EQ(Couleur_e::Bleu, ctBlue.getCouleur());
    EXPECT_EQ(Couleur_e::Vert, ctGreen.getCouleur());
    EXPECT_EQ(Couleur_e::Jaune, ctYellow.getCouleur());
}

TEST(CarteTest, CTrainShouldNotBeRealized) {
    CTrain ct(Couleur_e::Rouge);
    EXPECT_FALSE(ct.estRealise());
}

// ============== Ticket Tests ==============

TEST(CarteTest, ShouldCreateTicketsFromCSV) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    EXPECT_EQ(32, tickets.size());
}

TEST(CarteTest, TicketConstructorWithCities) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    EXPECT_EQ(1, t.getId());
    EXPECT_NE(nullptr, t.getVilleA());
    EXPECT_NE(nullptr, t.getVilleB());
    EXPECT_EQ("Seattle", t.getVilleA()->getNomVille());
    EXPECT_EQ("Los Angeles", t.getVilleB()->getNomVille());
}

TEST(CarteTest, TicketConstructorWithPointers) {
    Plateau p(MAP_FILE_PATH);
    Ville* villeA = p.getVille("Seattle");
    Ville* villeB = p.getVille("Los Angeles");

    Ticket t(&p, villeA, villeB, 42);

    EXPECT_EQ(42, t.getId());
    EXPECT_EQ(villeA, t.getVilleA());
    EXPECT_EQ(villeB, t.getVilleB());
}

TEST(CarteTest, TicketGetVilleA) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    Ville* villeA = t.getVilleA();
    EXPECT_NE(nullptr, villeA);
    EXPECT_EQ("Seattle", villeA->getNomVille());
}

TEST(CarteTest, TicketGetVilleB) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    Ville* villeB = t.getVilleB();
    EXPECT_NE(nullptr, villeB);
    EXPECT_EQ("Los Angeles", villeB->getNomVille());
}

TEST(CarteTest, TicketGetId) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 99);

    EXPECT_EQ(99, t.getId());
}

TEST(CarteTest, TicketSetVilleA) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);
    Ville* newVille = p.getVille("Helena");

    t.setVilleA(newVille);

    EXPECT_EQ(newVille, t.getVilleA());
    EXPECT_EQ("Helena", t.getVilleA()->getNomVille());
}

TEST(CarteTest, TicketSetVilleB) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);
    Ville* newVille = p.getVille("New York");

    t.setVilleB(newVille);

    EXPECT_EQ(newVille, t.getVilleB());
    EXPECT_EQ("New York", t.getVilleB()->getNomVille());
}

TEST(CarteTest, TicketSetId) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    t.setId(100);

    EXPECT_EQ(100, t.getId());
}

TEST(CarteTest, TicketGetType) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    EXPECT_EQ(Carte_type_e::Ticket, t.getType());
}

TEST(CarteTest, TicketShouldNotBeRealized) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    EXPECT_FALSE(t.estRealise());
}

TEST(CarteTest, AllLoadedTicketsHaveCorrectIds) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    for (int i = 0; i < tickets.size(); i++) {
        EXPECT_EQ(i + 1, tickets[i].getId());
    }
}

TEST(CarteTest, AllLoadedTicketsHaveValidCities) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    for (const auto& ticket : tickets) {
        EXPECT_NE(nullptr, ticket.getVilleA());
        EXPECT_NE(nullptr, ticket.getVilleB());
        EXPECT_NE("", ticket.getVilleA()->getNomVille());
        EXPECT_NE("", ticket.getVilleB()->getNomVille());
    }
}

TEST(CarteTest, TicketFirstLoadedTicket) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    EXPECT_EQ(1, tickets[0].getId());
    EXPECT_EQ("Seattle", tickets[0].getVilleA()->getNomVille());
    EXPECT_EQ("Los Angeles", tickets[0].getVilleB()->getNomVille());
}

TEST(CarteTest, TicketLastLoadedTicket) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    EXPECT_EQ(32, tickets[31].getId());
    EXPECT_EQ("Seattle", tickets[31].getVilleA()->getNomVille());
    EXPECT_EQ("New York", tickets[31].getVilleB()->getNomVille());
}

TEST(CarteTest, TicketSpecificLoadedTicket) {
    Plateau p(MAP_FILE_PATH);
    vector<Ticket> tickets = Ticket::loadFromCSVFile(&p, TICKET_FILE_PATH);

    // Check ticket 15: Denver - Dallas
    EXPECT_EQ(15, tickets[14].getId());
    EXPECT_EQ("Denver", tickets[14].getVilleA()->getNomVille());
    EXPECT_EQ("Dallas", tickets[14].getVilleB()->getNomVille());
}

TEST(CarteTest, TicketMultipleSettersChaining) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Los Angeles", 1);

    t.setId(50);
    Ville* villeNewA = p.getVille("Chicago");
    Ville* villeNewB = p.getVille("Washington");
    t.setVilleA(villeNewA);
    t.setVilleB(villeNewB);

    EXPECT_EQ(50, t.getId());
    EXPECT_EQ("Chicago", t.getVilleA()->getNomVille());
    EXPECT_EQ("Washington", t.getVilleB()->getNomVille());
}

