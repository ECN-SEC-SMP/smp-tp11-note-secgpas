//
// Created by David PROSPÉRIN on 22/03/2026.
//

#include "Pioche.h"
#include <gtest/gtest.h>
#include <algorithm>

// ============== Constructor Tests ==============

TEST(PiocheTest, ShouldCreatePiocheCarteW) {
    Pioche pw(Pioche_type_e::CarteW);

    EXPECT_EQ(Pioche_type_e::CarteW, pw.getPiocheType());
    EXPECT_FALSE(pw.estPiocheVide());
}

TEST(PiocheTest, ShouldCreatePiocheTicket) {
    Pioche pt(Pioche_type_e::Ticket);

    EXPECT_EQ(Pioche_type_e::Ticket, pt.getPiocheType());
    EXPECT_FALSE(pt.estPiocheVide());
}

TEST(PiocheTest, ShouldPiocheCarteWNotBeEmpty) {
    Pioche pw(Pioche_type_e::CarteW);

    EXPECT_FALSE(pw.estPiocheVide());
}

TEST(PiocheTest, ShouldPiocheTicketNotBeEmpty) {
    Pioche pt(Pioche_type_e::Ticket);

    EXPECT_FALSE(pt.estPiocheVide());
}

// ============== Deck Size Tests ==============

TEST(PiocheTest, CarteWPiocheShouldHave62Cards) {
    Pioche pw(Pioche_type_e::CarteW);

    // 10 de chaque couleur (6 couleurs) + 12 locomotives = 72 cartes
    EXPECT_EQ(72, pw.getDeck().size());
}

TEST(PiocheTest, TicketPiocheShouldHave32Cards) {
    Pioche pt(Pioche_type_e::Ticket);

    EXPECT_EQ(32, pt.getDeck().size());
}

// ============== Defausse Tests ==============

TEST(PiocheTest, DefausseShouldBeInitiallyEmpty) {
    Pioche pw(Pioche_type_e::CarteW);

    EXPECT_TRUE(pw.getDefausse().empty());
    EXPECT_EQ(0, pw.getDefausse().size());
}

TEST(PiocheTest, PushDefausseShouldAddCard) {
    Pioche pw(Pioche_type_e::CarteW);
    CTrain* card = new CTrain(Couleur_e::Rouge);

    pw.pushDefausse(card);

    EXPECT_EQ(1, pw.getDefausse().size());
    EXPECT_EQ(card, pw.getDefausse()[0]);
}

TEST(PiocheTest, PushDefausseShouldAddMultipleCards) {
    Pioche pw(Pioche_type_e::CarteW);
    CTrain* card1 = new CTrain(Couleur_e::Rouge);
    CTrain* card2 = new CTrain(Couleur_e::Bleu);
    CTrain* card3 = new CTrain(Couleur_e::Vert);

    pw.pushDefausse(card1);
    pw.pushDefausse(card2);
    pw.pushDefausse(card3);

    EXPECT_EQ(3, pw.getDefausse().size());
    EXPECT_EQ(card1, pw.getDefausse()[0]);
    EXPECT_EQ(card2, pw.getDefausse()[1]);
    EXPECT_EQ(card3, pw.getDefausse()[2]);
}

// ============== Pop/Remove Card Tests ==============

TEST(PiocheTest, PopLastCarteShouldRemoveLastCard) {
    Pioche pw(Pioche_type_e::CarteW);
    int initialSize = pw.getDeck().size();

    pw.popLastCarte();

    EXPECT_EQ(initialSize - 1, pw.getDeck().size());
}

TEST(PiocheTest, PopLastCarteShouldNotFailOnEmptyDeck) {
    Pioche pw(Pioche_type_e::CarteW);

    // Empty the deck
    while (!pw.estPiocheVide()) {
        pw.popLastCarte();
    }

    // Should not crash or throw
    pw.popLastCarte();
    EXPECT_TRUE(pw.estPiocheVide());
}

