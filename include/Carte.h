//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_CARTE_H
#define TP11_NOTE_CARTE_H

#include "types.h"
#include "Ville.h"

class Plateau;

class Carte {
    public:
    virtual bool estRealise() const = 0;
    virtual Carte_type_e getType()    const = 0;
};

class CTrain : public Carte {
    Couleur_e couleur_;

public:
    CTrain(Couleur_e couleur) {
        couleur_ = couleur;
    }

    Couleur_e getCouleur() const {
        return couleur_;
    }

    Carte_type_e getType() const override {
        return Carte_type_e::Train;
    }

    bool estRealise() const {
        return false;
    };
};

class Ticket : public Carte {
public:
    Ville *villeA_;
    Ville *villeB_;
    int   id_;
    Plateau *plateau_;

    Ticket(Plateau *plateau, Ville *villeA, Ville *villeB, const int id) {
        if (plateau == nullptr) {
            cerr << "Erreur : le plateau ne peut pas être nul." << endl;
            exit(EXIT_FAILURE);
        }

        if (villeA == nullptr) {
            cerr << "Erreur : la *villeA ne peut pas être nul." << endl;
            exit(EXIT_FAILURE);
        }

        if (villeB == nullptr) {
            cerr << "Erreur : la *villeB ne peut pas être nul." << endl;
            exit(EXIT_FAILURE);
        }

        plateau_ = plateau;
        villeA_ = villeA;
        villeB_ = villeB;
        id_      = id;
    }

    Ticket(Plateau *plateau, const string & nomVilleA, const string & nomVilleB, const int id);

    bool estRealise() const {
        return false;
    };

    Carte_type_e getType() const override {
        return Carte_type_e::Ticket;
    }

    Ville* getVilleA() const {
        return villeA_;
    }

    Ville* getVilleB() const {
        return villeB_;
    }

    int getId() const {
        return id_;
    }

    void setVilleA(Ville *villeA) {
        villeA_ = villeA;
    }

    void setVilleB(Ville *villeB) {
        villeB_ = villeB;
    }

    void setId(const int id) {
        id_ = id;
    }
};
#endif //TP11_NOTE_CARTE_H