#include "Carte.h"
#include "types.h"
#include "Joueur.h"
#include "Pioche.h"
#include "Plateau.h"
#include "config.h"
#include <gtest/gtest.h>

// ============ Test constructeur ====================
TEST(JoueurTest, testMainWConstructeurOK) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    EXPECT_EQ(20, j1.getMainWagon());  
    EXPECT_EQ(Couleur_e::Bleu, j1.getCouleur());
}

TEST(JoueurTest, testMainCConstructeurOK) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    map<Couleur_e, int> M_cartes = j1.getMainCarte();
    // Vérifie que toutes les couleurs sont initialisées à 0
    for (map<Couleur_e, int>::iterator it = M_cartes.begin(); it != M_cartes.end(); ++it){
        EXPECT_EQ(0, it->second);
    }
    EXPECT_EQ(8, M_cartes.size());
    EXPECT_EQ(0, M_cartes[Couleur_e::Rouge]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Bleu]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Jaune]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Locomotive]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Noir]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Vert]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Blanc]);
    EXPECT_EQ(0, M_cartes[Couleur_e::Orange]);

}
// ==============================================================
// ================ Test Pioche =================================
TEST(JoueurTest, testPiocheWagon) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pw(Pioche_type_e::CarteW);
    j1.piocher(3, pw);
    int compt = 0;
    map<Couleur_e, int> M_cartes = j1.getMainCarte();
    for (map<Couleur_e, int>::iterator it = M_cartes.begin(); it != M_cartes.end(); ++it){
        compt = compt + it->second;
    }
    EXPECT_EQ(3, compt);
}

TEST(JoueurTest, testDiminutionPiocheWagon) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pw(Pioche_type_e::CarteW);
    int tailleAvant = pw.getDeck().size();
    j1.piocher(3, pw);
    EXPECT_EQ(tailleAvant - 3, pw.getDeck().size());
}

TEST(JoueurTest, testPiocheTicket) {
    Joueur j1(Couleur_e::Bleu);
    Pioche pt(Pioche_type_e::Ticket);

    j1.piocher(2, pt);

    EXPECT_EQ(2, j1.getMainTicket().size());
}

TEST(JoueurTest, testPiocheEtDefausseVide) {
    Joueur j1(Couleur_e::Bleu);
    Pioche pw(Pioche_type_e::CarteW);

    // Vider complètement la pioche
    pw.getDeck().clear();
    pw.getDefausse().clear();

    j1.piocher(3, pw);

    int compt = 0;
    auto M_cartes = j1.getMainCarte();

    for (auto it = M_cartes.begin(); it != M_cartes.end(); ++it){
        compt += it->second;
    }

    // Rien ne doit être pioché
    EXPECT_EQ(0, compt);
}

TEST(JoueurTest, testPiocheVideAvecDefausse) {
    Joueur j1(Couleur_e::Bleu);
    Pioche pw(Pioche_type_e::CarteW);

    // Vider la pioche
    pw.getDeck().clear();

    // Ajouter 3 cartes dans la défausse
    pw.getDefausse().push_back(new CTrain(Couleur_e::Rouge));
    pw.getDefausse().push_back(new CTrain(Couleur_e::Bleu));
    pw.getDefausse().push_back(new CTrain(Couleur_e::Vert));

    j1.piocher(3, pw);

    int compt = 0;
    auto M_cartes = j1.getMainCarte();

    for (auto it = M_cartes.begin(); it != M_cartes.end(); ++it){
        compt += it->second;
    }

    // Les 3 cartes doivent être récupérées
    EXPECT_EQ(3, compt);

    // La défausse doit être vide après recyclage
    EXPECT_TRUE(pw.getDefausse().empty());
} 
// ================================================
// =============== Test GetMainTicket =============
TEST(JoueurTest, testGetMainTicket) {
    Joueur j1(Couleur_e::Bleu);
    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(2, pt);
    auto tickets = j1.getMainTicket();
    EXPECT_EQ(2, tickets.size());
    for (auto t : tickets) {
        EXPECT_NE(nullptr, t);
    }
}

// ===========================================
// ========= Test AfficheCarte ===============

