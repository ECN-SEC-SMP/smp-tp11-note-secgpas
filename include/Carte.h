//
// Created by David PROSPÉRIN on 20/03/2026.
//

#ifndef TP11_NOTE_CARTE_H
#define TP11_NOTE_CARTE_H

#include "types.h"
#include "Ville.h"

class Plateau;

/**
 * @brief Classe abstraite représentant une carte dans le jeu.
 */
class Carte {
    public:
    /**
     * @brief Vérifie si la carte est réalisée.
     * @return true si réalisée, false sinon.
     */
    virtual bool estRealise() const = 0;
    /**
     * @brief Retourne le type de la carte.
     * @return Le type de la carte.
     */
    virtual Carte_type_e getType()    const = 0;
};

/**
 * @brief Classe représentant une carte train.
 */
class CTrain : public Carte {
    /**
     * @brief Couleur de la carte train.
     */
    Couleur_e couleur_;

public:
    /**
     * @brief Constructeur de CTrain.
     * @param couleur La couleur de la carte train.
     */
    CTrain(Couleur_e couleur) {
        couleur_ = couleur;
    }

    /**
     * @brief Retourne la couleur de la carte train.
     * @return La couleur.
     */
    Couleur_e getCouleur() const {
        return couleur_;
    }

    /**
     * @brief Retourne le type de la carte.
     * @return Le type de la carte.
     */
    Carte_type_e getType() const override {
        return Carte_type_e::Train;
    }

    /**
     * @brief Vérifie si la carte train est réalisée.
     * @return true si réalisée, false sinon.
     */
    bool estRealise() const {
        // TODO: implémenter CTrain::estRealise
        return false;
    };
};

/**
 * @brief Classe représentant un ticket.
 */
class Ticket : public Carte {
public:
    /**
     * @brief Pointeur vers la ville de départ.
     */
    Ville *villeA_;
    /**
     * @brief Pointeur vers la ville d'arrivée.
     */
    Ville *villeB_;
    /**
     * @brief Identifiant unique du ticket.
     */
    int   id_;
    /**
     * @brief Pointeur vers le plateau de jeu.
     */
    Plateau *plateau_;

    /**
     * @brief Constructeur de Ticket.
     * @param plateau Pointeur vers le plateau.
     * @param villeA Pointeur vers la ville A.
     * @param villeB Pointeur vers la ville B.
     * @param id Identifiant du ticket.
     */
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

    /**
     * @brief Constructeur de Ticket avec noms de villes.
     * @param plateau Pointeur vers le plateau.
     * @param nomVilleA Nom de la ville A.
     * @param nomVilleB Nom de la ville B.
     * @param id Identifiant du ticket.
     */
    Ticket(Plateau *plateau, const string & nomVilleA, const string & nomVilleB, const int id);

    /**
     * @brief Charge les tickets depuis un fichier CSV.
     * @param plateau Pointeur vers le plateau.
     * @param nomFichierCSVTicket Nom du fichier CSV.
     * @return Vecteur de tickets chargés.
     */
    static vector<Ticket> loadFromCSVFile(Plateau *plateau, const string & nomFichierCSVTicket);

    /**
     * @brief Vérifie si le ticket est réalisé.
     * @return true si réalisé, false sinon.
     */
    bool estRealise() const {
        return false;
    };

    /**
     * @brief Retourne le type de la carte.
     * @return Le type de la carte.
     */
    Carte_type_e getType() const override {
        return Carte_type_e::Ticket;
    }

    /**
     * @brief Retourne la ville de départ.
     * @return Pointeur vers la ville A.
     */
    Ville* getVilleA() const {
        return villeA_;
    }

    /**
     * @brief Retourne la ville d'arrivée.
     * @return Pointeur vers la ville B.
     */
    Ville* getVilleB() const {
        return villeB_;
    }

    /**
     * @brief Retourne l'identifiant du ticket.
     * @return L'identifiant.
     */
    int getId() const {
        return id_;
    }

    /**
     * @brief Définit la ville de départ.
     * @param villeA Pointeur vers la nouvelle ville A.
     */
    void setVilleA(Ville *villeA) {
        villeA_ = villeA;
    }

    /**
     * @brief Définit la ville d'arrivée.
     * @param villeB Pointeur vers la nouvelle ville B.
     */
    void setVilleB(Ville *villeB) {
        villeB_ = villeB;
    }

    /**
     * @brief Définit l'identifiant du ticket.
     * @param id Le nouvel identifiant.
     */
    void setId(const int id) {
        id_ = id;
    }
};
#endif //TP11_NOTE_CARTE_H