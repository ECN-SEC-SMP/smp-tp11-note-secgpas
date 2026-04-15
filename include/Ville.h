#ifndef SMP_TP8_DAVID_RIANA_VILLE_H
#define SMP_TP8_DAVID_RIANA_VILLE_H

#include<iostream>
#include<vector>

using namespace std;

/**
 * @brief Classe représentant une ville dans le jeu, servant de sommet dans le graphe du plateau.
 */
class Ville{
    private:
        /**
         * @brief Nom de la ville.
         */
        string ville_;
        /**
         * @brief Vecteur des villes adjacentes (voisins dans le graphe).
         */
        vector<Ville*> villesAdjacentes; //vector d'adjacence du sommet
    public :
        /**
         * @brief Constructeur de Ville utilisant un indice.
         * @param i Indice de la ville dans le vecteur global des villes.
         */
        Ville(int i); //indice de la ville qu'on veut dans vectVille
        /**
         * @brief Constructeur de Ville avec nom direct.
         * @param NomVille Nom de la ville.
         */
        Ville(string NomVille): ville_(NomVille) {};
        /**
         * @brief Retourne le nom de la ville.
         * @return Le nom de la ville.
         */
        string getNomVille() const;
        /**
         * @brief Affiche les villes adjacentes.
         */
        void afficheAdjacent();
        /**
         * @brief Vérifie si une ville est adjacente via indice.
         * @param ville Indice de la ville à tester.
         * @return true si adjacente, false sinon.
         */
        bool estAdjacent(Ville *ville) const;

      /**
        * @brief Méthode qui teste si une ville est adjacente à une autre.
        * @param nomVille Nom de la ville à tester
        * @return Booléen à true si la ville i est adjacente à la ville courante et false sinon
        */
        bool estAdjacent(const string &nomVille);

        /**
         * @brief Retourne le vecteur des villes adjacentes.
         * @return Référence vers le vecteur des villes adjacentes.
         */
        vector<Ville *> &getAdjacent();
        /**
         * @brief Ajoute une ville adjacente.
         * @param v Pointeur vers la ville à ajouter.
         */
        void ajoutVilleAdjacente(Ville* v);
};


#endif