// TEST(JoueurTest, testAfficheCarte) {
//     Joueur j1 = Joueur(Couleur_e::Bleu);
//     Pioche pw(Pioche_type_e::CarteW);
//     Pioche pt(Pioche_type_e::Ticket);
//     j1.piocher(3, pw);
//     j1.piocher(2, pt);
//     EXPECT_NO_THROW(j1.afficherMain());
// }

TEST(JoueurTest, testAfficheTicket) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(2, pt);
    EXPECT_EQ(2, j1.getMainTicket().size());
}
// ==============================================
// =============Test nbTicketreussis ============

TEST(JoueurTest, testNbTicketReussi) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(2, pt);
    EXPECT_EQ(2, j1.getMainTicket().size());
}

TEST(JoueurTest, testNbTicketReussisVide) {
    Joueur j(Couleur_e::Bleu);

    EXPECT_EQ(0, j.getNbTicketReussis());
}

// ====================================================
//============ Test nbCartesCompatibles ===============

TEST(JoueurTest, AucuneCarte) {
    Joueur j(Couleur_e::Bleu);
    
    EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Rouge), 0);
}

// Test : seulement des cartes de la couleur demandée
TEST(JoueurTest, SeulementCouleur) {
    Joueur j(Couleur_e::Bleu);
    j.ajoutMainCarte(Couleur_e::Rouge,3); 
    EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Rouge), 3);
}

TEST(JoueurTest, SeulementLocomotives) {
    Joueur j(Couleur_e::Bleu);
    j.ajoutMainCarte(Couleur_e::Locomotive,2); 

    EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Rouge), 2);
}

TEST(JoueurTest, CouleurPlusLocomotives) {
   Joueur j(Couleur_e::Bleu);
   j.ajoutMainCarte(Couleur_e::Bleu,4); 
   j.ajoutMainCarte(Couleur_e::Locomotive,3); 

   EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Bleu), 7);
}

// Test : autre couleur + locomotives (la couleur demandée absente)
TEST(JoueurTest, CouleurAbsenteMaisLocos) {
    Joueur j(Couleur_e::Bleu);
    j.ajoutMainCarte(Couleur_e::Vert,5); 
    j.ajoutMainCarte(Couleur_e::Locomotive,2);

    EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Rouge), 2);
}

// Test : plusieurs couleurs mais on ne prend que la bonne + locos
TEST(JoueurTest, IgnoreAutresCouleurs) {
    Joueur j(Couleur_e::Bleu);
    j.ajoutMainCarte(Couleur_e::Rouge,2); 
    j.ajoutMainCarte(Couleur_e::Bleu,5); 
    j.ajoutMainCarte(Couleur_e::Locomotive,1); 

    EXPECT_EQ(j.nbCartesCompatibles(Couleur_e::Rouge), 3);
}
// ====================================================

// ======== Test poserWagon ===========================

TEST(JoueurTest, PoseWagonReussie) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );
    j.ajoutMainCarte(Couleur_e::Bleu,3); 
    j.ajoutMainCarte(Couleur_e::Locomotive,2); 

    EXPECT_TRUE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));
}

// Pas assez de wagons
TEST(JoueurTest, PasAssezDeWagons) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );
    j.ajoutMainCarte(Couleur_e::Bleu,3); 
    j.setWagon(2);

    EXPECT_FALSE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));
}

// Pas assez de cartes
TEST(JoueurTest, PasAssezDeCartes) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );

    j.ajoutMainCarte(Couleur_e::Bleu,1); 
    j.ajoutMainCarte(Couleur_e::Locomotive,0); 
    j.setWagon(10);

    EXPECT_FALSE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));
}

// Mauvaise couleur
TEST(JoueurTest, MauvaiseCouleur) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );
    j.ajoutMainCarte(Couleur_e::Bleu,3); 
    j.setWagon(10);

    EXPECT_FALSE(j.poserWagon(v1, v2, Couleur_e::Rouge, plateau));
}

// Voie déjà prise
TEST(JoueurTest, VoieDejaPrise) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );

    j.ajoutMainCarte(Couleur_e::Bleu,5); 
    j.setWagon(10);

    // première pose
    EXPECT_TRUE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));

    // deuxième tentative
    EXPECT_FALSE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));
}

//  Aucune voie trouvée
TEST(JoueurTest, AucuneVoieTrouvee) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");
    Ville v3("Denver");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );

    j.ajoutMainCarte(Couleur_e::Bleu,5); 
    j.setWagon(10);

    EXPECT_FALSE(j.poserWagon(v1, v3, Couleur_e::Bleu, plateau));
}