TEST(PiocheTest, PopLastCarteMultipleTimes) {
    Pioche pw(Pioche_type_e::CarteW);
    int initialSize = pw.getDeck().size();

    for (int i = 0; i < 5; i++) {
        pw.popLastCarte();
    }

    EXPECT_EQ(initialSize - 5, pw.getDeck().size());
}

// ============== Shuffle Tests ==============

TEST(PiocheTest, MelangerShouldNotChangeSize) {
    Pioche pw(Pioche_type_e::CarteW);
    int initialSize = pw.getDeck().size();

    pw.melanger();

    EXPECT_EQ(initialSize, pw.getDeck().size());
}

TEST(PiocheTest, MelangerShouldPreserveAllCards) {
    Pioche pw(Pioche_type_e::CarteW);
    vector<Carte*> original = pw.getDeck();

    pw.melanger();

    vector<Carte*> shuffled = pw.getDeck();

    // All cards should still be present
    for (auto card : original) {
        auto it = std::find(shuffled.begin(), shuffled.end(), card);
        EXPECT_NE(shuffled.end(), it);
    }
}

TEST(PiocheTest, TicketPiocheMelangerShouldNotChangeSize) {
    Pioche pt(Pioche_type_e::Ticket);
    int initialSize = pt.getDeck().size();

    pt.melanger();

    EXPECT_EQ(initialSize, pt.getDeck().size());
}

// ============== Deck Type Tests ==============

TEST(PiocheTest, CarteWDeckShouldContainCTrains) {
    Pioche pw(Pioche_type_e::CarteW);

    for (Carte* carte : pw.getDeck()) {
        EXPECT_EQ(Carte_type_e::Train, carte->getType());
    }
}

TEST(PiocheTest, TicketDeckShouldContainTickets) {
    Pioche pt(Pioche_type_e::Ticket);

    for (Carte* carte : pt.getDeck()) {
        EXPECT_EQ(Carte_type_e::Ticket, carte->getType());
    }
}

// ============== Empty Check Tests ==============

TEST(PiocheTest, EstPiocheVideShouldReturnTrueWhenEmpty) {
    Pioche pw(Pioche_type_e::CarteW);

    while (!pw.estPiocheVide()) {
        pw.popLastCarte();
    }

    EXPECT_TRUE(pw.estPiocheVide());
}

TEST(PiocheTest, EstPiocheVideShouldReturnFalseWhenNotEmpty) {
    Pioche pw(Pioche_type_e::CarteW);

    EXPECT_FALSE(pw.estPiocheVide());
}

TEST(PiocheTest, EstPiocheVideShouldReturnFalseWithOneCard) {
    Pioche pw(Pioche_type_e::CarteW);

    while (pw.getDeck().size() > 1) {
        pw.popLastCarte();
    }

    EXPECT_FALSE(pw.estPiocheVide());
}

// ============== Edge Cases ==============

TEST(PiocheTest, GetPiocheTypeShouldReturnCorrectType) {
    Pioche pw(Pioche_type_e::CarteW);
    Pioche pt(Pioche_type_e::Ticket);

    EXPECT_EQ(Pioche_type_e::CarteW, pw.getPiocheType());
    EXPECT_EQ(Pioche_type_e::Ticket, pt.getPiocheType());
}

TEST(PiocheTest, DeckAndDefausseShouldBeIndependent) {
    Pioche pw(Pioche_type_e::CarteW);
    int deckSize = pw.getDeck().size();

    CTrain* card = new CTrain(Couleur_e::Rouge);
    pw.pushDefausse(card);

    EXPECT_EQ(deckSize, pw.getDeck().size());
    EXPECT_EQ(1, pw.getDefausse().size());
}

TEST(PiocheTest, PopAndDefausseWorkTogether) {
    Pioche pw(Pioche_type_e::CarteW);
    int initialDeckSize = pw.getDeck().size();

    CTrain* card = new CTrain(Couleur_e::Jaune);
    pw.pushDefausse(card);
    pw.popLastCarte();

    EXPECT_EQ(initialDeckSize - 1, pw.getDeck().size());
    EXPECT_EQ(1, pw.getDefausse().size());
}
