#include "Carte.h"
#include "types.h"
#include "Joueur.h"
#include "Pioche.h"
#include "Plateau.h"
#include "config.h"
#include <gtest/gtest.h>

//TEST(JoueurTest, testDesMethodes) {
//     Joueur j1 = Joueur(Couleur_e::Bleu);
//     EXPECT_EQ(20, j1.getMainWagon());
//     // Vérifie que toutes les couleurs sont initialisées à 0
//     for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
//         EXPECT_EQ(0, it->second);
//     }

//     Pioche pw(Pioche_type_e::CarteW);
//     j1.piocher(3, pw);
//     int compt = 0;
//     for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
//         compt = compt + it->second;
//     }
//     EXPECT_EQ(2, compt);

//     Pioche pt(Pioche_type_e::Ticket);
//     j1.piocher(2, pt);
//     EXPECT_EQ(2, j1.getMainTicket().size());

//     EXPECT_NO_THROW(j1.afficherMain());

//     // On récupère la première carte possédée
//     Couleur_e couleurTrouvee;
//     for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
//         if (it->second > 0){
//             couleurTrouvee = it->first;
//             break;
//         }
//     }
//     int nbAvant = j1.getMainCarte()[couleurTrouvee];
//     CTrain carteADefausser(couleurTrouvee);
//     j1.defausserCarte(&carteADefausser);
//     EXPECT_EQ(nbAvant - 1, j1.getMainCarte()[couleurTrouvee]);

//     int nbTicketsAvant = j1.getMainTicket().size();
//     Ticket* ticketADefausser = j1.getMainTicket().back();
//     j1.defausserCarte(ticketADefausser);
//     EXPECT_EQ(nbTicketsAvant - 1, j1.getMainTicket().size());

//     // On s'assure d'avoir 2 tickets en main
//     j1.piocher(2, pt);
//     int nbTicketsAvantDefausse = j1.getMainTicket().size();
//     j1.defausser(pt);
//     // On a retiré 2 tickets et repioché 2 -> taille identique
//     EXPECT_EQ(nbTicketsAvantDefausse, j1.getMainTicket().size());

//     Plateau plateau;
//     int wagonsAvant = j1.getMainWagon();
//     // On pose sur une voie existante du plateau (à adapter selon vos villes)
//     j1.poserWagon(Ville_e::Paris, Ville_e::Lyon, Couleur_e::Rouge, plateau);
//     // Le nombre de wagons a diminué
//     EXPECT_LT(j1.getMainWagon(), wagonsAvant);
//     // La voie n'est plus disponible
//     bool voiePrise = false;
//     for (int i = 0; i < plateau.getVoieFerree().size(); i++){
//         VoieFerree& v = plateau.getVoieFerree()[i];
//         if (((v.getVille1() == Ville_e::Paris && v.getVille2() == Ville_e::Lyon) ||
//              (v.getVille1() == Ville_e::Lyon  && v.getVille2() == Ville_e::Paris)) &&
//              v.getCouleur() == Couleur_e::Rouge){
//             voiePrise = !v.estDispo();
//         }
//     }
//     EXPECT_TRUE(voiePrise);
//}

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



TEST(JoueurTest, testAfficheCarte) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pw(Pioche_type_e::CarteW);
    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(3, pw);
    j1.piocher(2, pt);
    EXPECT_NO_THROW(j1.afficherMain());
}

TEST(JoueurTest, testAfficheTicket) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(2, pt);
    EXPECT_EQ(2, j1.getMainTicket().size());
}

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

// TEST(JoueurTest, testNbTicketReussisAucunValide) {
//     Joueur j(Couleur_e::Bleu);

//     Ticket* t1 = new Ticket(...); // paramètres qui ne peuvent pas être réalisés
//     Ticket* t2 = new Ticket(...);

//     j.getMainTicket().push_back(t1);
//     j.getMainTicket().push_back(t2);

//     EXPECT_EQ(0, j.getNbTicketReussis());
// }




