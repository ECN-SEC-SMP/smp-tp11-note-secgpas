# TP11 - Projet C++ (Jeu de train + architecture de code)

## 🧩 Contexte du projet
Ce projet est un travail pratique (TP11) pour apprendre la conception orientée objet en C++.
Il comprend :
- un moteur de jeu simplifié inspiré de "Ticket to Ride",
- des entités métier (`Plateau`, `Ville`, `VoieFerree`, `Pioche`, `Joueur`),
- des fichiers de données (`map.csv`, `ticket.csv`),
- et une suite de tests unitaires (Google Test).

## 🎯 Objectifs pédagogiques
- modéliser un domaine avec classes et relations,
- lire/charger un plateau depuis un fichier CSV,
- implémenter une boucle de jeu et les règles du tour,
- écrire des tests unitaires pour valider le comportement des composants.

## 🧩 Description du jeu
Le jeu implémente une version simplifiée de "Ticket to Ride" :
- Plateaux de villes et voies ferroviaires via `map.csv`
- Pioche de cartes wagon et de tickets
- Joueurs avec couleur, wagons, tickets réussis
- Tour par tour avec 3 actions : piocher, poser un wagon, ou passer (défausser)

## 📁 Structure du projet
- `include/` : en-têtes (`.h` / `.hpp`)
- `src/` : implémentations (`.cpp`)
- `tests/` : tests unitaires (Google Test)
- `CMakeLists.txt` : configuration CMake
- `map.csv`, `ticket.csv` : données de plateau et tickets

## ▶️ Fonctionnement général
1. `main` crée un objet `Jeu` et lance `partie()`.
2. Le constructeur `Jeu(nbJoueur)` :
   - charge `Plateau` depuis `map.csv`
   - initialise deux pioches (`tickets` et `train`)
   - demande la couleur de chaque joueur
3. `Jeu::partie()` tourne tant que `estFinie()` est faux.
   - chaque tour, chaque joueur choisit 0=piocher, 1=poser un wagon, 2=passer.
4. `Jeu::estFinie()` retourne vrai si un joueur :
   - finit ses wagons, ou
   - a 6 tickets réussis.

## 🛠️ Comment compiler et exécuter
Pré-requis : CMake, compilateur C++17 (g++, clang++, MSVC). 

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

Puis exécuter le binaire `main` :

- Linux/Mac : `./main`
- Windows : `main.exe`

## 🧪 Lancer les tests unitaires
Depuis `build` :

```bash
ctest --output-on-failure
```

Ou exécuter chaque cible :
- `mytest.out`
- `VilleTest.out`
- `VoieFerreeTest.out`
- `PiocheTest.out`
- `JoueurTest.out`
- `CarteTest.out`
- `PlateauTest.out`

