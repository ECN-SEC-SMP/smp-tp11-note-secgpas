#include "Carte.h"
#include "types.h"
#include "Joueur.h"
#include "Pioche.h"
#include "Plateau.h"
#include <gtest/gtest.h>

TEST(JoueurTest, testDesMethodes) {
    Joueur j1 = Joueur(Couleur_e::Bleu);
    EXPECT_EQ(20, j1.getMainWagon());
    // Vérifie que toutes les couleurs sont initialisées à 0
    for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
        EXPECT_EQ(0, it->second);
    }

    Pioche pw(Pioche_type_e::CarteW);
    j1.piocher(3, pw);
    int compt = 0;
    for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
        compt = compt + it->second;
    }
    EXPECT_EQ(2, compt);

    Pioche pt(Pioche_type_e::Ticket);
    j1.piocher(2, pt);
    EXPECT_EQ(2, j1.getMainTicket().size());

    EXPECT_NO_THROW(j1.afficherMain());

    // On récupère la première carte possédée
    Couleur_e couleurTrouvee;
    for (map<Couleur_e, int>::iterator it = j1.getMainCarte().begin(); it != j1.getMainCarte().end(); ++it){
        if (it->second > 0){
            couleurTrouvee = it->first;
            break;
        }
    }
    int nbAvant = j1.getMainCarte()[couleurTrouvee];
    CTrain carteADefausser(couleurTrouvee);
    j1.defausserCarte(&carteADefausser);
    EXPECT_EQ(nbAvant - 1, j1.getMainCarte()[couleurTrouvee]);

    int nbTicketsAvant = j1.getMainTicket().size();
    Ticket* ticketADefausser = j1.getMainTicket().back();
    j1.defausserCarte(ticketADefausser);
    EXPECT_EQ(nbTicketsAvant - 1, j1.getMainTicket().size());

    // On s'assure d'avoir 2 tickets en main
    j1.piocher(2, pt);
    int nbTicketsAvantDefausse = j1.getMainTicket().size();
    j1.defausser(pt);
    // On a retiré 2 tickets et repioché 2 -> taille identique
    EXPECT_EQ(nbTicketsAvantDefausse, j1.getMainTicket().size());

    Plateau plateau;
    int wagonsAvant = j1.getMainWagon();
    // On pose sur une voie existante du plateau (à adapter selon vos villes)
    j1.poserWagon(Ville_e::Paris, Ville_e::Lyon, Couleur_e::Rouge, plateau);
    // Le nombre de wagons a diminué
    EXPECT_LT(j1.getMainWagon(), wagonsAvant);
    // La voie n'est plus disponible
    bool voiePrise = false;
    for (int i = 0; i < plateau.getVoieFerree().size(); i++){
        VoieFerree& v = plateau.getVoieFerree()[i];
        if (((v.getVille1() == Ville_e::Paris && v.getVille2() == Ville_e::Lyon) ||
             (v.getVille1() == Ville_e::Lyon  && v.getVille2() == Ville_e::Paris)) &&
             v.getCouleur() == Couleur_e::Rouge){
            voiePrise = !v.estDispo();
        }
    }
    EXPECT_TRUE(voiePrise);
}