cmake_minimum_required(VERSION 3.14)
project(tp11-note)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include_directories(include)

add_executable(mytest.out
    src/factorielle.cpp
    tests/mytest.cpp
)

add_executable(calculatorTest.out
    tests/calculatorTest.cpp
    src/Calculator.cpp
)

add_executable(VilleTest.out
    src/fonctionAnnexe.cpp
    src/Ville.cpp
    tests/VilleTest.cpp
)

add_executable(VoieFerreeTest.out
    src/fonctionAnnexe.cpp
    src/Ville.cpp
    src/VoieFerree.cpp
    tests/VoieFerreeTest.cpp
)

add_executable(PiocheTest.out
    src/Pioche.cpp
    src/Plateau.cpp
    src/VoieFerree.cpp
    src/fonctionAnnexe.cpp
    src/Ville.cpp
    tests/PiocheTest.cpp
    tests/PlateauTest.cpp
)

add_executable(JoueurTest.out
    src/Joueur.cpp
    src/Pioche.cpp
    src/Plateau.cpp
    src/VoieFerree.cpp
    src/fonctionAnnexe.cpp
    src/Ville.cpp
    src/Ticket.cpp
    tests/JoueurTest.cpp
)

add_executable(CarteTest.out
    src/Ticket.cpp
    tests/CarteTest.cpp
)

add_executable(PlateauTest.out
    src/Plateau.cpp
    src/VoieFerree.cpp
    src/fonctionAnnexe.cpp
    src/Ville.cpp
    tests/PlateauTest.cpp
)

target_compile_options(mytest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(calculatorTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(VilleTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(VoieFerreeTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(PiocheTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(JoueurTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(CarteTest.out PRIVATE -Wall -Wextra -pthread -g)
target_compile_options(PlateauTest.out PRIVATE -Wall -Wextra -pthread -g)

target_link_libraries(mytest.out GTest::gtest_main)
target_link_libraries(calculatorTest.out GTest::gtest_main)
target_link_libraries(VilleTest.out GTest::gtest_main)
target_link_libraries(VoieFerreeTest.out GTest::gtest_main)
target_link_libraries(PiocheTest.out GTest::gtest_main)
target_link_libraries(JoueurTest.out GTest::gtest_main)
target_link_libraries(CarteTest.out GTest::gtest_main)
target_link_libraries(PlateauTest.out GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(mytest.out)
gtest_discover_tests(VilleTest.out)
gtest_discover_tests(VoieFerreeTest.out)
gtest_discover_tests(PiocheTest.out)
gtest_discover_tests(JoueurTest.out)
gtest_discover_tests(CarteTest.out)
gtest_discover_tests(PlateauTest.out)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(main ${SOURCES} main.cpp)