// Utilisation locomotives
TEST(JoueurTest, UtilisationLocomotives) {
    Joueur j(Couleur_e::Rouge);

    Ville v1("Seattle");
    Ville v2("Calgary");

    Plateau plateau("map.csv");
    plateau.getVoieFerrees().clear();

    plateau.getVoieFerrees().push_back(
        VoieFerree(&v1, &v2, 3, Couleur_e::Bleu)
    );

    j.ajoutMainCarte(Couleur_e::Bleu,5); 
    j.ajoutMainCarte(Couleur_e::Locomotive,5); 
    j.setWagon(10);

    EXPECT_TRUE(j.poserWagon(v1, v2, Couleur_e::Bleu, plateau));
    EXPECT_EQ(j.getMainCarte()[Couleur_e::Bleu], 2);
    EXPECT_EQ(j.getMainCarte()[Couleur_e::Locomotive], 5);
}
 // =====================================================

 // =============== Test défausse =======================

TEST(JoueurTest, DefausserDeuxTickets) {
    Joueur j(Couleur_e::Rouge);
    Plateau plateau("map.csv");
    Pioche pioche(Pioche_type_e::Ticket);

    Ville v1("A"), v2("B"), v3("C"), v4("D"), v5("E"), v6("F");

    Ticket t1(&plateau, &v1, &v2, 1);
    Ticket t2(&plateau, &v3, &v4, 2);
    Ticket t3(&plateau, &v5, &v6, 3);

    j.ajoutTicket(&t1);
    j.ajoutTicket(&t2);
    j.ajoutTicket(&t3);

    int tailleAvant = j.getMainTicket().size();

    j.defausser(pioche);

    // -2 +2 = taille identique
    EXPECT_EQ(j.getMainTicket().size(), tailleAvant);

    EXPECT_EQ(pioche.getDefausse().size(), 2);
}

TEST(JoueurTest, DefausserUnTicket) {
    Joueur j(Couleur_e::Rouge);
    Plateau plateau("map.csv");
    Pioche pioche(Pioche_type_e::Ticket);

    Ville v1("A"), v2("B");

    Ticket t1(&plateau, &v1, &v2, 1);

    j.ajoutTicket(&t1);

    j.defausser(pioche);

    EXPECT_EQ(pioche.getDefausse().size(), 1);
    EXPECT_EQ(j.getMainTicket().size(), 2); // 1 retiré + 2 piochés
}

TEST(JoueurTest, DefausserAucunTicket) {
    Joueur j(Couleur_e::Rouge);
    Pioche pioche(Pioche_type_e::Ticket);

    j.defausser(pioche);

    EXPECT_EQ(pioche.getDefausse().size(), 0);
    EXPECT_EQ(j.getMainTicket().size(), 2);
}

TEST(JoueurTest, DefausserOrdre) {
    Joueur j(Couleur_e::Rouge);
    Plateau plateau("map.csv");
    Pioche pioche(Pioche_type_e::Ticket);

    Ville v1("A"), v2("B"), v3("C"), v4("D"), v5("E"), v6("F");

    Ticket t1(&plateau, &v1, &v2, 1);
    Ticket t2(&plateau, &v3, &v4, 2);
    Ticket t3(&plateau, &v5, &v6, 3);

    j.ajoutTicket(&t1);
    j.ajoutTicket(&t2);
    j.ajoutTicket(&t3);

    j.defausser(pioche);

        auto& defausse = pioche.getDefausse();

    Ticket* d0 = dynamic_cast<Ticket*>(defausse[0]);
    Ticket* d1 = dynamic_cast<Ticket*>(defausse[1]);

    ASSERT_NE(d0, nullptr);
    ASSERT_NE(d1, nullptr);

    EXPECT_TRUE(
        (d0->getId() == 3 && d1->getId() == 2) ||
        (d0->getId() == 2 && d1->getId() == 3)
    );
}

// ===================================================

// ================= Test getCouleur =================
TEST(JoueurTest, GetCouleur) {
    Joueur j(Couleur_e::Rouge);

    EXPECT_EQ(j.getCouleur(), Couleur_e::Rouge);
}

// ===================================================