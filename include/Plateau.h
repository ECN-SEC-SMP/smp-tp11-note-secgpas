//
// Created by David PROSPÉRIN on 25/03/2026.
//

#ifndef TP11_NOTE_PLATEAU_H
#define TP11_NOTE_PLATEAU_H

#include "Ville.h"
#include "VoieFerree.h"

/**
 * @brief Classe représentant le plateau de jeu contenant les villes et les voies ferrées.
 */
class Plateau {
  /**
   * @brief Pointeur vers le sommet racine du graphe de villes.
   */
  Ville              *graphe_ville_;
  /**
   * @brief Vecteur contenant toutes les villes du plateau.
   */
  vector<Ville>      villes_;
  /**
   * @brief Vecteur contenant toutes les voies ferrées du plateau.
   */
  vector<VoieFerree> voie_ferrees_;

public:

  /**
   * @brief Constructeur du plateau de jeu.
   * Il charge les villes et les voies ferrées à partir d'un fichier csv.
   * @param nomFichierMap Le chemin vers le fichier csv contenant les informations sur les villes et les voies ferrées
   */
  Plateau(const string & nomFichierMap);

  /**
   * @brief Recherche une ville par son nom.
   * @param nomVille Le nom de la ville à chercher
   * @return Un pointeur sur la ville trouvée ou nullptr si la ville n'existe pas
   */
  Ville* getVille(const string & nomVille);

  /**
   * @brief Retourne le vecteur de toutes les villes.
   * @return Référence vers le vecteur des villes.
   */
  vector<Ville>& getVilles() {
      return villes_;
  }

  /**
   * @brief Retourne une ville par son indice.
   * @param i Indice de la ville dans le vecteur.
   * @return Référence vers la ville à l'indice i.
   */
  Ville& getVille(int i) {
      return villes_[i];
  }

  /**
   * @brief Retourne le vecteur de toutes les voies ferrées.
   * @return Référence vers le vecteur des voies ferrées.
   */
  vector<VoieFerree>& getVoieFerrees() {
      return voie_ferrees_;
  }

  /**
   * @brief Permet de trouver les voies ferrées entre deux villes.
   * @param villeA la ville de départ
   * @param villeB la ville d'arrivée
   * @return un vecteur de voies ferrées entre les deux villes
   */
  vector<VoieFerree> getVoieFerrees(const Ville & villeA, const Ville & villeB) const;

  /**
   * @brief Affiche le plateau de jeu en format matrice d'adjacence.
   * Affiche le plateau de jeu en affichant les villes et les voies ferrées dans le flux standard de sortie.
   * Un joueur (max 4) possède une couleur parmi : bleu, jaune, vert et rouge.
   * La sortie prend la forme de matrice d'adjacence où chaque case représente une ou plusieurs voies ferrées entre deux villes.
   * Lorsqu'un joueur possède une voie ferrée, le texte de cette voie prend la couleur du joueur.
   *
   * Avec les villes suivantes : Seattle, Calgary et Helena
   * et les voies ferrées suivantes :
   * Seattle-Calgary (bleu)  poids : 2
   * Seattle-Calgary (rouge) poids : 4
   *
   * Seattle-Helena (rouge)  poids : 1
   * Seattle-Helena (vert)   poids : 2
   *
   * Calgary-Helena (vert)   poids : 3
   *
   * Voici un exemple de sortie possible :
   *
   * ----------=== Plateau de jeu ===----------
   *          Seattle    Calgary     Helena       (Ville A)
   *         ------------------------------------
   * Seattle | X         | 2, 4     | 1, 2      |
   * Calgary | 2, 4      | X        | 3         |
   * Helena  | 1, 2      | X        | X         |
   *         ------------------------------------
   * (Ville B)
   */
  void affichePlateau() const;
};

#endif //TP11_NOTE_PLATEAU_H