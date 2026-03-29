//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_CARTE_H
#define TP11_NOTE_CARTE_H

#include "types.h"

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

    bool estRealise() const override {};
};

class Ticket : public Carte {
public:
    bool estRealise() const override;

    Carte_type_e getType() const override {
        return Carte_type_e::Ticket;
    }
};
#endif //TP11_NOTE_CARTE_H