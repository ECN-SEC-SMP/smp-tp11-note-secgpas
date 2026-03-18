# Version minimale de CMake requise pour configurer ce projet.
# 3.14 est nécessaire pour utiliser FetchContent proprement.
cmake_minimum_required(VERSION 3.14)

# Nom du projet (affiché dans les outils et utilisé en interne par CMake).
project(tp11-note)

# Définition du standard C++ utilisé pour la compilation.
# Ici on impose C++17 (remplacer par 11 si nécessaire).
set(CMAKE_CXX_STANDARD 17)

# Oblige le compilateur à respecter strictement ce standard.
# Si le compilateur ne le supporte pas, la configuration échoue.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Permet d'utiliser le module FetchContent,
# qui sert à télécharger automatiquement une dépendance externe.
include(FetchContent)

# Déclaration de la dépendance GoogleTest.
# CMake va télécharger le dépôt Git à la configuration du projet.
FetchContent_Declare(
  googletest
  # Adresse du dépôt officiel
  GIT_REPOSITORY https://github.com/google/googletest.git

  # Version précise utilisée (bonne pratique pour éviter les surprises)
  GIT_TAG v1.17.0

  # Assure que les fichiers extraits ont un timestamp cohérent,
  # ce qui évite certains problèmes de recompilation.
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Ne pas construire GoogleMock si on n'en a pas besoin.
# Cela accélère la compilation et simplifie le projet.
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# Cette option est utile principalement sous Windows (MSVC).
# Elle force GoogleTest à utiliser la même bibliothèque runtime
# que le projet principal, afin d'éviter des erreurs de linkage.
# Sur macOS et Linux, cette ligne est généralement sans effet.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Télécharge et configure effectivement GoogleTest
# comme s'il faisait partie du projet.
FetchContent_MakeAvailable(googletest)

# Active le système de tests CTest dans CMake.
# Sans cette ligne, la commande "ctest" ne fonctionnerait pas.
enable_testing()

include_directories(include)

# Déclaration de l'exécutable de tests.
# Il sera construit à partir des fichiers suivants.
add_executable(mytest.out
    src/factorielle.cpp
    tests/mytest.cpp
)

add_executable(calculatorTest.out
        tests/calculatorTest.cpp
        src/Calculator.cpp
)

# Ajout d'options de compilation spécifiques à cette cible :
# -Wall   : active la plupart des warnings
# -Wextra : warnings supplémentaires
# -pthread: nécessaire pour GoogleTest
# -g      : ajoute les symboles de debug
target_compile_options(mytest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(calculatorTest.out PRIVATE -Wall -Wextra -pthread -g)

# Liaison de l'exécutable avec GoogleTest.
# GTest::gtest_main fournit :
#   - la bibliothèque GoogleTest
#   - un main() déjà implémenté qui lance les tests
target_link_libraries(mytest.out
    GTest::gtest_main
)

target_link_libraries(calculatorTest.out
        GTest::gtest_main
)

# Permet d'utiliser les fonctions spécifiques à GoogleTest dans CMake.
include(GoogleTest)

# Cette commande exécute automatiquement l'exécutable de test
# pour détecter tous les tests GoogleTest qu’il contient.
# Chaque test est enregistré individuellement dans CTest.
# Cela permet d'utiliser la commande "ctest" pour les exécuter.
gtest_discover_tests(mytest.out)