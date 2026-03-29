//
// Created by David PROSPÉRIN on 25/03/2026.
//

#ifndef TP11_NOTE_PLATEAU_H
#define TP11_NOTE_PLATEAU_H

#include "Ville.h"
#include "VoieFerree.h"

class Plateau {
  Ville              *graphe_ville_;
  vector<Ville>      villes_;
  vector<VoieFerree> voie_ferrees_;

public:

  /**
   * Constructeur du plateau de jeu.
   * Il charge les villes et les voies ferrées à partir d'un fichier csv.
   * TODO: Construire un graphe à partir des villes et des voies ferrées pour faciliter les recherches de chemins entre les villes.
   * @param nomFichierMap Le chemin vers le fichier csv contenant les informations sur les villes et les voies ferrées
   */
  Plateau(const string & nomFichierMap);

  void afficherVille();

  /**
   *
   * @param nomVille Le nom de la ville à chercher
   * @return Un pointeur sur la ville trouvée ou nullptr si la ville n'existe pas
   */
  Ville* getVille(const string & nomVille);

  vector<Ville>& getVilles() {
      return villes_;
  }

  Ville& getVille(int i) {
      return villes_[i];
  }

  vector<VoieFerree>& getVoieFerrees() {
      return voie_ferrees_;
  }

  void affichePlateau() const;
};

#endif //TP11_NOTE_PLATEAU_H