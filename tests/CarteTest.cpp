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

TEST(CarteTest, TicketShouldBeRealized) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Calgary", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j);
    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealized2) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Calgary", "Seattle", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j);
    EXPECT_TRUE(t.estRealise(&j));
}


TEST(CarteTest, TicketShouldBeNotRealized) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Salt Lake City", "Helena", 1);
    Joueur j(Couleur_e::Bleu);

    EXPECT_FALSE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWithMultiplePaths) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "San Francisco", "Salt Lake City", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeNotRealizedWithMultiplePaths) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "San Francisco", "Salt Lake City", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[7].setProprio(&j); // Los Angeles - Albuquerque

    EXPECT_FALSE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWith2Paths) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Salt Lake City", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[3].setProprio(&j); // Seattle - San Francisco
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWith2Paths2) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Salt Lake City", "Seattle", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[3].setProprio(&j); // Seattle - San Francisco
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWith3Paths) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Salt Lake City", "Calgary", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[3].setProprio(&j); // Seattle - San Francisco
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWith3Paths2) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Calgary", "Salt Lake City", 1);
    Joueur j(Couleur_e::Bleu);

    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[3].setProprio(&j); // Seattle - San Francisco
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeNotRealizedWithNullPlayer) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Calgary", 1);

    EXPECT_DEATH(t.estRealise(nullptr), "Erreur : le joueur ne peut pas être nul.");
}

TEST(CarteTest, TicketShouldBeRealizedWithLongerPath) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Helena", 1);
    Joueur j(Couleur_e::Bleu);

    // Assuming indices: 0: Seattle-Calgary, 1: Calgary-Helena
    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary
    p.getVoieFerrees()[2].setProprio(&j); // Calgary - Helena

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeNotRealizedWithPartialPath) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Helena", 1);
    Joueur j(Couleur_e::Bleu);

    // Possède seulement Seattle - Calgary, pas Calgary - Helena
    p.getVoieFerrees()[0].setProprio(&j); // Seattle - Calgary

    EXPECT_FALSE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWithAlternativePaths) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Salt Lake City", 1);
    Joueur j(Couleur_e::Bleu);

    // Possède un chemin alternatif : Seattle - San Francisco - Salt Lake City
    p.getVoieFerrees()[3].setProprio(&j); // Seattle - San Francisco
    p.getVoieFerrees()[5].setProprio(&j); // San Francisco - Salt Lake City

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeNotRealizedIfNoPathExists) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "New York", 1); // Assuming no direct or indirect path without possessing all
    Joueur j(Couleur_e::Bleu);

    // Possède seulement quelques voies, pas un chemin complet
    p.getVoieFerrees()[0].setProprio(&j);

    EXPECT_FALSE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeRealizedWithDoubleRoutes) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Calgary", 1);
    Joueur j(Couleur_e::Bleu);

    // Possède seulement une des deux voies entre Seattle et Calgary
    p.getVoieFerrees()[0].setProprio(&j); // Assuming [0] is one route

    EXPECT_TRUE(t.estRealise(&j));
}

TEST(CarteTest, TicketShouldBeNotRealizedWithOtherPlayerOwnership) {
    Plateau p(MAP_FILE_PATH);
    Ticket t(&p, "Seattle", "Calgary", 1);
    Joueur j1(Couleur_e::Bleu);
    Joueur j2(Couleur_e::Rouge);

    // j2 possède la voie, pas j1
    p.getVoieFerrees()[0].setProprio(&j2);

    EXPECT_FALSE(t.estRealise(&j1));
}

TEST(CarteTest, TicketConstructorWithNullPlateau) {
    EXPECT_DEATH(Ticket(nullptr, "Seattle", "Los Angeles", 1), "Erreur : le plateau ne peut pas être nul.");
}

TEST(CarteTest, TicketEstRealiseWithInvalidVille) {
    Plateau p(MAP_FILE_PATH);
    EXPECT_DEATH(Ticket(&p, "InvalidCity", "Los Angeles", 1),
                 "Erreur : la ville InvalidCity n'existe pas sur le plateau.");
}
